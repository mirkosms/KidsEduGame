#include "GameGUI.h"

GameGUI::GameGUI(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GameGUIClass())
{
    ui->setupUi(this);
}

GameGUI::~GameGUI()
{
    delete ui;
}
