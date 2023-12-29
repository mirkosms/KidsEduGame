#ifndef MENU_H
#define MENU_H

#include "RomanConverter.h"
#include "Facts.h"
#include "Quiz.h"
#include "Dec2Roman.h"

class Menu {
private:
    RomanConverter converter;
    Quiz quiz;
    Facts facts;

public:
    void start();
};

#endif // MENU_H
