#include <gtest/gtest.h>
#include <Dec2Roman.h>

// Podstawowe konwersje
TEST(TestConvertDecimal_2_Roman, TestBasicConversions) {
    EXPECT_EQ(ConvertDecimal_2_Roman(1), "I");
    EXPECT_EQ(ConvertDecimal_2_Roman(5), "V");
    EXPECT_EQ(ConvertDecimal_2_Roman(10), "X");
}

// Subtrakcje
TEST(TestConvertDecimal_2_Roman, TestSubtractions) {
    EXPECT_EQ(ConvertDecimal_2_Roman(4), "IV");
    EXPECT_EQ(ConvertDecimal_2_Roman(9), "IX");
    EXPECT_EQ(ConvertDecimal_2_Roman(40), "XL");
    EXPECT_EQ(ConvertDecimal_2_Roman(90), "XC");
    EXPECT_EQ(ConvertDecimal_2_Roman(400), "CD");
    EXPECT_EQ(ConvertDecimal_2_Roman(900), "CM");
}

// Powtórzenia symboli
TEST(TestConvertDecimal_2_Roman, TestRepetitions) {
    EXPECT_EQ(ConvertDecimal_2_Roman(3), "III");
    EXPECT_EQ(ConvertDecimal_2_Roman(20), "XX");
    EXPECT_EQ(ConvertDecimal_2_Roman(300), "CCC");
}

// Kombinacje odejmowania
TEST(TestConvertDecimal_2_Roman, TestSubtractiveCombinations) {
    EXPECT_EQ(ConvertDecimal_2_Roman(58), "LVIII");
    EXPECT_EQ(ConvertDecimal_2_Roman(90), "XC");
    EXPECT_EQ(ConvertDecimal_2_Roman(1994), "MCMXCIV");
}

// Ograniczenia i nieprawid³owe kombinacje
TEST(TestConvertDecimal_2_Roman, TestInvalidCombinations) {
    EXPECT_NE(ConvertDecimal_2_Roman(0), "I"); // 0 nie jest prawid³ow¹ liczb¹ rzymsk¹
    EXPECT_NE(ConvertDecimal_2_Roman(4), "IIII"); // Nieprawid³owa repetycja
    EXPECT_NE(ConvertDecimal_2_Roman(99), "IC"); // Nieprawid³owa subtrakcja
    EXPECT_NE(ConvertDecimal_2_Roman(1114), "MCIVX"); // Nieistniej¹ca liczba
    EXPECT_NE(ConvertDecimal_2_Roman(8), "IVIV");  // Nieistniej¹ca liczba
    EXPECT_NE(ConvertDecimal_2_Roman(19), "IXX");  // Nieistniej¹ca liczba
    EXPECT_NE(ConvertDecimal_2_Roman(2700), "CMCMCM");  // Nieistniej¹ca liczba

}

// Krawêdziowe przypadki
TEST(TestConvertDecimal_2_Roman, TestEdgeCases) {
    EXPECT_EQ(ConvertDecimal_2_Roman(1), "I"); // Najni¿sza mo¿liwa liczba rzymska
    EXPECT_EQ(ConvertDecimal_2_Roman(3999), "MMMCMXCIX"); // Najwy¿sza mo¿liwa liczba rzymska
    EXPECT_EQ(ConvertDecimal_2_Roman(0), "N/D"); // Zero nie istnieje w systemie rzymskim
    EXPECT_EQ(ConvertDecimal_2_Roman(-1), "N/D"); // Ujemne liczby nie istniej¹ w systemie rzymskim
}

// Ogólne i niesprecyzowane wyj¹tki
TEST(TestConvertDecimal_2_Roman, TestGeneralAndUnspecifiedExceptions) {
    EXPECT_EQ(ConvertDecimal_2_Roman(1066), "MLXVI"); // Rok bitwy pod Hastings
    EXPECT_EQ(ConvertDecimal_2_Roman(1492), "MCDXCII"); // Rok odkrycia Ameryki przez Kolumba
    EXPECT_EQ(ConvertDecimal_2_Roman(1114), "MCXIV"); // Rok bitwy pod Martorell
    EXPECT_EQ(ConvertDecimal_2_Roman(1023), "MXXIII"); // Liczba w zakresie
    EXPECT_EQ(ConvertDecimal_2_Roman(4000), "N/D"); // Liczba poza zakresem
}


int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
