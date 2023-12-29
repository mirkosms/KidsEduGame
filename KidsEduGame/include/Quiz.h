#ifndef QUIZ_H
#define QUIZ_H

#include <string>
#include <vector>
#include <utility> // Dla std::pair

class Quiz {
private:
    int score;
    std::vector<std::pair<int, std::string>> questions; // Trzymamy pary decymlane i rzymskie
    std::vector<bool> answeredCorrectly;
    size_t currentQuestionIndex; // Typ size_t do indeksowania wektorów

public:
    Quiz();
    size_t getCurrentQuestionIndex() const;
    std::pair<int, std::string> getNextQuestion(); // Zwraca nastêpne pytanie jako parê
    bool checkAnswer(const std::string& userAnswer);
    int getScore() const; // Zwraca wynik
    void resetQuiz(); // Resetuje quiz
    void start(); // Przygotowuje quiz do rozpoczêcia
};

#endif // QUIZ_H
