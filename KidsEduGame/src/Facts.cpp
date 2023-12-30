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
    generalFactsDisplayed.resize(generalFacts.size(), false);
    romanNumeralFactsDisplayed.resize(romanNumeralFacts.size(), false);
}

std::string Facts::getRandomGeneralFact() {
    static std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<std::size_t> dist(0, generalFacts.size() - 1);

    std::size_t index;
    for (index = dist(rng); generalFactsDisplayed[index]; index = dist(rng)) {
        // Sprawdzamy, czy wszystkie ciekawostki zosta³y wyœwietlone
        if (std::all_of(generalFactsDisplayed.begin(), generalFactsDisplayed.end(), [](bool v) { return v; })) {
            std::fill(generalFactsDisplayed.begin(), generalFactsDisplayed.end(), false); // Resetuj stan wyœwietlania
        }
    }
    generalFactsDisplayed[index] = true;
    return generalFacts[index];
}

std::string Facts::getRandomRomanNumeralFact() {
    static std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<std::size_t> dist(0, romanNumeralFacts.size() - 1);

    // Jeœli wszystkie ciekawostki zosta³y wyœwietlone, zresetuj stan
    if (allFactsDisplayed()) {
        resetFactsDisplayStatus();
    }

    std::size_t index = dist(rng);
    // Jeœli wylosowany fakt zosta³ ju¿ wyœwietlony, losuj ponownie
    while (romanNumeralFactsDisplayed[index]) {
        index = dist(rng);
    }

    romanNumeralFactsDisplayed[index] = true;  // Oznacz fakt jako wyœwietlony
    return romanNumeralFacts[index];
}


bool Facts::allFactsDisplayed() const {
    return std::all_of(generalFactsDisplayed.begin(), generalFactsDisplayed.end(), [](bool v) { return v; }) &&
        std::all_of(romanNumeralFactsDisplayed.begin(), romanNumeralFactsDisplayed.end(), [](bool v) { return v; });
}

void Facts::resetFactsDisplayStatus() {
    // Resetuje stan wyœwietlania dla wszystkich ciekawostek
    std::fill(generalFactsDisplayed.begin(), generalFactsDisplayed.end(), false);
    std::fill(romanNumeralFactsDisplayed.begin(), romanNumeralFactsDisplayed.end(), false);
}