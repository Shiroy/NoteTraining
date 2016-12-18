#include "notefinder.h"
#include <QButtonGroup>
#include <QHBoxLayout>
#include <QPushButton>
#include "utility.h"
#include <algorithm>
#include <QSound>
#include <QDebug>

NoteFinder::NoteFinder(std::vector<int> allowedOctaves, bool alterationAllowed, QWidget *parent) :
    QWidget(parent), m_allowedOctaves(allowedOctaves), m_currentNoteSound(nullptr)
{
    //Définition des notes autorisees
    if(alterationAllowed) {
        m_allowedNotes = {0,1,2,3,4,5,6,7,8,9,10,11};
    } else {
        m_allowedNotes = {0, 2, 4, 5, 7, 9, 11};
    }

    if(!std::all_of(m_allowedOctaves.begin(), m_allowedOctaves.end(), [](int octave) {
        return octave >= 2 && octave <= 8;
    })) {
        throw "Les octaves doivent etre comprises en 2 et 8";
    }

    QVBoxLayout *lay = new QVBoxLayout(this);
    //Creation du bouton play
    QPushButton *playNote = new QPushButton("Jouer la note", this);
    lay->addWidget(playNote);

    connect(playNote, &QPushButton::clicked, this, [this](){
        playFile(noteOctave2Filename(m_octave, m_note));
    });

    QPushButton* noteRef = new QPushButton("Jouer la note de référence (Do, C3)", this);
    lay->addWidget(noteRef);

    connect(noteRef, &QPushButton::clicked, [this](){
       playFile(noteOctave2Filename(5, 0));
    });

    //Creation du groupes de boutons de réponse
    m_answersButton = new QButtonGroup(this);
    QHBoxLayout *answerLayout = new QHBoxLayout();
    for(int note : m_allowedNotes) {
        QString noteLabal = int2Note(note);
        QPushButton *btn = new QPushButton(noteLabal, this);
        m_answersButton->addButton(btn, note);
        answerLayout->addWidget(btn);
    }

    connect(m_answersButton, SIGNAL(buttonClicked(int)), this, SLOT(checkGuess(int)));

    lay->addLayout(answerLayout);
    setLayout(lay);

    randomNote();
}

NoteFinder::~NoteFinder()
{
}

void NoteFinder::checkGuess(int guess) {
    if(guess == m_note) {
        QSound::play("right.wav");
        randomNote();
        emit guessedRight();
    } else {
        QSound::play("wrong.wav");
        emit guessedWrong();
    }
}

void NoteFinder::randomNote()
{
    std::random_shuffle(m_allowedNotes.begin(), m_allowedNotes.end());
    std::random_shuffle(m_allowedOctaves.begin(), m_allowedOctaves.end());

    m_octave = *m_allowedOctaves.begin();
    m_note = *m_allowedNotes.begin();

}

void NoteFinder::playFile(const QString &file2Play) {
    qDebug() << "Playing " << file2Play;

    if(m_currentNoteSound){
        m_currentNoteSound->stop();
        m_currentNoteSound->deleteLater();
    }
    m_currentNoteSound = new QSound(file2Play, this);
    m_currentNoteSound->play();
}
