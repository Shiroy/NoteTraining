#ifndef MAINMENU_H
#define MAINMENU_H

#include <QWidget>
#include <vector>

namespace Ui {
    class MainMenu;
}

class MainMenu : public QWidget
{
public:
    MainMenu(QWidget* parent=0);

private:
    void startGame(bool withAlteration, const std::vector<int>& octaveAllowed);

private:
    Ui::MainMenu* ui;
};

#endif
