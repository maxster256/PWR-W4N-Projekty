#include "Input.h"

int Input::inputLoop(int minimum, int maksimum){
    int x;
    // powtarzanie petli jesli x nie poza podanym zakresem lub nie jest liczba calkowita int
    while(!(std::cin >> x) || x < minimum || x > maksimum){
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        printf("Nalezy podac cyfre z zakresu (%d) - (%d):\n",minimum,maksimum);
    }
    return x;
}
