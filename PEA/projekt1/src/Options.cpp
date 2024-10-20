#include "Options.h"

TSPfull tspF;
TSPneighbour tspN;
TSPrandom tspR;

void Options::create_matrix(int mSize){
    TSPmatrix = new int*[mSize];
    for(int i = 0; i < mSize; ++i){
        TSPmatrix[i] = new int[mSize];
        for(int j = 0; j < mSize; ++j){
            TSPmatrix[i][j] = -1;
        }
    }
    removed_matrix_size = matrix_size;
}

void Options::remove_matrix(){
    if(TSPmatrix != nullptr){
        for (int i = 0; i < removed_matrix_size; i++) {
            delete[] TSPmatrix[i];
        }
        delete[] TSPmatrix;
    }
}

void Options::set_iterations_num(int m_size){
    iterations = 1;                // ustawienie liczby iteracji dla TSP
    for(int i=2;i<=m_size;i++){    // losowego w zaleznosci od rozmiaru macierzy.
        iterations*=i;             // wzor dobrany eksperymentalnie tak aby
    }                              // algorytm zwracal optymalny wynik z prawdopodobienstwem >=75%
    iterations/=std::max(m_size - 4, 1);// iterations = size! / (size - 4)
}

bool Options::load_graph(){
    std::cout << "\nPodaj nazwe pliku tekstowego:\n";
    std::cin >> text_file;
    std::ifstream ifile;
    ifile.open(text_file);
    // petla do obsluzenia przypadku nie odnalezienia pliku o zadanej nazwie
    while(!ifile){
        std::cout << "\nNie mozna odnalezc pliku. Upewnij sie ze podana nazwa jest wlasciwa i sprobuj ponownie lub:\n(0) Jesli chcesz wyjsc z programu\n(-1) Jesli chcesz sie cofnac do menu\n";
        std::cin >> text_file;
        ifile.open(text_file);
        if(text_file == "-1")       {system("CLS"); return true;}
        else if(text_file == "0")   {return false;}
    }
    std::cout << "\nPlik zostal pomyslne odnaleziony\n";

    try{
        remove_matrix();
        char content[60];
        ifile.getline(content, 60);

        char* token = strtok(content, " ");
        matrix_size = std::atoi(token);
        set_iterations_num(matrix_size);
        create_matrix(matrix_size);

        for(int i=0;i<matrix_size;i++){
            ifile.getline(content, 60);
            int j = 0;
            token = strtok(content," ");
            do{
                TSPmatrix[i][j] = std::atoi(token);
                j++;
                token = strtok(nullptr," ");
            }while(token != nullptr);
        }
        std::cout << "\n\n";
    }
    catch(std::invalid_argument e){
        std::cout << "Przerwanie odczytu! W pliku znajduje sie niewlasciwy argument!\n"; return false;
    }

    ifile.close();
    isGenerated = true;
    symmetric = 2;
    for(int i=0;i<matrix_size;i++){
        for(int j=0;j<matrix_size;j++){
            if(TSPmatrix[i][j] != TSPmatrix[j][i]) {symmetric = 1; return true;}
        }
    }
    return true;
}
void Options::generate_graph_info(){
    std::cout << "Podaj dlugosc macierzy:";
    matrix_size = inputC.inputLoop(2,10000);
    std::cout << "Podaj rodzaj problemu\n(1) TSP asymetryczny\n(2) TSP symetryczny\n";
    symmetric = inputC.inputLoop(1,2);
    generate_graph(matrix_size);
}
void Options::generate_graph(int matrix_s){
    remove_matrix();
    int max_weight = 2000;
    create_matrix(matrix_s);
    set_iterations_num(matrix_s);

    for(int i=0;i<matrix_s;i++){
        for(int j=0;j<matrix_s;j++){
            if(i != j){
                TSPmatrix[i][j] = rand()%max_weight+1;
            }
        }
    }
    if(symmetric == 2){
        for(int i=0;i<matrix_s;i++){
            for(int j=0;j<matrix_s;j++){
                if(i != j){
                    TSPmatrix[i][j] = TSPmatrix[j][i];
                }
            }
        }
    }
    isGenerated = true;
}

