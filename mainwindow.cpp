#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mainmenu.h"
#include <QAction>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_nbGuessedRight(0),
    m_nbGuessedWrong(0)
{
    ui->setupUi(this);

    updateScoreDisplay();

    connect(ui->newGame, &QAction::triggered, this, &MainWindow::newGame);
    newGame();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::guessedRight() {
    m_nbGuessedRight++;
    updateScoreDisplay();
}

void MainWindow::guessedWrong() {
    m_nbGuessedWrong++;
    updateScoreDisplay();
}

void MainWindow::updateScoreDisplay() {
    QString newScore = "Réussis : " + QString::number(m_nbGuessedRight) + " | Faux : " + QString::number(m_nbGuessedWrong);
    if(m_nbGuessedRight + m_nbGuessedWrong > 0) {
        float successRate = float(m_nbGuessedRight) / float(m_nbGuessedRight + m_nbGuessedWrong) * 100;
        newScore += " | Taux de réussite : " + QString::number(successRate, 'g', 2);
    }

    ui->statusBar->showMessage(newScore);
}

void MainWindow::newGame() {
    MainMenu *menu = new MainMenu(this);
    setCentralWidget(menu);
    m_nbGuessedRight = 0;
    m_nbGuessedWrong = 0;
    updateScoreDisplay();
}

