// RomanDigitalsToDecimal.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include "Dec2Roman.h"

using namespace std;


class RomanConverter {
private:
    map<char, int> roman_map = { {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000} };
    string valid_subtractors = "IXC";
    string non_repeatable = "VLD";
public:

    bool isValidRoman(string roman) {
        for (int i = 0; i < roman.length(); i++) {
            if (roman_map[roman[i]] < roman_map[roman[i + 1]]) {
                if (valid_subtractors.find(roman[i]) == string::npos || roman_map[roman[i]] * 10 < roman_map[roman[i + 1]]) {
                    return false;
                }
                if (i + 2 < roman.length() && roman_map[roman[i + 1]] <= roman_map[roman[i + 2]]) {
                    return false;
                }
            }
            if (i + 3 < roman.length() && roman[i] == roman[i + 1] && roman[i + 1] == roman[i + 2] && roman[i + 2] == roman[i + 3]) {
                return false;
            }
            if (non_repeatable.find(roman[i]) != string::npos && i + 1 < roman.length() && roman[i] == roman[i + 1]) {
                return false;
            }
        }
        return true;
    }

    int Roman2Dec(string roman) {
        if (!isValidRoman(roman)) {
            return -1;
        }
        int decimal = 0;
        int prev = 0;

        for (int i = roman.length() - 1; i >= 0; --i) {
            if (roman_map[roman[i]] >= prev)
                decimal += roman_map[roman[i]];
            else
                decimal -= roman_map[roman[i]];

            prev = roman_map[roman[i]];
        }

        return decimal == 0 ? -1 : decimal;
    }
};

class Facts {
public:
    void interestingFacts() {
        cout << "Ciekawostka: Slowo \"hundred\" pochodzi od staronordyjskiego slowa \"hundrath\", ktore oznacza 120, a nie 100." << endl;
    }

    void historyOfRomanNumerals() {
        cout << "Historia liczb rzymskich: Liczby rzymskie pochodza z starozytnego Rzymu i byly powszechnie uzywane do zapisywania liczb w Europie az do poznego sredniowiecza." << endl;
    }
};

class Quiz {
public:
    void start() {
        srand(time(0));
        map<int, string> questions = {
            {1, "I"}, {4, "IV"}, {9, "IX"}, {58, "LVIII"}, {1994, "MCMXCIV"},
            {3, "III"}, {20, "XX"}, {90, "XC"}
        };

        for (const auto& [dec, roman] : questions) {
            string userAnswer;
            int questionType = rand() % 2;

            if (questionType == 0) {
                cout << "Jaka jest liczba rzymska dla " << dec << "? ";
                cin >> userAnswer;
                if (userAnswer == roman) {
                    cout << "Poprawna odpowiedz!\n";
                }
                else {
                    cout << "Nieprawidlowa odpowiedź. Poprawna odpowiedz to: " << roman << "\n";
                }
            }
            else {
                cout << "Jaka jest liczba dziesietna dla '" << roman << "'? ";
                int userIntAnswer;
                cin >> userIntAnswer;
                if (userIntAnswer == dec) {
                    cout << "Poprawna odpowiedz!\n";
                }
                else {
                    cout << "Nieprawidlowa odpowiedz. Poprawna odpowiedz to: " << dec << "\n";
                }
            }
        }
    }
};

class Menu {
private:
    RomanConverter converter;
    Quiz quiz;
    Facts facts;

public:
    void start() {
        while (true) {
            cout << endl;
            cout << "\nMenu:\n";
            cout << "1. Konwersja liczb rzymskich na dziesietne\n";
            cout << "2. Konwersja liczb dziesietnych na rzymskie\n";
            cout << "3. Quiz\n";
            cout << "4. Ciekawostki o liczbach i ich konwersjach\n";
            cout << "5. Historia liczb rzymskich\n";
            cout << "6. Zakoncz\n";
            cout << "Wybierz opcje: ";

            int option;
            cin >> option;
            cout << endl;

            switch (option) {
            case 1: {
                string roman;
                cout << "Podaj liczbe rzymska: ";
                cin >> roman;
                // Konwertuj na wielkie litery
                transform(roman.begin(), roman.end(), roman.begin(), ::toupper);
                int decimal = converter.Roman2Dec(roman);
                if (decimal == -1) {
                    cout << "Nieprawidlowa liczba rzymska. Sprobuj ponownie.\n";
                    break;
                }
                cout << "Liczba dziesietna: " << decimal << endl;
                break;
            }
            case 2: {
                int decimal;
                cout << "Podaj liczbe dziesietna: ";
                if (!(cin >> decimal)) {
                    cout << "Nieprawidłowa liczba dziesiętna. Spróbuj ponownie.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }
                string roman = ConvertDecimal_2_Roman(decimal);
                cout << "Liczba rzymska: " << roman << endl;
                break;
            }
            case 3:
                quiz.start();
                break;
            case 4:
                facts.interestingFacts();
                break;
            case 5:
                facts.historyOfRomanNumerals();
                break;
            case 6:
                return;
            default:
                cout << "Nieprawidłowa opcja. Spróbuj ponownie.\n";
            }
        }
    }
};

int main() {
    Menu menu;
    menu.start();
    return 0;
}

