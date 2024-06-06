#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <cstdlib>
#include "Input.h"
#include "Options.h"

class Menu : public Input{
public:
    int option = -1;
    int problem = -1;
    void init_menu();
private:
    bool option_menu();
    bool choose_problem();
    void menu_options();
};

#endif // MENU_H
