cmake_minimum_required(VERSION 3.14)
project(GameCore)

# Ustawienie standardu C++
set(CMAKE_CXX_STANDARD 17)

# Dołączanie katalogów z nagłówkami
include_directories(../include)

# Dodanie plików źródłowych
set(SOURCE_FILES GameCore.cpp Dec2Roman.cpp)

# Dodanie celu wykonawczego
add_executable(GameCore ${SOURCE_FILES})

# Linkowanie z zależnościami (jeśli jakieś są)
# target_link_libraries(GameCore PRIVATE some_library)
