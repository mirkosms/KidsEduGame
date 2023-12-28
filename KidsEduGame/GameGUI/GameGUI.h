#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_GameGUI.h"
#include "RomanConverter.h"

QT_BEGIN_NAMESPACE
namespace Ui { class GameGUIClass; };
QT_END_NAMESPACE

class GameGUI : public QMainWindow
{
    Q_OBJECT

public:
    GameGUI(QWidget *parent = nullptr);
    ~GameGUI();

private:
    Ui::GameGUIClass *ui;
    RomanConverter converter;

private slots:
    void on_convert2DecimalClicked();
    void on_convert2RomanClicked();

};
