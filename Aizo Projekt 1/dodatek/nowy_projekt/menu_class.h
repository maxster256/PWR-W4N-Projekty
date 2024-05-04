#ifndef MENU_CLASS_H_INCLUDED
#define MENU_CLASS_H_INCLUDED

#include "input_class.h"
#include "options_class.h"

//klasa menu - warstwa pierwsza menu programu do wyboru typu danych
class menu : public Input{
private:
    void chooseDataType(){
        std::cout << "######################################################\n           AiZO - zadanie projektowe nr. 1\n\n";
        std::cout << "      Badanie efektywnosci wybranych algorytmow\n   sortowania ze wzgledu na zlozonosc obliczeniowa\n";
        std::cout << "######################################################\n";
        std::cout << "\nStworzony program pozwala na wykonanie roznych sposobow sortownia\nna ponizej pzedstawionych typach danych. W celu wybrania\ndanego typu danych nalezy podac odpowiednia cyfre:\n";
        std::cout << "\n(1) Int\n(2) Float\n(3) Double\n\n(0) Wyjscie z programu\n";
        data_type = inputLoop(0, 3);
        if (data_type == 0)  {return;}
        system("CLS");
    }
public:
    Operations<int> ints;
    Operations<float> floats;
    Operations<double> doubles;
    int data_type = 0;

    void init_programme(){
        chooseDataType();
        switch(data_type){
            case 1: ints.options(); break;
            case 2: floats.options(); break;
            case 3: doubles.options(); break;
            default: break;
        }
    }
};

#endif // MENU_CLASS_H_INCLUDED
