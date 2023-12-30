#include "Facts.h"
#include <algorithm>
#include <random>
#include <chrono>

Facts::Facts() {
    generalFacts = {
        "Słowo 'hundred' pochodzi od staronordyjskiego słowa 'hundrath', które oznacza 120, a nie 100.",
        "Pierwiastek kwadratowy z 2 (1.41) jest znany jako stala Pitagorasa.",
        "Zero jest jedyna liczba, ktora nie moze byc reprezentowana w systemie rzymskim."
    };
    romanNumeralFacts = {
        "Historia liczb rzymskich: Liczby rzymskie pochodzą z starożytnego Rzymu i były powszechnie używane do zapisywania liczb w Europie aż do późnego średniowiecza.",
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
        // Sprawdzamy, czy wszystkie ciekawostki zostały wyświetlone
        if (std::all_of(generalFactsDisplayed.begin(), generalFactsDisplayed.end(), [](bool v) { return v; })) {
            std::fill(generalFactsDisplayed.begin(), generalFactsDisplayed.end(), false); // Resetuj stan wyświetlania
        }
    }
    generalFactsDisplayed[index] = true;
    return generalFacts[index];
}

std::string Facts::getRandomRomanNumeralFact() {
    static std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<std::size_t> dist(0, romanNumeralFacts.size() - 1);

    std::size_t index;
    for (index = dist(rng); romanNumeralFactsDisplayed[index]; index = dist(rng)) {
        // Sprawdzamy, czy wszystkie ciekawostki zostały wyświetlone
        if (std::all_of(romanNumeralFactsDisplayed.begin(), romanNumeralFactsDisplayed.end(), [](bool v) { return v; })) {
            std::fill(romanNumeralFactsDisplayed.begin(), romanNumeralFactsDisplayed.end(), false); // Resetuj stan wyświetlania
            break; // Opcjonalnie, możemy wyjść z pętli, jeśli wszystkie fakty zostały zresetowane
        }
    }
    romanNumeralFactsDisplayed[index] = true;
    return romanNumeralFacts[index];
}



bool Facts::allFactsDisplayed() const {
    return std::all_of(generalFactsDisplayed.begin(), generalFactsDisplayed.end(), [](bool v) { return v; }) &&
        std::all_of(romanNumeralFactsDisplayed.begin(), romanNumeralFactsDisplayed.end(), [](bool v) { return v; });
}

void Facts::resetFactsDisplayStatus() {
    // Resetuje stan wyświetlania dla wszystkich ciekawostek
    std::fill(generalFactsDisplayed.begin(), generalFactsDisplayed.end(), false);
    std::fill(romanNumeralFactsDisplayed.begin(), romanNumeralFactsDisplayed.end(), false);
}