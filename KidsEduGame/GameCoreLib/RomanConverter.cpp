#include "RomanConverter.h"
#include <map>
#include <string>
#include <iostream>

RomanConverter::RomanConverter() {
    roman_map = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
}

bool RomanConverter::isValidRoman(const std::string& roman) {
    if (roman.empty()) return false;

    std::map<char, int> values = {
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
        {'C', 100}, {'D', 500}, {'M', 1000}
    };

    int last_value = 0;
    char last_char = '\0';
    int repeat_count = 0;

    for (size_t i = 0; i < roman.size(); ++i) {
        char current_char = roman[i];

        // Sprawdzenie, czy znak jest prawidłowym znakiem rzymskim
        if (values.find(current_char) == values.end()) {
            return false; // Nieprawidłowy znak
        }

        int current_value = values[current_char];

        // Sprawdzenie powtórzeń
        if (current_char == last_char) {
            repeat_count++;
            if (repeat_count > 3 || (current_char == 'V' || current_char == 'L' || current_char == 'D')) {
                return false; // Znak 'V', 'L', 'D' nie może się powtarzać, inne maksymalnie 3 razy
            }
        } else {
            repeat_count = 1;
        }

        // Sprawdzenie subtrakcji
        if (last_value < current_value) {
            // Subtrakcja jest dozwolona tylko w przypadku, gdy ostatni znak był 'I', 'X', lub 'C'
            if (last_value != 0 && (current_value > last_value * 10 || last_char != 'I' && last_char != 'X' && last_char != 'C')) {
                return false; // Nieprawidłowa subtrakcja
            }
            // Sprawdzenie, czy nie jest to wielokrotna subtrakcja (np. 'IIX')
            if (i > 1 && values[roman[i - 2]] < current_value) {
            return false; // Nieprawidłowe wielokrotne odejmowanie
            }
            }
                last_char = current_char; // Aktualizacja ostatniego znaku
                last_value = current_value; // Aktualizacja ostatniej wartości
            }

            // Dodatkowe sprawdzenie na koniec, czy ostatni znak nie jest nieprawidłową subtrakcją
            if (roman.size() > 1 && values[roman[roman.size() - 2]] < values[roman.back()]) {
                if (roman[roman.size() - 2] != 'I' && roman[roman.size() - 2] != 'X' && roman[roman.size() - 2] != 'C') {
                    return false; // Nieprawidłowa subtrakcja na końcu ciągu
                }
            }

    return true; // Liczba rzymska jest prawidłowa
}




int RomanConverter::Roman2Dec(const std::string& roman) {
    if (!isValidRoman(roman)) {
        return -1;
    }

    int decimal = 0;
    int prev_value = 0;

    for (size_t i = 0; i < roman.length(); i++) {
        int current_value = roman_map.at(roman[i]);

        if (prev_value && prev_value < current_value) {
            decimal += current_value - 2 * prev_value;
        }
        else {
            decimal += current_value;
        }
        prev_value = current_value;
    }

    return decimal;
}

