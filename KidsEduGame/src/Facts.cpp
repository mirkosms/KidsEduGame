#include "Facts.h"
#include <algorithm>
#include <random>
#include <chrono>

Facts::Facts() {
    generalFacts = {
        "S³owo 'hundred' pochodzi od staronordyjskiego s³owa 'hundrath', które oznacza 120, a nie 100.",
        "Pierwiastek kwadratowy z 2 (1.41) jest znany jako stala Pitagorasa.",
        "Zero jest jedyna liczba, ktora nie moze byc reprezentowana w systemie rzymskim."
    };
    romanNumeralFacts = {
        "Historia liczb rzymskich: Liczby rzymskie pochodz¹ z staro¿ytnego Rzymu i by³y powszechnie u¿ywane do zapisywania liczb w Europie a¿ do póŸnego œredniowiecza.",
        "Uzycie liczb rzymskich trwalo dlugo po upadku Cesarstwa Rzymskiego. Od XIV wieku liczby rzymskie zaczely byc zastepowane przez liczby arabskie.",
        "Liczby rzymskie sa nadal uzywane w niektorych zastosowaniach do dnia dzisiejszego, na przyklad na tarczach zegarow."
    };
    factsDisplayed.resize(generalFacts.size() + romanNumeralFacts.size(), false);
}

std::string Facts::getRandomGeneralFact() const {
    static std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<std::size_t> dist(0, generalFacts.size() - 1);

    std::size_t index;
    do {
        index = dist(rng);
    } while (factsDisplayed[index]);
    factsDisplayed[index] = true;

    return generalFacts[index];
}

std::string Facts::getRandomRomanNumeralFact() const {
    static std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<std::size_t> dist(0, romanNumeralFacts.size() - 1);

    std::size_t index = romanNumeralFacts.size();
    do {
        index = dist(rng) + generalFacts.size(); // Offset by the size of the first facts array
    } while (factsDisplayed[index]);
    factsDisplayed[index] = true;

    return romanNumeralFacts[index - generalFacts.size()];
}
