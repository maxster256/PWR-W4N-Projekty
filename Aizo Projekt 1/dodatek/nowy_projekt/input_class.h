#ifndef INPUT_CLASS_H_INCLUDED
#define INPUT_CLASS_H_INCLUDED

//klasa input - do ujednolicenia wykonania jednakowych funkcjonalnosci
//              wystepujacych w roznych czesciach programu. Klasa ta jest
//              dziedziczona przez wszystkie pozostale klasy
class Input{
public:
    //funkcja do wprowadzania liczby z oczekiwanego przedzialu
    int inputLoop(int minimum, int maksimum){
        int x;
        // powtarzanie petli jesli x nie poza podanym zakresem lub nie jest liczba calkowita int
        while(!(std::cin >> x) || x < minimum || x > maksimum){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            printf("Nalezy podac cyfre z zakresu (%d) - (%d):\n",minimum,maksimum);
        }
        return x;
    }

    //funkcja do zwrocenia liczby losowej z oczekiwanego przedzialu
    double giveRandom(int min_v, int max_v){
        double random_num = (rand()/(double)RAND_MAX)*(max_v - min_v)+min_v;
        return random_num;
    }
};

#endif // INPUT_CLASS_H_INCLUDED
