cmake_minimum_required(VERSION 3.14)
project(KidsEduGame)

# Ustawienie standardu C++
set(CMAKE_CXX_STANDARD 17)

# Dodaj podprojekty
add_subdirectory(GameCoreLib)
add_subdirectory(src)
add_subdirectory(GameGUI)
add_subdirectory(test)

# Kopiowanie plików danych do katalogu binarnego przy każdej konfiguracji
foreach(config IN LISTS CMAKE_CONFIGURATION_TYPES)
    file(COPY ${CMAKE_SOURCE_DIR}/build/GameGUI/data/general_facts.txt
         DESTINATION ${CMAKE_BINARY_DIR}/${config}/GameGUI)
    file(COPY ${CMAKE_SOURCE_DIR}/build/GameGUI/data/roman_numeral_facts.txt
         DESTINATION ${CMAKE_BINARY_DIR}/${config}/GameGUI)
endforeach()

