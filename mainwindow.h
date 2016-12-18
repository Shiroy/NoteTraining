#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void guessedRight();
    void guessedWrong();
    void updateScoreDisplay();

private:
    Ui::MainWindow *ui;
    int m_nbGuessedRight;
    int m_nbGuessedWrong;
};

#endif // MAINWINDOW_H
