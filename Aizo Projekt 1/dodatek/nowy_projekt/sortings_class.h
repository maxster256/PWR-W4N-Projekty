#ifndef SORTINGS_CLASS_H_INCLUDED
#define SORTINGS_CLASS_H_INCLUDED

#include "input_class.h"

//klasa sortings - klasa ze wszystkimi uwzglednionymi sortowaniami
//                  sortowanie shella z 2 funkcjami po 1 dla kazdego rodzaju
//                  podobnie quick sort: 4 funkcje po 1 dla kazdego rodzaju wyboru pivota
template <typename T>
class Sortings: public Input{
public:
    int chosen_pivot = -1;   //zmienna okreslajaca wybrany sposob doboru pivota w quicksort
    int ShellOption = -1;    //zmienna okreslajaca wybrane odstepy w algorytmie shella

// poczatek sekcji z sortowaniem przez wstawianie
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

    double prepareInsertSort(T tab[], int n){
        auto start = std::chrono::high_resolution_clock::now();
        insertSort(tab, n);
        auto ending = std::chrono::high_resolution_clock::now();
        return std::chrono::duration_cast<std::chrono::nanoseconds>(ending-start).count();
    }

// poczatek sekcji z sortowaniem przez kocpowanie
    void heapFix(T t[], int n, int index){
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
            heapFix(t, n, parent);
        }
    }

    void heapSort(T tab[], int n){
        //wstepne zbudowanie kopca
        for (int i = n/2 - 1; i >= 0; i--){
            heapFix(tab, n, i);
        }
        //wlasciwa czesc sortowania
        for(int i=n-1;i>0; i--) {
            std::swap(tab[0],tab[i]);
            heapFix(tab,i,0);
        }
    }

    double prepareHeapSort(T tab[], int n){
        auto start = std::chrono::high_resolution_clock::now();
        heapSort(tab, n);
        auto ending = std::chrono::high_resolution_clock::now();
        return std::chrono::duration_cast<std::chrono::nanoseconds>(ending-start).count();
    }
// poczatek sekcji z sortowaniami shella
    // z odstepami shella N/2, N/4 itd.
    void ShellSort1(T tab[], int n){
        for (int gap = n/2; gap > 0; gap /= 2) {
            for (int i = gap; i < n; i += 1) {
                auto temp = tab[i];
                int j;
                for (j = i; j >= gap && tab[j-gap] > temp; j -= gap){
                    tab[j] = tab[j-gap];
                }
                tab[j] = temp;
            }
        printf("\n");
        }
    }
    // z odstepami Hibbarda (2^k - 1)
    void ShellSort2(T tab[], int n){
        int interval = 2;                   // wyznaczenie maksymalnej potegi liczby 2
        while(interval < n/2){interval*=2;} // ale mniejszej niz n
        interval--;                         // uzyskanie 2^k - 1
        for (int gap = interval; gap > 0; gap /= 2) {
            for (int i = gap; i < n; i += 1) {
                auto temp = tab[i];
                int j;
                for (j = i; j >= gap && tab[j-gap] > temp; j -= gap){
                    tab[j] = tab[j-gap];
                }
                tab[j] = temp;
            }
        }
    }

    void shellSortInfo(int n){
        std::cout << "Wybierz sortowanie shella:\n(1) Odstepy Shella N/2, N/4 itd.\n(2) Odstepy Hibbarda (2^-1)\n";
        ShellOption = inputLoop(1,2);
    }
    double prepareShellSort(T tab[], int n){
        auto start = std::chrono::high_resolution_clock::now();
        switch(ShellOption){
            case 1: ShellSort1(tab, n); break;
            case 2: ShellSort2(tab, n); break;
            default: break;
        }
        auto ending = std::chrono::high_resolution_clock::now();
        return std::chrono::duration_cast<std::chrono::nanoseconds>(ending-start).count();
    }

