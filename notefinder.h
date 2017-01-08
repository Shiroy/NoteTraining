#ifndef NOTEFINDER_H
#define NOTEFINDER_H

#include <QWidget>
#include <QSound>

class QButtonGroup;

class NoteFinder : public QWidget
{
    Q_OBJECT

public:
    explicit NoteFinder(std::vector<int> allowedOctaves, bool alterationAllowed, QWidget *parent = 0, bool withReference = true);
    ~NoteFinder();

    void randomNote();

signals:
    void guessedRight();
    void guessedWrong();

private slots:
    void checkGuess(int guess);

private:
    void playFile(const QString& filename);

    std::vector<int> m_allowedNotes;
    std::vector<int> m_allowedOctaves;
    QButtonGroup *m_answersButton;

    QSound *m_currentNoteSound;

    int m_octave;
    int m_note;

};

#endif // NOTEFINDER_H
