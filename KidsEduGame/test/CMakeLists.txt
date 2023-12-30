cmake_minimum_required(VERSION 3.14)
project(GameTests)

# Ustawienie standardu C++
set(CMAKE_CXX_STANDARD 17)

# Znalezienie i dołączenie Google Test
set(GTest_DIR "C:/vcpkg/vcpkg-master/installed/x64-windows/share/gtest")
find_package(GTest CONFIG REQUIRED)

# Dołączanie katalogów z nagłówkami
include_directories(../include)

# Dodanie plików źródłowych
set(TEST_SOURCES test.cpp ../GameCoreLib/Dec2Roman.cpp)

# Dodanie celu wykonawczego
add_executable(GameTests ${TEST_SOURCES})


# Linkowanie z Google Test i głównym projektem
target_link_libraries(GameTests PRIVATE GTest::gtest GTest::gtest_main)
target_include_directories(GameTests PRIVATE ../include)


# Dodanie testów do CTest
enable_testing()
add_test(NAME GameTests COMMAND GameTests)
