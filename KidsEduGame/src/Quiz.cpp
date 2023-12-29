#include "Quiz.h"
#include <iostream>
#include <map>
#include <cstdlib>
#include <ctime>

void Quiz::start() const {
    srand(static_cast<unsigned>(time(nullptr)));
    std::map<int, std::string> questions = {
        {1, "I"}, {4, "IV"}, {9, "IX"}, {58, "LVIII"}, {1994, "MCMXCIV"},
        {3, "III"}, {20, "XX"}, {90, "XC"}
    };

    for (const auto& [dec, roman] : questions) {
        std::string userAnswer;
        int questionType = rand() % 2;

        if (questionType == 0) {
            std::cout << "Jaka jest liczba rzymska dla " << dec << "? ";
            std::cin >> userAnswer;
            if (userAnswer == roman) {
                std::cout << "Poprawna odpowiedz!\n";
            }
            else {
                std::cout << "Nieprawidlowa odpowiedŸ. Poprawna odpowiedz to: " << roman << "\n";
            }
        }
        else {
            std::cout << "Jaka jest liczba dziesietna dla '" << roman << "'? ";
            int userIntAnswer;
            std::cin >> userIntAnswer;
            if (userIntAnswer == dec) {
                std::cout << "Poprawna odpowiedz!\n";
            }
            else {
                std::cout << "Nieprawidlowa odpowiedz. Poprawna odpowiedz to: " << dec << "\n";
            }
        }
    }
}
