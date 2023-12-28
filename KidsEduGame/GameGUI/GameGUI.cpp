#include "GameGUI.h"
#include "Dec2Roman.h"
#include "RomanConverter.h"

GameGUI::GameGUI(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GameGUIClass())
{
    ui->setupUi(this);
    // Pod��czone sygna�y przycisk�w do slot�w
    connect(ui->pushButtonConvert2Decimal, SIGNAL(clicked()), this, SLOT(on_convert2DecimalClicked()));
    connect(ui->pushButtonConvert2Roman, SIGNAL(clicked()), this, SLOT(on_convert2RomanClicked()));
}

// Sloty
void GameGUI::on_convert2DecimalClicked() {
    QString roman = ui->lineEditRoman->text();
    int decimal = converter.Roman2Dec(roman.toUpper().toStdString());
    ui->labelDecimalResult->setText(decimal != -1 ? QString::number(decimal) : "B��d");
}

void GameGUI::on_convert2RomanClicked() {
    bool ok;
    int decimal = ui->lineEditDecimal->text().toInt(&ok);
    if (ok) {
        QString roman = QString::fromStdString(ConvertDecimal_2_Roman(decimal));
        ui->labelRomanResult->setText(!roman.isEmpty() ? roman : "B��d");
    }
    else {
        ui->labelRomanResult->setText("B��d");
    }
}

GameGUI::~GameGUI()
{
    delete ui;
}
