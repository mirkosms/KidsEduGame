cmake_minimum_required(VERSION 3.14)
project(GameGUI)

# Ustawienie standardu C++
set(CMAKE_CXX_STANDARD 17)

# Ustawienie automatycznego przetwarzania plików MOC, UI, i QRC
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# Znajdowanie pakietów Qt6 wymaganych dla projektu
find_package(Qt6 COMPONENTS Core Gui Widgets SerialPort REQUIRED)

# Dodawanie katalogów z nagłówkami
include_directories(../include ../GameGUI)

# Dodawanie plików źródłowych do projektu
set(PROJECT_SOURCES 
    GameGUI.cpp
    main.cpp)

# Dodanie plików UI
set(PROJECT_UI 
    GameGUI.ui)

# Dodanie zasobów QRC
set(PROJECT_RESOURCES 
    GameGUI.qrc)

# Dodanie plików źródłowych do wykonywalnego pliku
add_executable(GameGUI ${PROJECT_SOURCES} ${PROJECT_UI} ${PROJECT_RESOURCES})

# Linkowanie projektu z bibliotekami Qt
target_link_libraries(GameGUI GameCoreLib Qt6::Core Qt6::Gui Qt6::Widgets Qt6::SerialPort)
