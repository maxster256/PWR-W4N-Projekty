#include <iostream>
#include <ctime>
#include <chrono>
#include <stdlib.h>
#include <fstream>
#include <cstdlib>
#include <algorithm>

class Input{
public:
    int inputLoop(int minimum, int maksimum){
        int x;
        std::cin >> x;
        while(x < minimum || x > maksimum){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            printf("Nalezy podac cyfre z zakresu (%d) - (%d):\n",minimum,maksimum);
            std::cin >> x;
        }
        return x;
    }
    double giveRandom(int min_v, int max_v){
        double random_num = (rand()/(double)RAND_MAX)*(max_v - min_v)+min_v;
        return random_num;
    }
};
template <typename T>
class Sortings: public Input{
public:
    int pivot_index = -1;
    int shellSortGrain;

    void insertSort(T tab[], int n){
        int key;
        for(int i=1;i<n;i++){
            key=tab[i];
            int j=i;
            while(j>0 && tab[j-1]>key){
                tab[j]=tab[j-1];
                j--;
            }
            tab[j] = key;
        }
    }

    void heapFixUp(T t[], int n, int index){
        int parent = index;
        int left_child = 2 * index + 1;
        int right_child = 2 * index + 2;
        if (left_child < n && t[left_child] > t[parent]){
            parent = left_child;
        }
        if (right_child < n && t[right_child] > t[parent]){
            parent = right_child;
        }
        if (parent != index) {
            std::swap(t[index], t[parent]);
            heapFixUp(t, n, parent);
        }
    }

    void heapSort(T tab[], int n){

        for (int i = n/2 - 1; i >= 0; i--){
            heapFixUp(tab, n, i);
        }
        for(int i=n-1;i>0; i--) {
            std::swap(tab[0],tab[i]);
            heapFixUp(tab,i,0);
        }
    }
    void ShellSort(T tab[], int n){
        std::cout << "Wybierz ziarno sortowania shella:\n";
        shellSortGrain = inputLoop(1,n);
        for (int gap = n/shellSortGrain; gap > 0; gap /= shellSortGrain) {
            for (int i = gap; i < n; i += 1) {
                int temp = tab[i];
                int j;
                for (j = i; j >= gap && tab[j-gap] > temp; j -= gap){
                    tab[j] = tab[j-gap];
                }
                tab[j] = temp;
            }
        }
    }
    int partitioned(T tab[], int left, int right){
        T pivot = tab[left];
        int l=left; int r = right;
        while(true){
            while(tab[l]<pivot){l++;}
            while(tab[r]>pivot){r--;}
            if(l < r){
                std::swap(tab[l],tab[r]);
                l++;
                r--;
            }
            else{
                if (r == right) r--;
                return r;
            }
        }
    }

    void quickSort(T tab[], int l, int r){
        if(l>=r)    {return;}
        int m = partitioned(tab, l, r);
        quickSort(tab, l, m);
        quickSort(tab, m+1, r);
    }
};

template <typename H>
class Operations: public Input{
public:
    Sortings<H> sorting;
    H* arrayToSort = nullptr;
    H* sortedArray = nullptr;
    int array_size;
    std::string text_file;
    int min_value, max_value;
    int source = 0;
    int algorithm = 0;

    bool is_initialized = false;
    bool isSorted = false;
    Operations() : arrayToSort(nullptr), array_size(0) {}

    void createArray(H *&arr, int array_size){
        if (arr != nullptr) {
            delete[] arr;
        }
        arr = new H[array_size];
        this->array_size = array_size;
        is_initialized = true;
    }

