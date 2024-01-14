#include "GameGUI.h"

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
    feedbackTimer->setInterval(3000); // Ustawienie interwału na 5000 ms (5 sekund)
    connect(feedbackTimer, &QTimer::timeout, this, &GameGUI::proceedToNextQuestion);

    // Używamy nowszej składni do połączeń przycisków z ciekawostkami
    connect(ui->buttonShowGeneralFact, &QPushButton::clicked, this, &GameGUI::showRandomGeneralFact);
    connect(ui->buttonShowRomanFact, &QPushButton::clicked, this, &GameGUI::showRandomRomanNumeralFact);
}

void GameGUI::on_convert2DecimalClicked() {
    QString roman = ui->lineEditRoman->text();
    int decimal = converter.Roman2Dec(roman.toUpper().toStdString());
    ui->labelDecimalResult->setText(decimal != -1 ? QString::number(decimal) : "Błąd!");
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
    delete ui;
}