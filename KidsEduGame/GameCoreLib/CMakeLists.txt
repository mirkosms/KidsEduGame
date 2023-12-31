cmake_minimum_required(VERSION 3.14)
project(GameCoreLib)

# Ustawienie standardu C++
set(CMAKE_CXX_STANDARD 17)

# Dodanie plików źródłowych biblioteki
add_library(GameCoreLib
    Dec2Roman.cpp
    RomanConverter.cpp
    Quiz.cpp
    Menu.cpp
    Facts.cpp
)

# Ustawienie ścieżek do plików nagłówkowych
target_include_directories(GameCoreLib PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/../include
    ${CMAKE_CURRENT_SOURCE_DIR}/../GameGUI
)