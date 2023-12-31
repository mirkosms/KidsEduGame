#include "GameGUI.h"
#include <QtWidgets/QApplication>
#include <iostream>
#include <filesystem> // C++17
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    std::cout << "Current working directory: " << std::filesystem::current_path() << std::endl;
    // Reszta kodu...
    GameGUI w;
    w.show();
    return a.exec();
}