// poczatek sekcji z sortowaniami szybkimi
    // z lewym skrajnym pivotem
    int partitionedL(T tab[], int left, int right){
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
                if (r == right) {r--;}
                return r;
            }
        }
    }
    void quickSortL(T tab[], int l, int r){
        if(l>=r)    {return;}
        int m = partitionedL(tab, l, r);
        quickSortL(tab, l, m);
        quickSortL(tab, m+1, r);
    }

    // z prawym skrajnym pivotem
    int partitionedR(T tab[], int left, int right){
        T pivot = tab[right];
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
                if (r == right) {r--;}
                return r;
            }
        }
    }
    void quickSortR(T tab[], int l, int r){
        if(l>=r)    {return;}
        int m = partitionedR(tab, l, r);
        quickSortR(tab, l, m);
        quickSortR(tab, m+1, r);
    }

    // ze srodkowym pivotem
    int partitionedM(T tab[], int left, int right){
        T pivot = tab[(left+right)/2];
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
                if (r == right) {r--;}
                return r;
            }
        }
    }
    void quickSortM(T tab[], int l, int r){
        if(l>=r)    {return;}
        int m = partitionedM(tab, l, r);
        quickSortM(tab, l, m);
        quickSortM(tab, m+1, r);
    }

    // z losowym pivotem
    int partitionedRand(T tab[], int left, int right){
        T pivot = tab[int(giveRandom(left,right))];
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
                if (r == right) {r--;}
                return r;
            }
        }
    }
    void quickSortRand(T tab[], int l, int r){
        if(l>=r)    {return;}
        int m = partitionedRand(tab, l, r);
        quickSortRand(tab, l, m);
        quickSortRand(tab, m+1, r);
    }

    // pomiar czasu sortowania z pivotem skrajnym lewym
    double quickSort1(T tab[], int l, int r){
        auto start = std::chrono::high_resolution_clock::now();
        quickSortL(tab, l, r);
        auto ending = std::chrono::high_resolution_clock::now();
        return std::chrono::duration_cast<std::chrono::nanoseconds>(ending-start).count();
    }

    // pomiar czasu sortowania z pivotem skrajnym prawym
    double quickSort2(T tab[], int l, int r){
        auto start = std::chrono::high_resolution_clock::now();
        quickSortR(tab, l, r);
        auto ending = std::chrono::high_resolution_clock::now();
        return std::chrono::duration_cast<std::chrono::nanoseconds>(ending-start).count();
    }

    // pomiar czasu sortowania z pivotem srodkowym
    double quickSort3(T tab[], int l, int r){
        auto start = std::chrono::high_resolution_clock::now();
        quickSortM(tab, l, r);
        auto ending = std::chrono::high_resolution_clock::now();
        return std::chrono::duration_cast<std::chrono::nanoseconds>(ending-start).count();
    }

    // pomiar czasu sortowania z pivotem losowym
    double quickSort4(T tab[], int l, int r){
        auto start = std::chrono::high_resolution_clock::now();
        quickSortRand(tab, l, r);
        auto ending = std::chrono::high_resolution_clock::now();
        return std::chrono::duration_cast<std::chrono::nanoseconds>(ending-start).count();
    }

    // wybor pivota w sortowaniu szybkim
    void quickSortInfo(){
        std::cout << "Wybierz pozycje pivota:\n(1) Skrajna lewa\n(2) Skrajna prawa\n(3) Srodkowa\n(4) Losowa\n";
        chosen_pivot = inputLoop(1,4);
    }
    // wywolanie danej funkcji zalezne od wyboru z powyzszej funkcji
    double prepareQuickSort(T tab[], int l, int r){
        int time_m = 0;
        switch(chosen_pivot){
            case 1: time_m = quickSort1(tab, l, r); break;
            case 2: time_m = quickSort2(tab, l, r); break;
            case 3: time_m = quickSort3(tab, l, r); break;
            case 4: time_m = quickSort4(tab, l, r); break;
            default: break;
        }
        return time_m;
    }
};

#endif // SORTINGS_CLASS_H_INCLUDED
