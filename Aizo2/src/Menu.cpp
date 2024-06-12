#include "Menu.h"

void Menu::init_menu(){
    std::cout << "#################################################################\n";
    std::cout << "                      AiZO - projekt 2\nBadanie efektywnosci algorytmow grafowych";
    std::cout << "w zaleznosci od rozmiaru\n       oraz sposobu reprezentacji grafu w pamieci komputera\n";
    std::cout << "#################################################################\n";
    menu_options();
}
bool Menu::option_menu(){
    std::cout << "Wybierz jedna z opcji:\n(1) Wczytanie struktury grafu z pliku .txt\n(2) Losowe wygenerowanie grafu\n(3) Wyswietlenie wygenerowanego grafu w formie macierzowej i listowej\n(4) Uruchomienie wybranego algorytmu na grafie\n(5) Wykonanie serii badan dla rozpatrywanego problemu\n\n(0) Wyjscie z programu\n";
    option = inputLoop(0, 5);
    if (option == 0)   {return false;}
    return true;
}
bool Menu::choose_problem(){
    std::cout << "Wybierz rodzaj problemu do zbadania:\n(1) Wyznaczanie minimalnego drzewa rozpinajacego\n(2) Wyznaczanie najkrotszej sciezki w grafie\n\n(0) Wyjscie z programu\n";
    problem = inputLoop(0,2);
    if (problem == 0){
            return false;
    }
    return true;
}
void Menu::menu_options(){
    Options choosenOption;

    if(!choose_problem()){
            return;
    }
    system("CLS");
    while(true){
        if(!option_menu()) {break;}
        choosenOption.problem_type = problem;
        switch(option){
            case 1: if(!choosenOption.load_graph()){return;} break;
            case 2: choosenOption.generate_graph_info(); break;
            case 3: choosenOption.show_graph(); break;
            case 4: choosenOption.choose_algorithm_info(true);
                    choosenOption.choose_algorithm(true); break;
            case 5: choosenOption.serie(); break;
            default: break;
        }
        system("PAUSE");
        system("CLS");
    }
}
