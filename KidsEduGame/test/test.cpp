//#include "pch.h"
#include <gtest/gtest.h>
#include <Dec2Roman.h>
TEST(TestConvertDecimal_2_Roman, TestValidDecimalNumbers) {
    EXPECT_EQ(ConvertDecimal_2_Roman(1), "I");
    EXPECT_EQ(ConvertDecimal_2_Roman(4), "IV");
    EXPECT_EQ(ConvertDecimal_2_Roman(9), "IX");
    EXPECT_EQ(ConvertDecimal_2_Roman(58), "LVIII");
    EXPECT_EQ(ConvertDecimal_2_Roman(1994), "MCMXCIV");
    EXPECT_EQ(ConvertDecimal_2_Roman(3), "III"); // liczby rzymskie z powtarzajacymi sie symbolami
    EXPECT_EQ(ConvertDecimal_2_Roman(20), "XX"); // liczby rzymskie z powtarzajacymi sie symbolami
    EXPECT_EQ(ConvertDecimal_2_Roman(90), "XC"); // liczby rzymskie z symbolami odejmowania
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}