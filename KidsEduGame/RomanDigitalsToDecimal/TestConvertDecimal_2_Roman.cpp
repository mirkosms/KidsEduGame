#include <gtest/gtest.h>
#include "Dec2Roman.h" 

TEST(TestConvertDecimal_2_Roman, TestValidDecimalNumbers) {
    EXPECT_EQ(ConvertDecimal_2_Roman(1), "I");
    EXPECT_EQ(ConvertDecimal_2_Roman(4), "IV");
    EXPECT_EQ(ConvertDecimal_2_Roman(9), "IX");
    EXPECT_EQ(ConvertDecimal_2_Roman(58), "LVIII");
    EXPECT_EQ(ConvertDecimal_2_Roman(1994), "MCMXCIV");
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
