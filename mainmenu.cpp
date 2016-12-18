#include "mainmenu.h"
#include "ui_mainmenu.h"
#include "notefinder.h"
#include "mainwindow.h"

MainMenu::MainMenu(QWidget* parent) : QWidget(parent), ui(new Ui::MainMenu) {    
    ui->setupUi(this);
    
    //Connect button to start the game
    connect(ui->level1, &QPushButton::clicked, [this](){
        startGame(false, {5});
    });
    connect(ui->level2, &QPushButton::clicked, [this]() {
        startGame(true, {5});
    });
    connect(ui->level3, &QPushButton::clicked, [this]() {
        startGame(false, {2, 3, 4, 5, 6, 7, 8});
    });
    connect(ui->level4, &QPushButton::clicked, [this]() {
        startGame(true, {2, 3, 4, 5, 6, 7, 8});
    });
    connect(ui->level4, &QPushButton::clicked, [this]() {
        startGame(true, {2, 3, 4, 5, 6, 7, 8});
    });
}

void MainMenu::startGame(bool withAlteration, const std::vector<int>& octaveAllowed) {
    NoteFinder *finder = new NoteFinder(octaveAllowed, withAlteration, qobject_cast<MainWindow*>(parent())); 
    MainWindow* mainWin = qobject_cast<MainWindow*>(parent());
    mainWin->setCentralWidget(finder);
}
