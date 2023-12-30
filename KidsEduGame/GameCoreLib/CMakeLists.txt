add_library(GameCoreLib
    Dec2Roman.cpp
    RomanConverter.cpp
    Quiz.cpp 
    Menu.cpp 
    Facts.cpp
)
include_directories(../include ../GameGUI)

target_include_directories(GameCoreLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
