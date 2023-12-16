// RomanDigitalsToDecimal.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

//#include <iostream>
//#include <map>
//#include <vector>
//#include <algorithm>
//#include <cctype>
//
//std::map<char, int> roman = { {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000} };
//
//int romanToDecimal(std::string str) {
//    int result = 0;
//    for (int i = 0; i < str.length(); i++) {
//        if (i + 1 < str.length() && roman[toupper(str[i])] < roman[toupper(str[i + 1])]) {
//            result -= roman[toupper(str[i])];
//        }
//        else {
//            result += roman[toupper(str[i])];
//        }
//    }
//    return result;
//}
//
//std::string decimalToRoman(int num) {
//    std::string str;
//    std::vector<std::pair<int, std::string>> value = { {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"} };
//    for (auto& pair : value) {
//        while (num >= pair.first) {
//            num -= pair.first;
//            str += pair.second;
//        }
//    }
//    return str;
//}
//
//int main() {
//    std::string r;
//    std::cout << "Enter a Roman numeral: ";
//    std::cin >> r;
//    std::cout << "Decimal: " << romanToDecimal(r) << std::endl;
//
//    int d;
//    std::cout << "Enter a decimal number: ";
//    std::cin >> d;
//    std::cout << "Roman: " << decimalToRoman(d) << std::endl;
//
//    return 0;
//}


//#include <iostream>
//#include <vector>
//#include <string>
//#include <map>
//
//using namespace std;
//
//int Roman2Dec(string roman) {
//    map<char, int> roman_map = { {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000} };
//    int decimal = 0;
//    int prev = 0;
//
//    for (int i = roman.length() - 1; i >= 0; --i) {
//        if (roman_map[roman[i]] >= prev)
//            decimal += roman_map[roman[i]];  // sum the value if it's greater or equal to the previous value
//        else
//            decimal -= roman_map[roman[i]];  // subtract the value if it's less than the previous value
//
//        prev = roman_map[roman[i]];
//    }
//
//    return decimal;
//}
//
//int main() {
//    string roman;
//    cout << "Podaj liczbę rzymską: ";
//    cin >> roman;
//    cout << "Liczba dziesiętna: " << Roman2Dec(roman) << endl;
//    return 0;
//}


#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "Dec2Roman.h" 

using namespace std;

bool isValidRoman(string roman) {
    map<char, int> roman_map = { {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000} };
    string valid_subtractors = "IXC";
    string non_repeatable = "VLD";
    for (int i = 0; i < roman.length(); i++) {
        if (roman_map[roman[i]] < roman_map[roman[i + 1]]) {
            if (valid_subtractors.find(roman[i]) == string::npos || roman_map[roman[i]] * 10 < roman_map[roman[i + 1]]) {
                return false;
            }
            if (i + 2 < roman.length() && roman_map[roman[i + 1]] <= roman_map[roman[i + 2]]) {
                return false;
            }
        }
        if (i + 3 < roman.length() && roman[i] == roman[i + 1] && roman[i + 1] == roman[i + 2] && roman[i + 2] == roman[i + 3]) {
            return false;
        }
        if (non_repeatable.find(roman[i]) != string::npos && i + 1 < roman.length() && roman[i] == roman[i + 1]) {
            return false;
        }
    }
    return true;
}

int Roman2Dec(string roman) {
    if (!isValidRoman(roman)) {
        cout << "Nieprawidlowa liczba rzymska" << endl;
        return -1;
    }

    map<char, int> roman_map = { {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000} };
    int decimal = 0;
    int prev = 0;

    for (int i = roman.length() - 1; i >= 0; --i) {
        if (roman_map[roman[i]] >= prev)
            decimal += roman_map[roman[i]]; 
        else
            decimal -= roman_map[roman[i]];  

        prev = roman_map[roman[i]];
    }

    return decimal;
}

