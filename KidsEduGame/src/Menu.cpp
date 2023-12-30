#include "Menu.h"
#include <iostream>
#include <string>
#include <limits>
#include <algorithm>

void Menu::start() {
    RomanConverter converter;
    Quiz quiz;
    Facts facts;

    while (true) {
        std::cout << "\nMenu:\n";
        std::cout << "1. Konwersja liczb rzymskich na dziesietne\n";
        std::cout << "2. Konwersja liczb dziesietnych na rzymskie\n";
        std::cout << "3. Quiz\n";
        std::cout << "4. Ciekawostki o liczbach i ich konwersjach\n";
        std::cout << "5. Historia liczb rzymskich\n";
        std::cout << "6. Zakoncz\n";
        std::cout << "Wybierz opcje: ";

        int option;
        std::cin >> option;
        std::cout << std::endl;

        switch (option) {
        case 1: {
            std::string roman;
            std::cout << "Podaj liczbe rzymska: ";
            std::cin >> roman;
            std::transform(roman.begin(), roman.end(), roman.begin(), ::toupper);
            int decimal = converter.Roman2Dec(roman);
            if (decimal == -1) {
                std::cout << "Nieprawidlowa liczba rzymska. Sprobuj ponownie.\n";
            }
            else {
                std::cout << "Liczba dziesietna: " << decimal << std::endl;
            }
            break;
        }
        case 2: {
            int decimal;
            std::cout << "Podaj liczbe dziesietna: ";
            if (!(std::cin >> decimal)) {
                std::cout << "Nieprawid³owa liczba dziesiêtna. Spróbuj ponownie.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            else {
                std::string roman = ConvertDecimal_2_Roman(decimal);
                std::cout << "Liczba rzymska: " << roman << std::endl;
            }
            break;
        }
        case 3:
            quiz.start();
            break;
        case 4:
            std::cout << facts.getRandomGeneralFact() << std::endl;
            break;
        case 5:
            std::cout << facts.getRandomRomanNumeralFact() << std::endl;
            break;
        case 6:
            return;
        default:
            std::cout << "Nieprawid³owa opcja. Spróbuj ponownie.\n";
        }
    }
}
