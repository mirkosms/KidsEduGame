#ifndef ROMANCONVERTER_H
#define ROMANCONVERTER_H

#include <string>
#include <map>

class RomanConverter {
public:
    RomanConverter();
    bool isValidRoman(const std::string& roman);
    int Roman2Dec(const std::string& roman);

private:
    std::map<char, int> roman_map;
    std::string valid_subtractors;
    std::string non_repeatable;
};

#endif // ROMANCONVERTER_H
