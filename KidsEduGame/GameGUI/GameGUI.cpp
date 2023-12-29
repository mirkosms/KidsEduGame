#include "GameGUI.h"

GameGUI::GameGUI(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::GameGUIClass()), quiz() // Inicjalizacja quizu
{
    ui->setupUi(this);
    connect(ui->pushButtonConvert2Decimal, SIGNAL(clicked()), this, SLOT(on_convert2DecimalClicked()));
    connect(ui->pushButtonConvert2Roman, SIGNAL(clicked()), this, SLOT(on_convert2RomanClicked()));

    // Nowe po³¹czenia dla quizu
    connect(ui->startQuizButton, SIGNAL(clicked()), this, SLOT(on_startQuizButton_clicked()));
    connect(ui->submitAnswerButton, SIGNAL(clicked()), this, SLOT(on_submitAnswerButton_clicked()));

    feedbackTimer = new QTimer(this);  // Inicjalizacja timera
    feedbackTimer->setInterval(5000);  // Ustawienie interwa³u na 5000 ms (5 sekund)
    connect(feedbackTimer, &QTimer::timeout, this, &GameGUI::proceedToNextQuestion);
}
void GameGUI::on_convert2DecimalClicked() {
    QString roman = ui->lineEditRoman->text();
    int decimal = converter.Roman2Dec(roman.toUpper().toStdString());
    ui->labelDecimalResult->setText(decimal != -1 ? QString::number(decimal) : "Blad");
}

void GameGUI::on_convert2RomanClicked() {
    bool ok;
    int decimal = ui->lineEditDecimal->text().toInt(&ok);
    if (ok) {
        QString roman = QString::fromStdString(ConvertDecimal_2_Roman(decimal));
        ui->labelRomanResult->setText(!roman.isEmpty() ? roman : "Blad");
    }
    else {
        ui->labelRomanResult->setText("Blad");
    }
}

void GameGUI::on_startQuizButton_clicked() {
    // Rozpocznij quiz i wyœwietl pierwsze pytanie
    quiz.start();
    displayNextQuestion();
}

void GameGUI::on_submitAnswerButton_clicked() {
    QString userAnswer = ui->lineEditAnswer->text();
    bool isCorrect = quiz.checkAnswer(userAnswer.toStdString()); // SprawdŸ odpowiedŸ

    // Ustaw tekst w zale¿noœci od poprawnoœci odpowiedzi
    ui->labelFeedback->setText(isCorrect ? "Dobrze!" : "Niepoprawnie.");
    ui->labelFeedback->setStyleSheet(isCorrect ? "color: green;" : "color: red;"); // Ustaw kolor na zielony lub czerwony

    if (isCorrect) {
        updateScoreDisplay(); // Aktualizuj wynik tylko jeœli odpowiedŸ jest poprawna
    }

    // Wy³¹cz przyciski, aby unikn¹æ ponownego klikniêcia
    ui->submitAnswerButton->setEnabled(false);
    ui->startQuizButton->setEnabled(false);

    // Rozpocznij odliczanie do przejœcia do nastêpnego pytania lub zakoñczenia quizu
    feedbackTimer->start();
}

void GameGUI::proceedToNextQuestion() {
    feedbackTimer->stop();  // Zatrzymaj timer
    displayNextQuestion();  // PrzejdŸ do nastêpnego pytania lub zakoñcz quiz
    ui->submitAnswerButton->setEnabled(true); // Ponownie w³¹cz przycisk
    ui->startQuizButton->setEnabled(true); // Ponownie w³¹cz przycisk startu quizu
    ui->labelFeedback->clear(); // Wyczyœæ komunikat o poprawnoœci
}

void GameGUI::displayNextQuestion() {
    auto questionPair = quiz.getNextQuestion();
    if (questionPair.first != -1) {
        QString questionText = QString("Jaka jest liczba dziesietna dla rzymskiej '%1'?").arg(QString::fromStdString(questionPair.second));
        ui->labelQuestion->setText(questionText);
        ui->lineEditAnswer->clear();
        ui->labelFeedback->clear(); // Wyczyœæ komunikat o poprawnoœci
    }
    else {
        ui->labelQuestion->setText("Koniec quizu!");
        ui->submitAnswerButton->setEnabled(false);
        ui->startQuizButton->setEnabled(true);
        ui->labelFeedback->clear();
    }
}

void GameGUI::updateScoreDisplay() {
    int score = quiz.getScore();
    ui->labelScore->setText(QString("Twoj wynik: %1").arg(score));
}


GameGUI::~GameGUI()
{
    delete ui;
}
