#include "Quiz.h"
#include <cstdlib>
#include <ctime>

Quiz::Quiz() : score(0), currentQuestionIndex(0) {
    srand(static_cast<unsigned int>(time(nullptr)));
    // Inicjalizacja pyta�
    questions = {
        {1, "I"}, {4, "IV"}, {9, "IX"}, {58, "LVIII"}, {1994, "MCMXCIV"},
        {3, "III"}, {20, "XX"}, {90, "XC"}
    };
    answeredCorrectly.resize(questions.size(), false); // Inicjalizacja wektora odpowiedzi na false
}

void Quiz::start() {
    resetQuiz(); // Resetujemy quiz i zaczynamy od pierwszego pytania
}

std::pair<int, std::string> Quiz::getNextQuestion() {
    if (currentQuestionIndex < questions.size()) {
        return questions[currentQuestionIndex++]; // Zwraca bie��ce pytanie i zwi�ksza indeks
    }
    return { -1, "" }; // Je�li pytania si� sko�czy�y
}

bool Quiz::checkAnswer(const std::string& userAnswer) {
    if (currentQuestionIndex > 0 && currentQuestionIndex <= questions.size() && !answeredCorrectly[currentQuestionIndex - 1]) {
        const auto& [correctDec, correctRoman] = questions[currentQuestionIndex - 1];
        if (userAnswer == correctRoman || std::to_string(correctDec) == userAnswer) {
            score++;
            answeredCorrectly[currentQuestionIndex - 1] = true; // Oznaczamy pytanie jako poprawnie zaliczone
            return true;
        }
    }
    return false;
}

size_t Quiz::getCurrentQuestionIndex() const {
    return currentQuestionIndex;
}

int Quiz::getScore() const {
    return score;
}

void Quiz::resetQuiz() {
    score = 0;
    currentQuestionIndex = 0;
    std::fill(answeredCorrectly.begin(), answeredCorrectly.end(), false); // Resetujemy flagi odpowiedzi na false
}
