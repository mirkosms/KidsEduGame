cmake_minimum_required(VERSION 3.14)
project(GameCore)

# Ustawienie standardu C++
set(CMAKE_CXX_STANDARD 17)

# Dodanie pliku źródłowego aplikacji konsolowej
add_executable(GameCore main_console.cpp)

# Linkowanie z biblioteką GameCoreLib
target_link_libraries(GameCore GameCoreLib)

# Upewnij się, że katalog include jest dostępny
target_include_directories(GameCore PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)
