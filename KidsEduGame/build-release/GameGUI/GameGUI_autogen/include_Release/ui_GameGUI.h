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
    QLabel *labelLogo;
    QLabel *labelKEDb3;
    QWidget *Konwersja;
    QLineEdit *lineEditRoman;
    QPushButton *pushButtonConvert2Decimal;
    QLineEdit *lineEditDecimal;
    QPushButton *pushButtonConvert2Roman;
    QLabel *labelRomanResult;
    QLabel *labelDecimalResult;
    QLabel *label_3;
    QLabel *label_2;
    QWidget *Facts;
    QPushButton *buttonShowGeneralFact;
    QPushButton *buttonShowRomanFact;
    QLabel *labelFactsDisplay;
    QLabel *label;
    QLabel *labelFactsL;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *GameGUIClass)
    {
        if (GameGUIClass->objectName().isEmpty())
            GameGUIClass->setObjectName("GameGUIClass");
        GameGUIClass->resize(862, 591);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(GameGUIClass->sizePolicy().hasHeightForWidth());
        GameGUIClass->setSizePolicy(sizePolicy);
        GameGUIClass->setAutoFillBackground(false);
        GameGUIClass->setStyleSheet(QString::fromUtf8("background-color: rgb(234, 206, 169);"));
        centralWidget = new QWidget(GameGUIClass);
        centralWidget->setObjectName("centralWidget");
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(60, 30, 741, 491));
        sizePolicy.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy);
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
        labelQuestion->setGeometry(QRect(180, 50, 401, 31));
        QFont font1;
        font1.setPointSize(13);
        font1.setUnderline(true);
        labelQuestion->setFont(font1);
        labelQuestion->setStyleSheet(QString::fromUtf8("border-color: rgb(170, 179, 160);"));
        labelQuestion->setFrameShape(QFrame::StyledPanel);
        labelQuestion->setFrameShadow(QFrame::Sunken);
        labelQuestion->setLineWidth(3);
        labelQuestion->setScaledContents(false);
        labelQuestion->setAlignment(Qt::AlignCenter);
        labelQuestion->setMargin(1);
        lineEditAnswer = new QLineEdit(Quiz);
        lineEditAnswer->setObjectName("lineEditAnswer");
        lineEditAnswer->setGeometry(QRect(300, 90, 151, 51));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Tahoma")});
        font2.setPointSize(12);
        font2.setBold(true);
        lineEditAnswer->setFont(font2);
        lineEditAnswer->setAlignment(Qt::AlignCenter);
        submitAnswerButton = new QPushButton(Quiz);
        submitAnswerButton->setObjectName("submitAnswerButton");
        submitAnswerButton->setGeometry(QRect(290, 150, 171, 61));
        QFont font3;
        font3.setPointSize(14);
        font3.setBold(true);
        submitAnswerButton->setFont(font3);
        submitAnswerButton->setStyleSheet(QString::fromUtf8("background-color: rgb(194, 131, 6);"));
        labelFeedback = new QLabel(Quiz);
        labelFeedback->setObjectName("labelFeedback");
        labelFeedback->setGeometry(QRect(290, 210, 171, 61));
        QFont font4;
        font4.setPointSize(20);
        font4.setBold(true);
        labelFeedback->setFont(font4);
        labelFeedback->setFrameShape(QFrame::StyledPanel);
        labelFeedback->setAlignment(Qt::AlignCenter);
        labelFeedback->setMargin(2);
        labelScore = new QLabel(Quiz);
        labelScore->setObjectName("labelScore");
        labelScore->setGeometry(QRect(510, 360, 201, 41));
        QFont font5;
        font5.setPointSize(22);
        font5.setBold(true);
        labelScore->setFont(font5);
        labelScore->setAutoFillBackground(false);
        labelScore->setStyleSheet(QString::fromUtf8("color: rgb(255, 152, 67);\n"
"background-color: rgb(241, 226, 201);\n"
"border-color: rgb(89, 66, 39);"));
        labelScore->setFrameShape(QFrame::StyledPanel);
        labelScore->setFrameShadow(QFrame::Sunken);
        labelScore->setLineWidth(0);
        labelScore->setMidLineWidth(0);
        startQuizButton = new QPushButton(Quiz);
        startQuizButton->setObjectName("startQuizButton");
        startQuizButton->setGeometry(QRect(330, 320, 81, 61));
        startQuizButton->setFont(font3);
        startQuizButton->setStyleSheet(QString::fromUtf8("background-color: rgb(29, 79, 21);\n"
"color: rgb(255, 255, 255);"));
        QIcon icon(QIcon::fromTheme(QString::fromUtf8("applications-multimedia")));
        startQuizButton->setIcon(icon);
        startQuizButton->setAutoDefault(false);
        labelLogo = new QLabel(Quiz);
        labelLogo->setObjectName("labelLogo");
        labelLogo->setGeometry(QRect(0, 280, 171, 161));
        labelLogo->setPixmap(QPixmap(QString::fromUtf8(":/GameGUI/KidsEduGameLogo.png")));
        labelLogo->setScaledContents(true);
        labelKEDb3 = new QLabel(Quiz);
        labelKEDb3->setObjectName("labelKEDb3");
        labelKEDb3->setGeometry(QRect(-10, 0, 741, 461));
        sizePolicy.setHeightForWidth(labelKEDb3->sizePolicy().hasHeightForWidth());
        labelKEDb3->setSizePolicy(sizePolicy);
        labelKEDb3->setPixmap(QPixmap(QString::fromUtf8(":/Background/KEGb3.png.png")));
        labelKEDb3->setScaledContents(true);
        tabWidget->addTab(Quiz, QString());
        labelKEDb3->raise();
        labelQuestion->raise();
        lineEditAnswer->raise();
        submitAnswerButton->raise();
        labelFeedback->raise();
        labelScore->raise();
        startQuizButton->raise();
        labelLogo->raise();
        Konwersja = new QWidget();
        Konwersja->setObjectName("Konwersja");
        lineEditRoman = new QLineEdit(Konwersja);
        lineEditRoman->setObjectName("lineEditRoman");
        lineEditRoman->setGeometry(QRect(150, 90, 191, 51));
        QFont font6;
        font6.setFamilies({QString::fromUtf8("Times New Roman")});
        font6.setPointSize(14);
        font6.setBold(false);
        lineEditRoman->setFont(font6);
        lineEditRoman->setAlignment(Qt::AlignCenter);
        pushButtonConvert2Decimal = new QPushButton(Konwersja);
        pushButtonConvert2Decimal->setObjectName("pushButtonConvert2Decimal");
        pushButtonConvert2Decimal->setGeometry(QRect(150, 210, 211, 51));
        QFont font7;
        font7.setPointSize(12);
        font7.setBold(true);
        pushButtonConvert2Decimal->setFont(font7);
        pushButtonConvert2Decimal->setAutoFillBackground(false);
        pushButtonConvert2Decimal->setStyleSheet(QString::fromUtf8("background-color: rgb(194, 131, 6);"));
        lineEditDecimal = new QLineEdit(Konwersja);
        lineEditDecimal->setObjectName("lineEditDecimal");
        lineEditDecimal->setGeometry(QRect(440, 90, 201, 51));
        lineEditDecimal->setFont(font6);
        lineEditDecimal->setAlignment(Qt::AlignCenter);
        pushButtonConvert2Roman = new QPushButton(Konwersja);
        pushButtonConvert2Roman->setObjectName("pushButtonConvert2Roman");
        pushButtonConvert2Roman->setGeometry(QRect(420, 210, 211, 51));
        pushButtonConvert2Roman->setFont(font7);
        pushButtonConvert2Roman->setAutoFillBackground(false);
        pushButtonConvert2Roman->setStyleSheet(QString::fromUtf8("background-color: rgb(194, 131, 6);"));
        labelRomanResult = new QLabel(Konwersja);
        labelRomanResult->setObjectName("labelRomanResult");
        labelRomanResult->setGeometry(QRect(450, 300, 161, 71));
        QFont font8;
        font8.setFamilies({QString::fromUtf8("Sitka Small Semibold")});
        font8.setPointSize(15);
        font8.setBold(true);
        labelRomanResult->setFont(font8);
        labelRomanResult->setMouseTracking(false);
        labelRomanResult->setFrameShape(QFrame::Box);
        labelRomanResult->setFrameShadow(QFrame::Raised);
        labelRomanResult->setLineWidth(3);
        labelRomanResult->setTextFormat(Qt::PlainText);
        labelRomanResult->setAlignment(Qt::AlignCenter);
        labelDecimalResult = new QLabel(Konwersja);
        labelDecimalResult->setObjectName("labelDecimalResult");
        labelDecimalResult->setGeometry(QRect(170, 300, 161, 71));
        labelDecimalResult->setFont(font8);
        labelDecimalResult->setMouseTracking(false);
        labelDecimalResult->setFrameShape(QFrame::Box);
        labelDecimalResult->setFrameShadow(QFrame::Raised);
        labelDecimalResult->setLineWidth(3);
        labelDecimalResult->setTextFormat(Qt::PlainText);
        labelDecimalResult->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(Konwersja);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(0, 360, 101, 101));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/GameGUI/KidsEduGameLogo.png")));
        label_3->setScaledContents(true);
        label_2 = new QLabel(Konwersja);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(0, 0, 751, 471));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/Background/KEGb1.png")));
        label_2->setScaledContents(true);
        tabWidget->addTab(Konwersja, QString());
        label_2->raise();
        lineEditDecimal->raise();
        lineEditRoman->raise();
        pushButtonConvert2Decimal->raise();
        pushButtonConvert2Roman->raise();
        labelRomanResult->raise();
        labelDecimalResult->raise();
        label_3->raise();
        Facts = new QWidget();
        Facts->setObjectName("Facts");
        buttonShowGeneralFact = new QPushButton(Facts);
        buttonShowGeneralFact->setObjectName("buttonShowGeneralFact");
        buttonShowGeneralFact->setGeometry(QRect(20, 50, 181, 61));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(buttonShowGeneralFact->sizePolicy().hasHeightForWidth());
        buttonShowGeneralFact->setSizePolicy(sizePolicy1);
        QFont font9;
        font9.setFamilies({QString::fromUtf8("Algerian")});
        font9.setPointSize(15);
        font9.setBold(false);
        buttonShowGeneralFact->setFont(font9);
        buttonShowGeneralFact->setStyleSheet(QString::fromUtf8("background-color: rgb(194, 131, 6);"));
        buttonShowRomanFact = new QPushButton(Facts);
        buttonShowRomanFact->setObjectName("buttonShowRomanFact");
        buttonShowRomanFact->setGeometry(QRect(20, 150, 181, 61));
        sizePolicy1.setHeightForWidth(buttonShowRomanFact->sizePolicy().hasHeightForWidth());
        buttonShowRomanFact->setSizePolicy(sizePolicy1);
        buttonShowRomanFact->setFont(font9);
        buttonShowRomanFact->setStyleSheet(QString::fromUtf8("background-color: rgb(194, 131, 6);"));
        labelFactsDisplay = new QLabel(Facts);
        labelFactsDisplay->setObjectName("labelFactsDisplay");
        labelFactsDisplay->setEnabled(true);
        labelFactsDisplay->setGeometry(QRect(360, 140, 221, 191));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(labelFactsDisplay->sizePolicy().hasHeightForWidth());
        labelFactsDisplay->setSizePolicy(sizePolicy2);
        QFont font10;
        font10.setPointSize(13);
        labelFactsDisplay->setFont(font10);
        labelFactsDisplay->setFrameShape(QFrame::Panel);
        labelFactsDisplay->setFrameShadow(QFrame::Raised);
        labelFactsDisplay->setTextFormat(Qt::AutoText);
        labelFactsDisplay->setAlignment(Qt::AlignCenter);
        labelFactsDisplay->setWordWrap(true);
        labelFactsDisplay->setMargin(1);
        label = new QLabel(Facts);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 941, 491));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy3);
        label->setPixmap(QPixmap(QString::fromUtf8(":/Background/KEGb2.png")));
        label->setScaledContents(true);
        labelFactsL = new QLabel(Facts);
        labelFactsL->setObjectName("labelFactsL");
        labelFactsL->setGeometry(QRect(0, 270, 211, 191));
        labelFactsL->setPixmap(QPixmap(QString::fromUtf8(":/GameGUI/KidsEduGameLogo.png")));
        labelFactsL->setScaledContents(true);
        tabWidget->addTab(Facts, QString());
        label->raise();
        buttonShowGeneralFact->raise();
        buttonShowRomanFact->raise();
        labelFactsDisplay->raise();
        labelFactsL->raise();
        GameGUIClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(GameGUIClass);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 862, 22));
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
        labelQuestion->setText(QCoreApplication::translate("GameGUIClass", "Pytanie - aby je zobaczy\304\207 kliknij Start", nullptr));
        lineEditAnswer->setPlaceholderText(QCoreApplication::translate("GameGUIClass", "Wpisz odpowied\305\272", nullptr));
        submitAnswerButton->setText(QCoreApplication::translate("GameGUIClass", "Odpowiedz", nullptr));
        labelFeedback->setText(QCoreApplication::translate("GameGUIClass", "Poprawno\305\233\304\207", nullptr));
        labelScore->setText(QCoreApplication::translate("GameGUIClass", "Wynik", nullptr));
        startQuizButton->setText(QCoreApplication::translate("GameGUIClass", "Start", nullptr));
        labelLogo->setText(QString());
        labelKEDb3->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(Quiz), QCoreApplication::translate("GameGUIClass", "Quiz", nullptr));
        lineEditRoman->setText(QString());
        lineEditRoman->setPlaceholderText(QCoreApplication::translate("GameGUIClass", "Wpisz liczb\304\231 rzymsk\304\205", nullptr));
        pushButtonConvert2Decimal->setText(QCoreApplication::translate("GameGUIClass", "Konwertuj na dziesi\304\231tne", nullptr));
        lineEditDecimal->setPlaceholderText(QCoreApplication::translate("GameGUIClass", "Wpisz liczb\304\231 dziesi\304\231tn\304\205", nullptr));
        pushButtonConvert2Roman->setText(QCoreApplication::translate("GameGUIClass", "Konwertuj na rzymskie", nullptr));
        labelRomanResult->setText(QCoreApplication::translate("GameGUIClass", "Wynik", nullptr));
        labelDecimalResult->setText(QCoreApplication::translate("GameGUIClass", "Wynik", nullptr));
        label_3->setText(QString());
        label_2->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(Konwersja), QCoreApplication::translate("GameGUIClass", "Konwersja", nullptr));
        buttonShowGeneralFact->setText(QCoreApplication::translate("GameGUIClass", "Og\303\263lne", nullptr));
        buttonShowRomanFact->setText(QCoreApplication::translate("GameGUIClass", "Historyczne", nullptr));
        labelFactsDisplay->setText(QCoreApplication::translate("GameGUIClass", "Wybierz kategori\304\231 a pojawi si\304\231 ciekawostka", nullptr));
        label->setText(QString());
        labelFactsL->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(Facts), QCoreApplication::translate("GameGUIClass", "Ciekawostki", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GameGUIClass: public Ui_GameGUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEGUI_H
