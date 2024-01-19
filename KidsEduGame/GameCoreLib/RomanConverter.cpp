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
    int second_last_value = 0;
    char last_char = '\0';
    int repeat_count = 0;

    for (size_t i = 0; i < roman.size(); ++i) {
        char current_char = roman[i];
        if (values.find(current_char) == values.end()) {
            return false;
        }

        int current_value = values[current_char];
        if (current_char == last_char) {
            repeat_count++;
            if (repeat_count > 3 || (current_char == 'V' || current_char == 'L' || current_char == 'D')) {
                return false;
            }
        } else {
            repeat_count = 1;
        }

        if (last_value < current_value) {
            if (last_value != 0 && (current_value > last_value * 10 || (last_char != 'I' && last_char != 'X' && last_char != 'C'))) {
                return false;
            }
            if (second_last_value >= current_value) {
                return false;
            }
        }

        second_last_value = last_value;
        last_char = current_char;
        last_value = current_value;
    }

    return true;
}

int RomanConverter::Roman2Dec(const std::string& roman) {
    // Sprawdzenie, czy liczba rzymska jest prawidłowa
    if (!isValidRoman(roman)) {
        return -1; // Nieprawidłowa liczba rzymska
    }

    int decimal = 0;
    int prev_value = 0;

    for (size_t i = 0; i < roman.length(); i++) {
        int current_value = roman_map.at(roman[i]);

        if (prev_value < current_value) {
            decimal += current_value - 2 * prev_value;
        }
        else {
            decimal += current_value;
        }
        prev_value = current_value;
    }

    // Sprawdzenie, czy liczba nie przekracza maksymalnej wartości dla systemu rzymskiego
    if (decimal > 3999) {
        return -2; // Liczba przekracza maksymalną wartość
    }

    return decimal;
}