    bool optionMenu(){
        std::cout << "Wybierz polecenie:\n(1) Wczytanie tablicy z pliku o zadanej nazwie\n(2) Wygenerowanie tablicy o zadanym rozmiarze\n(3) Wyswietlenie ostatnio utworzonej tablicy\n(4) Uruchomienie wybranego algorytmu sortowania\n(5) Wyswietlenie posortowanej tablicy\n(6) Sprawdzenie poprawnosci sortowania\n\n(0) Wyjscie z programu\n";
        source = inputLoop(0, 6);
        if (source == 0)   {return false;}
        return true;
    }
    void options(){
        while(true){
            if(!optionMenu()) {break;}
            switch(source){
                case 1: loadFile(); break;
                case 2: generateArray(); break;
                case 3: showLastArray(); break;
                case 4: chooseAlgorithm(); break;
                case 5: showSortedArray(); break;
                case 6: isSortDoneRight(); break;
                default: break;
            }
            system("PAUSE");
            system("CLS");
        }
    }
    void loadFile(){
        std::cout << "\nPodaj nazwe pliku tekstowego (razem z '.txt'):\n";
        std::cin >> text_file;
        std::ifstream ifile;
        ifile.open(text_file);
        while(!ifile){
            std::cout << "\nNie mozna odnalezc pliku. Upewnij sie ze podana nazwa jest wlasciwa i sprobuj ponownie.\n(0) Jesli ccesz wyjsc z programu\n(-1) Jesli chcesz sie cofnac do poprzedniego menu\n";
            std::cin >> text_file;
            ifile.open(text_file);
            if(text_file == "-1")       {system("CLS"); return;}
            else if(text_file == "0")   {exit(9);}
        }
        std::cout << "\nPlik zostal pomyslne odnaleziony\n";

        try{
            std::string content;
            getline(ifile, content);
            createArray(arrayToSort, std::stoi(content));
            int index = 0;
            while(getline(ifile, content)){
                arrayToSort[index] = std::stod(content);
                index++;
            }
            std::cout << "\n\n";
        }
        catch(std::invalid_argument e){
            std::cout << "Przerwanie odczytu! W pliku znajduje sie niewlasciwy argument!\n"; exit(1);
        }

        is_initialized = true;
        isSorted = false;
    }
    void generateArray(){
        std::cout << "\nWybierz rozmiar tablicy:\n";
        array_size = inputLoop(1, 2147000000);
        std::cout << "\nPodaj minimalna wartosc w tablicy:\n";
        min_value = inputLoop(-2147000000, 2147000000);
        std::cout << "\nPodaj maksymalna wartosc w tablicy:\n";
        max_value = inputLoop(min_value, 2147000000);
        createArray(arrayToSort, array_size);
        H rand_number;
        for (int i = 0; i < array_size; i++){
            rand_number = giveRandom(min_value, max_value);
            arrayToSort[i] = rand_number;
        }
        is_initialized = true;
        isSorted = false;
    }
    void showLastArray(){
        if(!is_initialized) {std::cout << "Operacja niemozliwa. Tablica nie zostala jeszcze zainicjowana!\n"; return;}
        std::cout << "\nZawartosc ostaniej utworzonej tablicy:\n";
        for(int i = 0; i < array_size; i++){
            std::cout << arrayToSort[i] << "\n";
        }
    }
    void chooseAlgorithm(){
        if(!is_initialized) {std::cout << "Operacja niemozliwa. Tablica nie zostala jeszcze zainicjowana!\n"; return;}
        system("CLS");
        std::cout << "Wybierz algorytm sortowania:\n(1) przez wstawianie\n(2) przez kopcowanie\n(3) Shella\n(4) szybkie\n\n(0) Wyjscie z programu\n(-1) Cofniecie do poprzedniego menu\n";
        algorithm = inputLoop(-1,4);
        system("CLS");
        createArray(sortedArray, array_size);
        std::copy(arrayToSort, arrayToSort+array_size, sortedArray);
        // sort(sortedArray, sortedArray + array_size, std::greater<H>());
        // here with 0 - 33 - 66 - 100 stuff
        switch(algorithm){
            case -1: return; break;
            case 0: exit(9); break;
            case 1: sorting.insertSort(sortedArray, array_size); break;
            case 2: sorting.heapSort(sortedArray, array_size); break;
            case 3: sorting.ShellSort(sortedArray, array_size); break;
            case 4: sorting.quickSort(sortedArray, 0, array_size); break;
            default: break;
        }
        isSorted = true;
    }
    void showSortedArray(){
        if(!isSorted) {std::cout << "Operacja niemozliwa. Ostatnio utworzona tablica nie zostala jeszcze posortowana!\n"; return;}
        std::cout << "\nZawartosc ostaniej posortowanej tablicy:\n";
        for(int i = 0; i < array_size; i++){
            std::cout << sortedArray[i] << "\n";
        }
    }
    void isSortDoneRight(){
        if(!isSorted) {std::cout << "Operacja niemozliwa. Ostatnio utworzona tablica nie zostala jeszcze posortowana!\n"; return;}
        for(int i = 1; i < array_size; i++){
            if(sortedArray[i] < sortedArray[i-1]) {printf("Wykryto blad na indeksie %d !\n",i); return;}
        }
        std::cout << "Nie wykryto bledow w sortowaniu.\n";
    }

    ~Operations(){
        if(arrayToSort != nullptr){
            delete[] arrayToSort;
        }
        if(sortedArray != nullptr){
            delete[] sortedArray;
        }
    }
};

class menu : public Input{
private:
    void chooseDataType(){
        std::cout << "######################################################\n           AiZO - zadanie projektowe nr. 1\n\n";
        std::cout << "      Badanie efektywnosci wybranych algorytmow\n   sortowania ze wzgledu na zlozonosc obliczeniowa\n";
        std::cout << "######################################################\n";
        std::cout << "\nStworzony program pozwala na wykonanie roznych sposobow sortownia\nna ponizej pzedstawionych typach danych. W celu wybrania\ndanego typu danych nalezy podac odpowiednia cyfre:\n";
        std::cout << "\n(1) Int\n(2) Float\n(3) Double\n\n(0) Wyjscie z programu\n";
        data_type = inputLoop(0, 3);
        if (data_type == 0)  {exit(9);}
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

int main()
{
    menu klasa;
    srand(time(NULL));
    klasa.init_programme();
}
