#include "Menu.h"

void Menu::init_menu(){
    std::cout << "#################################################################\n";
    std::cout << "                      PEA - projekt 1\n                  Badanie problemu TSP\n";
    std::cout << "#################################################################\n";
    menu_options();
}
bool Menu::option_menu(){
    std::cout << "Wybierz jedna z opcji:\n(1) Wczytanie struktury macierzy z pliku\n(2) Losowe wygenerowanie macierzy\n(3) Wyswietlenie ostatnio zapisanej macierzy\n(4) Uruchomienie wybranego algorytmu\n(5) Wykonanie serii badan dla rozpatrywanego problemu\n\n(0) Wyjscie z programu\n";
    option = inputC.inputLoop(0, 5);
    if (option == 0)   {return false;}
    return true;
}

void Menu::menu_options(){
    while(true){
        Options choosenOption;
        while(true){
            if(!option_menu()) {return;}
            switch(option){
                case 1: if(!choosenOption.load_graph()){return;} break;
                case 2: choosenOption.generate_graph_info(); break;
                case 3: choosenOption.show_graph(); break;
                case 4: if(choosenOption.choose_algorithm_info(true)){
                            choosenOption.choose_algorithm(true);
                        } break;
                case 5: choosenOption.serie(); break;
                default: break;
            }
            system("PAUSE");
            system("CLS");
        }
        system("CLS");
    }
}
