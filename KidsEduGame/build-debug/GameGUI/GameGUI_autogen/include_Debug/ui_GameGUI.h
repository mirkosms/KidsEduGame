/********************************************************************************
** Form generated from reading UI file 'GameGUI.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEGUI_H
#define UI_GAMEGUI_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameGUIClass
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *Quiz;
    QLabel *labelQuestion;
    QLineEdit *lineEditAnswer;
    QPushButton *submitAnswerButton;
    QLabel *labelFeedback;
    QLabel *labelScore;
    QPushButton *startQuizButton;
    QWidget *Konwersja;
    QLineEdit *lineEditRoman;
    QPushButton *pushButtonConvert2Decimal;
    QLineEdit *lineEditDecimal;
    QPushButton *pushButtonConvert2Roman;
    QLabel *labelRomanResult;
    QLabel *labelDecimalResult;
    QWidget *tab;
    QPushButton *buttonShowGeneralFact;
    QPushButton *buttonShowRomanFact;
    QLabel *labelFactsDisplay;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *GameGUIClass)
    {
        if (GameGUIClass->objectName().isEmpty())
            GameGUIClass->setObjectName("GameGUIClass");
        GameGUIClass->resize(751, 542);
        centralWidget = new QWidget(GameGUIClass);
        centralWidget->setObjectName("centralWidget");
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(80, 30, 641, 441));
        QFont font;
        font.setFamilies({QString::fromUtf8("Times New Roman")});
        font.setPointSize(14);
        font.setBold(true);
        tabWidget->setFont(font);
        tabWidget->setAutoFillBackground(false);
        tabWidget->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border-radius: 15px;\n"
"    background-color: #89CFF0;\n"
"    padding: 10px;\n"
"    }\n"
"    QPushButton:hover {\n"
"        background-color: #1E90FF;\n"
"    }\n"
"    "));
        Quiz = new QWidget();
        Quiz->setObjectName("Quiz");
        labelQuestion = new QLabel(Quiz);
        labelQuestion->setObjectName("labelQuestion");
        labelQuestion->setGeometry(QRect(140, 20, 411, 31));
        QFont font1;
        font1.setPointSize(13);
        font1.setUnderline(true);
        labelQuestion->setFont(font1);
        lineEditAnswer = new QLineEdit(Quiz);
        lineEditAnswer->setObjectName("lineEditAnswer");
        lineEditAnswer->setGeometry(QRect(290, 90, 151, 51));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Tahoma")});
        font2.setPointSize(12);
        font2.setBold(true);
        lineEditAnswer->setFont(font2);
        submitAnswerButton = new QPushButton(Quiz);
        submitAnswerButton->setObjectName("submitAnswerButton");
        submitAnswerButton->setGeometry(QRect(290, 160, 151, 61));
        QFont font3;
        font3.setPointSize(14);
        font3.setBold(true);
        submitAnswerButton->setFont(font3);
        labelFeedback = new QLabel(Quiz);
        labelFeedback->setObjectName("labelFeedback");
        labelFeedback->setGeometry(QRect(250, 240, 161, 61));
        QFont font4;
        font4.setPointSize(20);
        font4.setBold(true);
        labelFeedback->setFont(font4);
        labelScore = new QLabel(Quiz);
        labelScore->setObjectName("labelScore");
        labelScore->setGeometry(QRect(400, 340, 201, 41));
        QFont font5;
        font5.setPointSize(22);
        font5.setBold(true);
        labelScore->setFont(font5);
        labelScore->setStyleSheet(QString::fromUtf8("color: rgb(255, 152, 67);"));
        startQuizButton = new QPushButton(Quiz);
        startQuizButton->setObjectName("startQuizButton");
        startQuizButton->setGeometry(QRect(70, 120, 81, 61));
        startQuizButton->setFont(font3);
        startQuizButton->setStyleSheet(QString::fromUtf8("background-color: rgb(92, 255, 67);\n"
""));
        QIcon icon(QIcon::fromTheme(QString::fromUtf8("applications-multimedia")));
        startQuizButton->setIcon(icon);
        startQuizButton->setAutoDefault(false);
        tabWidget->addTab(Quiz, QString());
        Konwersja = new QWidget();
        Konwersja->setObjectName("Konwersja");
        lineEditRoman = new QLineEdit(Konwersja);
        lineEditRoman->setObjectName("lineEditRoman");
        lineEditRoman->setGeometry(QRect(60, 40, 201, 51));
        lineEditRoman->setFont(font);
        pushButtonConvert2Decimal = new QPushButton(Konwersja);
        pushButtonConvert2Decimal->setObjectName("pushButtonConvert2Decimal");
        pushButtonConvert2Decimal->setGeometry(QRect(60, 110, 211, 81));
        QFont font6;
        font6.setPointSize(12);
        font6.setBold(true);
        pushButtonConvert2Decimal->setFont(font6);
        pushButtonConvert2Decimal->setAutoFillBackground(false);
        lineEditDecimal = new QLineEdit(Konwersja);
        lineEditDecimal->setObjectName("lineEditDecimal");
        lineEditDecimal->setGeometry(QRect(370, 40, 211, 51));
        lineEditDecimal->setFont(font);
        pushButtonConvert2Roman = new QPushButton(Konwersja);
        pushButtonConvert2Roman->setObjectName("pushButtonConvert2Roman");
        pushButtonConvert2Roman->setGeometry(QRect(370, 110, 211, 81));
        pushButtonConvert2Roman->setFont(font6);
        pushButtonConvert2Roman->setAutoFillBackground(false);
        labelRomanResult = new QLabel(Konwersja);
        labelRomanResult->setObjectName("labelRomanResult");
        labelRomanResult->setGeometry(QRect(388, 240, 161, 71));
        QFont font7;
        font7.setFamilies({QString::fromUtf8("Sitka Small Semibold")});
        font7.setPointSize(15);
        font7.setBold(true);
        labelRomanResult->setFont(font7);
        labelRomanResult->setMouseTracking(false);
        labelRomanResult->setFrameShape(QFrame::Box);
        labelRomanResult->setFrameShadow(QFrame::Raised);
        labelRomanResult->setLineWidth(3);
        labelRomanResult->setTextFormat(Qt::PlainText);
        labelRomanResult->setAlignment(Qt::AlignCenter);
        labelDecimalResult = new QLabel(Konwersja);
        labelDecimalResult->setObjectName("labelDecimalResult");
        labelDecimalResult->setGeometry(QRect(78, 240, 161, 71));
        labelDecimalResult->setFont(font7);
        labelDecimalResult->setMouseTracking(false);
        labelDecimalResult->setFrameShape(QFrame::Box);
        labelDecimalResult->setFrameShadow(QFrame::Raised);
        labelDecimalResult->setLineWidth(3);
        labelDecimalResult->setTextFormat(Qt::PlainText);
        labelDecimalResult->setAlignment(Qt::AlignCenter);
        tabWidget->addTab(Konwersja, QString());
        tab = new QWidget();
        tab->setObjectName("tab");
        buttonShowGeneralFact = new QPushButton(tab);
        buttonShowGeneralFact->setObjectName("buttonShowGeneralFact");
        buttonShowGeneralFact->setGeometry(QRect(140, 80, 151, 61));
        QFont font8;
        font8.setFamilies({QString::fromUtf8("Algerian")});
        font8.setPointSize(15);
        font8.setBold(false);
        buttonShowGeneralFact->setFont(font8);
        buttonShowRomanFact = new QPushButton(tab);
        buttonShowRomanFact->setObjectName("buttonShowRomanFact");
        buttonShowRomanFact->setGeometry(QRect(340, 80, 181, 61));
        buttonShowRomanFact->setFont(font8);
        labelFactsDisplay = new QLabel(tab);
        labelFactsDisplay->setObjectName("labelFactsDisplay");
        labelFactsDisplay->setGeometry(QRect(150, 200, 351, 91));
        QFont font9;
        font9.setPointSize(13);
        labelFactsDisplay->setFont(font9);
        labelFactsDisplay->setFrameShape(QFrame::Panel);
        labelFactsDisplay->setFrameShadow(QFrame::Raised);
        labelFactsDisplay->setTextFormat(Qt::AutoText);
        labelFactsDisplay->setWordWrap(true);
        tabWidget->addTab(tab, QString());
        GameGUIClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(GameGUIClass);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 751, 22));
        GameGUIClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(GameGUIClass);
        mainToolBar->setObjectName("mainToolBar");
        GameGUIClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(GameGUIClass);
        statusBar->setObjectName("statusBar");
        GameGUIClass->setStatusBar(statusBar);

        retranslateUi(GameGUIClass);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(GameGUIClass);
    } // setupUi

    void retranslateUi(QMainWindow *GameGUIClass)
    {
        GameGUIClass->setWindowTitle(QCoreApplication::translate("GameGUIClass", "GameGUI", nullptr));
        labelQuestion->setText(QCoreApplication::translate("GameGUIClass", "Pytanie", nullptr));
        lineEditAnswer->setPlaceholderText(QCoreApplication::translate("GameGUIClass", "Wpisz odpowied\305\272", nullptr));
        submitAnswerButton->setText(QCoreApplication::translate("GameGUIClass", "Odpowiedz", nullptr));
        labelFeedback->setText(QCoreApplication::translate("GameGUIClass", "Poprawno\305\233\304\207", nullptr));
        labelScore->setText(QCoreApplication::translate("GameGUIClass", "Wynik", nullptr));
        startQuizButton->setText(QCoreApplication::translate("GameGUIClass", "Start", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Quiz), QCoreApplication::translate("GameGUIClass", "Quiz", nullptr));
        lineEditRoman->setText(QString());
        lineEditRoman->setPlaceholderText(QCoreApplication::translate("GameGUIClass", "Wpisz liczb\304\231 rzymsk\304\205", nullptr));
        pushButtonConvert2Decimal->setText(QCoreApplication::translate("GameGUIClass", "Konwertuj na dziesi\304\231tne", nullptr));
        lineEditDecimal->setPlaceholderText(QCoreApplication::translate("GameGUIClass", "Wpisz liczb\304\231 dziesi\304\231tn\304\205", nullptr));
        pushButtonConvert2Roman->setText(QCoreApplication::translate("GameGUIClass", "Konwertuj na rzymskie", nullptr));
        labelRomanResult->setText(QCoreApplication::translate("GameGUIClass", "Wynik", nullptr));
        labelDecimalResult->setText(QCoreApplication::translate("GameGUIClass", "Wynik", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Konwersja), QCoreApplication::translate("GameGUIClass", "Konwersja", nullptr));
        buttonShowGeneralFact->setText(QCoreApplication::translate("GameGUIClass", "Og\303\263lne", nullptr));
        buttonShowRomanFact->setText(QCoreApplication::translate("GameGUIClass", "Historyczne", nullptr));
        labelFactsDisplay->setText(QCoreApplication::translate("GameGUIClass", "Tekst ciekawostki", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("GameGUIClass", "Ciekawostki", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GameGUIClass: public Ui_GameGUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEGUI_H
