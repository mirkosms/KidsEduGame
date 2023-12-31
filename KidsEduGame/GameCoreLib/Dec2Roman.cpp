#include <iostream>
#include <vector>
#include <string>
#include "Dec2Roman.h"

std::string ConvertDecimal_2_Roman(int in_dec_num) {
    if (in_dec_num <= 0 || in_dec_num > 3999) {
        return "N/D"; // Komunikat dla liczb poza zakresem 1-3999
    }

    const std::vector<std::pair<int, std::string>> RomanValueTranslator = {
        {1000, "M"}, {900, "CM"},
        {500, "D"}, {400, "CD"},
        {100, "C"}, {90, "XC"},
        {50, "L"}, {40, "XL"},
        {10, "X"}, {9, "IX"},
        {5, "V"}, {4, "IV"},
        {1, "I"}
    };

    std::string outStr = "";
    // Traverse all pairs [val, str], starting from the largest val
    for (const auto& [val, str] : RomanValueTranslator) {
        while (in_dec_num >= val) { // iterate subtracting the largest possible value
            outStr += str;
            in_dec_num -= val;
        }
    }

    return outStr;
}
