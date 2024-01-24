#include "GameGUI.h"
#include <QSerialPort>

// W klasie GameGUI
QSerialPort* serial;

GameGUI::GameGUI(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::GameGUIClass()), quiz(), facts() // Inicjalizacja quizu i ciekawostek
{
    ui->setupUi(this);
    connect(ui->pushButtonConvert2Decimal, &QPushButton::clicked, this, &GameGUI::on_convert2DecimalClicked);
    connect(ui->pushButtonConvert2Roman, &QPushButton::clicked, this, &GameGUI::on_convert2RomanClicked);

    connect(ui->startQuizButton, &QPushButton::clicked, this, &GameGUI::on_startQuizButton_clicked);
    connect(ui->submitAnswerButton, &QPushButton::clicked, this, &GameGUI::on_submitAnswerButton_clicked);

    feedbackTimer = new QTimer(this);
    feedbackTimer->setInterval(3000); // Ustawienie interwału na 3000 ms (3 sekund)
    connect(feedbackTimer, &QTimer::timeout, this, &GameGUI::proceedToNextQuestion);

    connect(ui->buttonShowGeneralFact, &QPushButton::clicked, this, &GameGUI::showRandomGeneralFact);
    connect(ui->buttonShowRomanFact, &QPushButton::clicked, this, &GameGUI::showRandomRomanNumeralFact);

    serial = new QSerialPort(this);
    serial->setPortName("COM9"); // Zmienić na odpowiedni port
    serial->setBaudRate(28800);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);
    //serial->open(QIODevice::ReadWrite);
    if (!serial->open(QIODevice::ReadWrite)) {
        // Obsługa błędu, jeśli port się nie otworzy
    }

    connect(serial, &QSerialPort::readyRead, this, &GameGUI::readFromPort);
}

void GameGUI::readFromPort() {
    QByteArray data = serial->readAll();
    QString receivedData = QString::fromUtf8(data).trimmed(); // Zakładamy kodowanie ASCII

    if (!receivedData.isEmpty()) {
        // Wprowadzanie danych do aktywnego pola tekstowego
        QWidget* focusedWidget = QApplication::focusWidget();
        QLineEdit* lineEdit = dynamic_cast<QLineEdit*>(focusedWidget);
        if (lineEdit) {
            lineEdit->insert(receivedData); // Wstawia otrzymane dane do aktywnego pola tekstowego
        }
    }
}

void GameGUI::on_convert2DecimalClicked() {
    QString roman = ui->lineEditRoman->text();
    int decimal = converter.Roman2Dec(roman.toUpper().toStdString());

    if (decimal == -1) {
        ui->labelDecimalResult->setText("Błąd!"); // Nieprawidłowa liczba rzymska
    }
    else if (decimal == -2) {
        ui->labelDecimalResult->setText("N/D"); // Liczba przekracza maksymalną wartość
    }
    else {
        ui->labelDecimalResult->setText(QString::number(decimal)); // Poprawna konwersja
    }
}

void GameGUI::on_convert2RomanClicked() {
    bool ok;
    int decimal = ui->lineEditDecimal->text().toInt(&ok);
    if (ok) {
        QString roman = QString::fromStdString(ConvertDecimal_2_Roman(decimal));
        ui->labelRomanResult->setText(!roman.isEmpty() ? roman : "Błąd!");
    }
    else {
        ui->labelRomanResult->setText("Błąd!");
    }
}

void GameGUI::on_startQuizButton_clicked() {
    // Rozpocznij quiz i wyświetl pierwsze pytanie
    quiz.start();
    displayNextQuestion();
}

void GameGUI::on_submitAnswerButton_clicked() {
    QString userAnswer = ui->lineEditAnswer->text();
    bool isCorrect = quiz.checkAnswer(userAnswer.toStdString()); // Sprawdź odpowiedź

    // Ustaw tekst w zależności od poprawności odpowiedzi
    ui->labelFeedback->clear();  // Wyczyść obecny stan
    ui->labelFeedback->setText(isCorrect ? "Dobrze!" : "Źle.");
    ui->labelFeedback->setStyleSheet(isCorrect ? "color: green;" : "color: red;"); // Ustaw kolor na zielony lub czerwony

    if (isCorrect) {
        updateScoreDisplay(); // Aktualizuj wynik tylko jeśli odpowiedź jest poprawna
    }

    feedbackTimer->start();
    ui->submitAnswerButton->setEnabled(false);
    ui->startQuizButton->setEnabled(false);

}

void GameGUI::proceedToNextQuestion() {
    feedbackTimer->stop();  // Zatrzymaj timer
    ui->labelFeedback->clear(); // Wyczyść komunikat o poprawności
    displayNextQuestion();  // Przejdź do następnego pytania lub zakończ quiz
    ui->submitAnswerButton->setEnabled(true); // Ponownie włącz przycisk

}

void GameGUI::displayNextQuestion() {
    auto questionPair = quiz.getNextQuestion();
    if (questionPair.first != -1) {
        QString questionText = QString("Jaka jest liczba dziesiętna dla rzymskiej '%1'?").arg(QString::fromStdString(questionPair.second));
        ui->labelQuestion->setText(questionText);
        ui->lineEditAnswer->clear();
        ui->labelFeedback->clear();
    }
    else {
        ui->labelQuestion->setText("Koniec quizu!");
        ui->submitAnswerButton->setEnabled(false);
        ui->startQuizButton->setEnabled(true);
        ui->labelFeedback->clear();
        ui->lineEditAnswer->clear();
        ui->labelFeedback->clear();
    }
}

void GameGUI::updateScoreDisplay() {
    int score = quiz.getScore();
    ui->labelScore->setText(QString("Twój wynik: %1").arg(score));
}

void GameGUI::showRandomGeneralFact() {
    QString fact = QString::fromStdString(facts.getRandomGeneralFact());
    ui->labelFactsDisplay->setText(fact);
}

void GameGUI::showRandomRomanNumeralFact() {
    QString fact = QString::fromStdString(facts.getRandomRomanNumeralFact());
    ui->labelFactsDisplay->setText(fact);
}

GameGUI::~GameGUI()
{
    if (serial->isOpen())
        serial->close();
    delete serial;
    delete ui;
}
