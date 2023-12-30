#include "RomanConverter.h"
#include <string>
#include <limits>

RomanConverter::RomanConverter()
    : roman_map{ {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000} },
    valid_subtractors("IXC"),
    non_repeatable("VLD") {
}

bool RomanConverter::isValidRoman(const std::string& roman) {
    // Używamy std:: przed nazwami z biblioteki standardowej
    for (size_t i = 0; i < roman.length(); i++) {
        if (roman_map[roman[i]] < roman_map[roman[i + 1]]) {
            if (valid_subtractors.find(roman[i]) == std::string::npos || roman_map[roman[i]] * 10 < roman_map[roman[i + 1]]) {
                return false;
            }
            if (i + 2 < roman.length() && roman_map[roman[i + 1]] <= roman_map[roman[i + 2]]) {
                return false;
            }
        }
        if (i + 3 < roman.length() && roman[i] == roman[i + 1] && roman[i + 1] == roman[i + 2] && roman[i + 2] == roman[i + 3]) {
            return false;
        }
        if (non_repeatable.find(roman[i]) != std::string::npos && i + 1 < roman.length() && roman[i] == roman[i + 1]) {
            return false;
        }
    }
    return true;
}

int RomanConverter::Roman2Dec(const std::string& roman) {
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
