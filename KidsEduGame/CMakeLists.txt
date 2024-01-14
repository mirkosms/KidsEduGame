cmake_minimum_required(VERSION 3.14)
project(KidsEduGame)

# Ustawienie standardu C++
set(CMAKE_CXX_STANDARD 17)

# Ustawienie katalogu wyjściowego dla plików wykonywalnych
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Dodaj podprojekty
add_subdirectory(GameCoreLib)
add_subdirectory(src)
add_subdirectory(GameGUI)

# Włączenie testowania i dodanie katalogu z testami
enable_testing()
add_subdirectory(test)

# Kopiowanie plików danych do katalogu binarnego przy każdej konfiguracji
foreach(config IN LISTS CMAKE_CONFIGURATION_TYPES)
    file(COPY ${CMAKE_SOURCE_DIR}/data/
         DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${config}/data)
endforeach()

