cmake_minimum_required(VERSION 3.14)
project(KidsEduGame)

# Ustawienie standardu C++
set(CMAKE_CXX_STANDARD 17)

# Dodaj podprojekty
add_subdirectory(GameCoreLib)
add_subdirectory(src)
add_subdirectory(GameGUI)
add_subdirectory(test)
