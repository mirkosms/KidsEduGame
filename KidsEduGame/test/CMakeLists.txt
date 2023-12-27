cmake_minimum_required(VERSION 3.14)
project(TestForRoman2Decimal)

# Ustawienie standardu C++
set(CMAKE_CXX_STANDARD 17)

# Znalezienie i dołączenie Google Test
find_package(GTest CONFIG REQUIRED)

# Dołączanie katalogów z nagłówkami
include_directories(../include)

# Dodanie plików źródłowych dla testów
add_executable(TestForRoman2Decimal test.cpp)


# Linkowanie z Google Test i głównym projektem
target_link_libraries(TestForRoman2Decimal PRIVATE GTest::gtest GTest::gtest_main)

# Dodanie testów do CTest
enable_testing()
add_test(NAME TestForRoman2Decimal COMMAND TestForRoman2Decimal)
