
#include "RomanConverter.h"
#include <map>
#include <string>

RomanConverter::RomanConverter()
    : roman_map{ {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000} } {
}

bool RomanConverter::isValidRoman(const std::string& roman) {
    std::map<char, int> values = { {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000} };
    std::map<char, int> max_repeat = { {'I', 3}, {'X', 3}, {'C', 3}, {'M', 3}, {'V', 1}, {'L', 1}, {'D', 1} };
    std::map<char, std::string> valid_subtractions = { {'I', "VX"}, {'X', "LC"}, {'C', "DM"} };

    int last_value = 0;
    char last_char = ' ';
    int repeat_count = 0;

    for (const char& c : roman) {
        // Check for valid Roman numeral
        if (values.find(c) == values.end()) return false;

        // Check for valid subtraction
        if (last_value < values[c] &&
            (valid_subtractions.find(last_char) == valid_subtractions.end() ||
                valid_subtractions[last_char].find(c) == std::string::npos)) return false;

        // Check for repeats
        if (last_char == c) {
            repeat_count++;
            if (repeat_count > max_repeat[c]) return false;
        }
        else {
            repeat_count = 1;
        }

        last_char = c;
        last_value = values[c];
    }

    return true;
}

int RomanConverter::Roman2Dec(const std::string& roman) {
    if (!isValidRoman(roman)) {
        return -1;
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

    return decimal;
}
