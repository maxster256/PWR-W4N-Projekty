#ifndef MENU_H
#define MENU_H
#include "Input.h"

class Menu : public Input{
public:
    int option = -1;
    void init_menu();
private:
    bool option_menu();
    void menu_options();
};

#endif // MENU_H
