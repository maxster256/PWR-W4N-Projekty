#include <iostream>
#include "Menu.h"
#include "Options.h"

int option = -1;

void Menu::init_menu(){
    std::cout << "#################################################################\n";
    std::cout << "                      AiZO - projekt 2\nBadanie efektywnosci algorytmow grafowych";
    std::cout << "w zaleznosci od rozmiaru\n       oraz sposobu reprezentacji grafu w pamieci komputera\n";
    std::cout << "#################################################################\n";
    menu_options();
}
bool Menu::option_menu(){
    std::cout << "Wybierz jedna z opcji:\n(1) Wczytanie struktury grafu z pliku .txt\n(2) Losowe wygenerowanie grafu\n(3) Wyswietlenie wygenerowanego grafu w formie macierzowej i listowej\n(4) Uruchomienie wybranego algorytmu na grafie\n\n(0) Wyjscie z programu\n";
    option = inputLoop(0, 4);
    if (option == 0)   {return false;}
    return true;
}
void Menu::menu_options(){
    Options choosenOption;
    while(true){
        if(!option_menu()) {break;}
        switch(option){
            case 1: choosenOption.load_graph(); break;
            case 2: choosenOption.generate_graph(); break;
            case 3: choosenOption.show_graph(); break;
            case 4: choosenOption.choose_algorithm(); break;
            default: break;
        }
        system("PAUSE");
        system("CLS");
    }
}
