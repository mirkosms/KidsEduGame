#include "Facts.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <random>
#include <chrono>
#include <iostream>

Facts::Facts() {
    // Zakładając, że plik wykonywalny znajduje się w Debug/GameGUI lub Release/GameGUI
    // i że folder data jest w tym samym katalogu co plik wykonywalny.
    std::string baseDir = "./"; // Dla ścieżki bezwzględnej od miejsca pliku wykonywalnego

    std::string generalFactsPath = baseDir + "data/general_facts.txt";
    std::string romanNumeralFactsPath = baseDir + "data/roman_numeral_facts.txt";

    try {
        loadFactsFromFile(generalFactsPath, generalFacts);
        loadFactsFromFile(romanNumeralFactsPath, romanNumeralFacts);
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Blad podczas ladowania ciekawostek: " << e.what() << std::endl;
    }

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

void Facts::loadFactsFromFile(const std::string& filePath, std::vector<std::string>& facts) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        throw std::runtime_error("Unable to open file: " + filePath);
    }
    std::string line;
    while (std::getline(file, line)) {
        if (!line.empty()) {
            facts.push_back(line);
        }
    }
}