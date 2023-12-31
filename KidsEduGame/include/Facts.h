#ifndef FACTS_H
#define FACTS_H

#include <vector>
#include <string>

class Facts {
public:
    Facts();
    std::string getRandomGeneralFact();
    std::string getRandomRomanNumeralFact();
    void resetFactsDisplayStatus();
    bool allFactsDisplayed() const;

private:
    void loadFactsFromFile(const std::string& filePath, std::vector<std::string>& facts);
    std::vector<std::string> generalFacts;
    std::vector<std::string> romanNumeralFacts;
    mutable std::vector<bool> generalFactsDisplayed;
    mutable std::vector<bool> romanNumeralFactsDisplayed;
};

#endif // FACTS_H
