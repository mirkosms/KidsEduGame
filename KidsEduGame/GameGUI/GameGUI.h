#include <QtWidgets/QMainWindow>
#include "ui_GameGUI.h"
#include "RomanConverter.h"
#include "Dec2Roman.h"
#include "Quiz.h"
#include "Menu.h"
#include "Facts.h"
#include <QTimer>
#include <QSerialPort> // Dołączenie QSerialPort

QT_BEGIN_NAMESPACE
namespace Ui { class GameGUIClass; };
QT_END_NAMESPACE

class GameGUI : public QMainWindow
{
    Q_OBJECT

public:
    GameGUI(QWidget* parent = nullptr);
    ~GameGUI();

private:
    Ui::GameGUIClass* ui;
    RomanConverter converter;
    Quiz quiz;
    Facts facts;
    QTimer* feedbackTimer;
    QSerialPort* serial; // Dodanie instancji QSerialPort

private slots:
    void on_convert2DecimalClicked();
    void on_convert2RomanClicked();
    void on_startQuizButton_clicked();
    void on_submitAnswerButton_clicked();
    void proceedToNextQuestion();
    void displayNextQuestion();
    void updateScoreDisplay();
    void showRandomGeneralFact();
    void showRandomRomanNumeralFact();
    void readFromPort(); // Metoda do odczytu danych z portu
};
