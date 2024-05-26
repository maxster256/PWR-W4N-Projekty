#include <iostream>
#include "Options.h"

bool isGenerated = false;
short algorithm_type = -1;
short algorithm = -1;

void Options::load_graph(){


    isGenerated = true;
}
void Options::generate_graph(){


    isGenerated = true;
}
void Options::show_graph(){
    if(!isGenerated){std::cout << "Operacja niemozliwa! Graf nie zostal jeszcze utworzony.\n";}

}
void Options::choose_algorithm(){
    if(!isGenerated){std::cout << "Operacja niemozliwa! Graf nie zostal jeszcze utworzony.\n";}
    std::cout << "Wybierz rodzaj algorytmu:\n(1) Wyznaczanie minimalnego drzewa rozpinajacego\n(2) Wyznaczanie najkrotszej sciezki w grafie\n(3) Wyznaczanie maksymalnego przeplywu (algorytm Forda-Fulkersona)\n";
    algorithm_type = inputLoop(1,3);
    if(algorithm_type != 3){
        std::cout << "Wybierz algorytm:\n";
        if(algorithm_type == 1){
            std::cout << "(1) Algorytm Prima\n(2) Algorytm Kruskala\n";
            algorithm = inputLoop(1,2);
        }
        else{
            std::cout << "(1) Algorytm Dijkstry\n(2) Algorytm Forda-Bellmana\n";
            algorithm = inputLoop(1,2);
        }
    }
}
