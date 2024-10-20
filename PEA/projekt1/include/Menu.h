#ifndef MENU_H
#define MENU_H

#include "Options.h"

class Menu
{
    public:
        int option;
        Input inputC;

        void init_menu();
        bool option_menu();
        void menu_options();

    protected:

    private:
};

#endif // MENU_H
