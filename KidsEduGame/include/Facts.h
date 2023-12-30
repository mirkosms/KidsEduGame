#ifndef FACTS_H
#define FACTS_H

#include <string>
#include <vector>

class Facts {
private:
    std::vector<std::string> generalFacts;
    std::vector<std::string> romanNumeralFacts;
    mutable std::vector<bool> factsDisplayed;

public:
    Facts();

    std::string getRandomGeneralFact() const;
    std::string getRandomRomanNumeralFact() const;
};

#endif // FACTS_H
