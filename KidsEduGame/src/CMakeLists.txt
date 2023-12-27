cmake_minimum_required(VERSION 3.14)
project(RomanDigitalsToDecimal)

# Ustawienie standardu C++
set(CMAKE_CXX_STANDARD 17)

# Dołączanie katalogów z nagłówkami (jeśli są)
include_directories(include)

# Dodanie plików źródłowych
add_executable(RomanDigitalsToDecimal RomanDigitalsToDecimal.cpp)


# Linkowanie z zależnościami (jeśli jakieś są)
# target_link_libraries(RomanDigitalsToDecimal PRIVATE some_library)