void Options::show_graph(){
    if(!isGenerated){std::cout << "Operacja niemozliwa! Macierz nie zostala jeszcze utworzona.\n"; return;}
    std::cout << "\n";
    for(int i=0;i<matrix_size;i++){
        for(int j=0;j<matrix_size;j++){
            std::cout << TSPmatrix[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}
bool Options::choose_algorithm_info(bool input){
    if(!isGenerated){std::cout << "Operacja niemozliwa! Macierz nie zostala jeszcze utworzona.\n"; return false;}
    std::cout << "Wybierz algorytm:\n";

    std::cout << "(1) Przeglad zupelny\n(2) Przeglad najblizszych sasiadow\n(3) Przeglad losowy\n";
    algorithm = inputC.inputLoop(1,3);
    return true;
}
void Options::choose_algorithm(bool results){
    double time_elapsed = -1;
    time_elapsed = matrix_algorithms();
    if(results){
        printf("czas: %f milisekund\n",time_elapsed/1000000);
        print_solution(algorithm, cycle_length);
    }
}

void Options::print_solution(int alg, int solution){
    std::string algorithm_type;
    switch (alg){
        case 1: algorithm_type = "Przeglad zupelny";    break;
        case 2: algorithm_type = "Przeglad najblizszych sasiadow";  break;
        case 3: algorithm_type = "Przeglad losowy";    break;
        default:    break;
    }
    std::cout <<  algorithm_type << " - dlugosc sciezki: " << solution << "\n\n";
}

double Options::matrix_algorithms(){
    auto start = std::chrono::high_resolution_clock::now();
    auto ending = std::chrono::high_resolution_clock::now();
    double time_elapsed = -1;
    if(algorithm == 1){
        start = std::chrono::high_resolution_clock::now();
        cycle_length = tspF.algorithm(TSPmatrix, matrix_size);
        ending = std::chrono::high_resolution_clock::now();
    }
    else if(algorithm == 2){
        start = std::chrono::high_resolution_clock::now();
        cycle_length = tspN.algorithm(TSPmatrix, matrix_size);
        ending = std::chrono::high_resolution_clock::now();
    }
    else{
        start = std::chrono::high_resolution_clock::now();
        cycle_length = tspR.algorithm(TSPmatrix, matrix_size, iterations);
        ending = std::chrono::high_resolution_clock::now();
    }
    time_elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(ending-start).count();
    return time_elapsed;
}

void Options::serie(){
    system("CLS");

    int matrixSizes[7] = {5,6,7,8,9,10,11};

    int repeats = 0;
    double Stime_measured, Saverage_time, Atime_measured, Aaverage_time;
    std::string files[3] = {"full.csv", "neighbour.csv", "random.csv"};
    std::cout << "Zostanie przeprowadzone badanie dla 7 reprezentatywnych rozmiarow macierzy,\ndla 3 roznych algorytmow\nPodaj liczbe powtorzen:";
    repeats = inputC.inputLoop(0,5000);

    for(int i=0;i<3;i++){               //matrix algorithms
        std::ofstream outFile(files[i]);
        if (!outFile.is_open()){
            std::cout << "Blad otwarcia pliku na zapisywanie danych!\n";
            return;
        }
        outFile << files[i] << " (time in ms):\n-,Asymetryczne,Symetryczne\n";
        algorithm = i+1;

        for(int j=0;j<7;j++){//matrix sizes
            printf("matrix size %d     ",matrixSizes[j]);
            Saverage_time = 0;
            Stime_measured = 0;
            Aaverage_time = 0;
            Atime_measured = 0;
            matrix_size = matrixSizes[j];
            for(int x=0;x<repeats;x++){ //repeats
                if(x%10 == 0){printf("%d/%d Ukonczenia\n",x,repeats);}
                symmetric = 1; //asymetryczny
                generate_graph(matrixSizes[j]);
                Atime_measured += matrix_algorithms();
                symmetric = 2; //symetryczny
                generate_graph(matrixSizes[j]);
                Stime_measured += matrix_algorithms();
            }
            Aaverage_time = Atime_measured/(double)(repeats*1000000.);
            Saverage_time = Stime_measured/(double)(repeats*1000000.);
            outFile << "Macierz " << matrixSizes[j] << "," << Aaverage_time << "," << Saverage_time << "\n";
        }
        outFile.close();
    }
}
Options::~Options()
{
    remove_matrix();
}