void interestingFacts() {
    cout << "Ciekawostka: Slowo \"hundred\" pochodzi od staronordyjskiego slowa \"hundrath\", ktore oznacza 120, a nie 100." << endl;
    cout << "Ciekawostka: Pierwiastek kwadratowy z 2 (1.41) jest znany jako stala Pitagorasa." << endl;
    cout << "Ciekawostka: Zero jest jedyna liczba, ktora nie moze byc reprezentowana w systemie rzymskim." << endl;
}

void historyOfRomanNumerals() {
    cout << "Historia liczb rzymskich: Liczby rzymskie pochodza z starozytnego Rzymu i byly powszechnie uzywane do zapisywania liczb w Europie az do poznego sredniowiecza." << endl;
    cout << "Historia liczb rzymskich: Uzycie liczb rzymskich trwalo dlugo po upadku Cesarstwa Rzymskiego. Od XIV wieku liczby rzymskie zaczely byc zastepowane przez liczby arabskie." << endl;
    cout << "Historia liczb rzymskich: Mimo to, liczby rzymskie sa nadal uzywane w niektorych zastosowaniach do dnia dzisiejszego, na przyklad na tarczach zegarow." << endl;
}


void quiz() {
    srand(time(0)); // inicjalizacja generatora liczb losowych
    map<int, string> questions = {
        {1, "I"}, {4, "IV"}, {9, "IX"}, {58, "LVIII"}, {1994, "MCMXCIV"},
        {3, "III"}, {20, "XX"}, {90, "XC"} // dodatkowe pytania
    }; // możesz dodać więcej pytań

    for (const auto& [dec, roman] : questions) {
        string userAnswer;
        int questionType = rand() % 2; // losowo wybiera typ pytania

        if (questionType == 0) {
            cout << "Jaka jest liczba rzymska dla " << dec << "? ";
            cin >> userAnswer;
            if (userAnswer == roman) {
                cout << "Poprawna odpowiedz!\n";
            }
            else {
                cout << "Nieprawidlowa odpowiedź. Poprawna odpowiedz to: " << roman << "\n";
            }
        }
        else {
            cout << "Jaka jest liczba dziesietna dla '" << roman << "'? ";
            int userIntAnswer;
            cin >> userIntAnswer;
            if (userIntAnswer == dec) {
                cout << "Poprawna odpowiedz!\n";
            }
            else {
                cout << "Nieprawidlowa odpowiedz. Poprawna odpowiedz to: " << dec << "\n";
            }
        }
    }
}


void menu() {
    while (true) {
        cout << endl;
        cout << "\nMenu:\n";
        cout << "1. Konwersja liczb rzymskich na dziesietne\n";
        cout << "2. Konwersja liczb dziesietnych na rzymskie\n";
        cout << "3. Quiz\n";
        cout << "4. Ciekawostki o liczbach i ich konwersjach\n";
        cout << "5. Historia liczb rzymskich\n";
        cout << "6. Zakoncz\n";
        cout << "Wybierz opcje: ";
        
        int option;
        cin >> option;
        cout << endl;

        switch (option) {
        case 1: {
            string roman;
            cout << "Podaj liczbe rzymska: ";
            cin >> roman;
            int decimal = Roman2Dec(roman);
            if (decimal != -1) {
                cout << "Liczba dziesietna: " << decimal << endl;
            }
            break;
        }
        case 2: {
            int decimal;
            cout << "Podaj liczbe dziesietna: ";
            cin >> decimal;
            string roman = ConvertDecimal_2_Roman(decimal);
            cout << "Liczba rzymska: " << roman << endl;
            break;
        }
        case 3:
            quiz();
            break;
        case 4:
            interestingFacts();
            break;
        case 5:
            historyOfRomanNumerals();
            break;
        case 6:
            return;
        default:
            cout << "Nieprawidłowa opcja. Spróbuj ponownie.\n";
        }
    }
}

int main() {
    menu();
    return 0;
}

