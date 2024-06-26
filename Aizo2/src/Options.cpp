#include "Options.h"

bool Options::load_graph(){ //todo list version
    std::cout << "\nPodaj nazwe pliku tekstowego (razem z '.txt'):\n";
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
        char content[33];
        ifile.getline(content, 33);

        char* token = strtok(content," ");
        edges = std::atoi(token);
        token = strtok(nullptr," ");
        vertices = std::atoi(token);

        matrix.~IncidenceGraph();
        lista.~ListGraph();

        matrix.setGraph(vertices,edges);
        lista.setGraph(vertices,edges);

        for(int i=0;i<edges;i++){
            ifile.getline(content, 33);
            int numbers[3];
            int j = 0;
            token = strtok(content," ");
            do{
                numbers[j] = std::atoi(token);
                j++;
                token = strtok(nullptr," ");
            }while(token != nullptr);

            if(problem_type == 1){
                matrix.addEdge(i,numbers[0],numbers[1],numbers[2]);
                lista.addEdge(numbers[0],numbers[1],numbers[2]);
            }
            else{
                matrix.addDirectedEdge(i,numbers[0],numbers[1],numbers[2]);
                lista.addDirectedEdge(numbers[0],numbers[1],numbers[2]);
            }
        }
        std::cout << "\n\n";
    }
    catch(std::invalid_argument e){
        std::cout << "Przerwanie odczytu! W pliku znajduje sie niewlasciwy argument!\n"; return false;
    }

    ifile.close();
    isGenerated = true;
    return true;
}
void Options::generate_graph_info(){
    std::cout << "Podaj liczbe wierzcholkow grafu:";
    vertices = inputLoop(2,10000);
    std::cout << "Podaj gestosc grafu w procentach:";
    density = inputLoop(1,100);

    generate_graph(vertices, density);
}
void Options::generate_graph(int vertices, int density){
    matrix.~IncidenceGraph();
    lista.~ListGraph();

    int max_weight = 2000000;
    edges = (vertices*(vertices-1))*density/200;
    matrix.setGraph(vertices,edges);
    lista.setGraph(vertices,edges);
    int rand_num, src_vert, dest_vert;
    if(problem_type==1){ //no directed
        for(int v=0;v<vertices;v++){
            rand_num = rand()%max_weight+1;
            matrix.addEdge(v,v,(v+1)%vertices,rand_num);
            lista.addEdge(v,(v+1)%vertices,rand_num);
        }
        for(int i=vertices;i<edges;i++){
            rand_num = rand()%max_weight+1;
            do{
                src_vert = rand()%vertices;
                do{
                    dest_vert = rand()%vertices;
                }while(src_vert==dest_vert);
            }while(check_edge(src_vert,dest_vert,lista));

            matrix.addEdge(i,src_vert,dest_vert,rand_num);
            lista.addEdge(src_vert,dest_vert,rand_num);
        }
    }
    //directed
    else{
        for(int v=0;v<vertices;v++){
            rand_num = rand()%max_weight+1;
            matrix.addDirectedEdge(v,v,(v+1)%vertices,rand_num);
            lista.addDirectedEdge(v,(v+1)%vertices,rand_num);
        }
        for(int i=vertices;i<edges;i++){
            rand_num = rand()%max_weight+1;
            do{
                src_vert = rand()%vertices;
                do{
                    dest_vert = rand()%vertices;
                }while(src_vert==dest_vert);
            }while(check_edge(src_vert,dest_vert,lista));

            matrix.addDirectedEdge(i,src_vert,dest_vert,rand_num);
            lista.addDirectedEdge(src_vert,dest_vert,rand_num);
        }
    }
    isGenerated = true;
}
bool Options::check_edge(int src, int dest, ListGraph &lista){
    AdjListNode* node = lista.arr[src].head;
    while(node){
        if(dest == node->dest){return true;}
        node = node->next;
    }
    return false;
}
void Options::show_graph(){
    if(!isGenerated){std::cout << "Operacja niemozliwa! Graf nie zostal jeszcze utworzony.\n"; return;}
    matrix.printGraph();
    lista.printGraph();
}
bool Options::choose_algorithm_info(bool input){
    if(!isGenerated){std::cout << "Operacja niemozliwa! Graf nie zostal jeszcze utworzony.\n"; return false;}
    std::cout << "Wybierz algorytm:\n";
    if(problem_type == 1){
        std::cout << "(1) Algorytm Prima\n(2) Algorytm Kruskala\n";
        algorithm = inputLoop(1,2);
    }
    else{
        std::cout << "(1) Algorytm Dijkstry\n(2) Algorytm Forda-Bellmana\n";
        algorithm = inputLoop(1,2);
        if(input){
            std::cout << "Podaj wierzcholek poczatkowy:";
            start_vert = inputLoop(0,vertices-1);
            std::cout << "Podaj wierzcholek koncowy:";
            end_vert = inputLoop(0,vertices-1);
        }
    }
    return true;
}
void Options::choose_algorithm(bool results){
    double time_elapsedL = -1, time_elapsedM = -1;
    time_elapsedM = matrix_algorithms();
    time_elapsedL = list_algorithms();
    if(results){
        printf("(matrix) czas: %f milisekund\n",time_elapsedM/1000000);
        printf("(list)   czas: %f milisekund\n",time_elapsedL/1000000);
        print_solution();
    }
}

void Options::print_solution(){
    if(problem_type == 1){
            printf("\n=== Reprezentacja macierzowa ===\n");
            printf("Uzyskane drzewo\n\n0 jest wierzcholkiem poczatkowym\n");

            int sum = 0;
            for(int i=0;i<mst_IM.E;i++){
                int v = 0;
                while(mst_IM.incMatrix[v][i] == 0){v++;}
                printf("Krawedz %d - ",v);
                do{v++;}while(mst_IM.incMatrix[v][i] == 0);
                printf("%d | waga krawedzi: %d\n",v,mst_IM.weights[i]);
                sum += mst_IM.weights[i];
            }
            printf("Calkowita waga drzewa: %d",sum);
            printf("\n\n================================\n");
            sum = 0;
            printf("\n\n==== Reprezentacja listowa ====\n");
            printf("Uzyskane drzewo\n\n0 jest wierzcholkiem poczatkowym\n");
            for(int i=0;i<mst_L.V;i++){
                AdjListNode* node = mst_L.arr[i].head;
                while(node){
                    if(node->source < node->dest){
                        printf("Krawedz %d - %d | waga krawedzi: %d\n",node->source,node->dest,node->weight);
                        sum += node->weight;
                    }
                    node = node->next;
                }
            }
            printf("Calkowita waga drzewa: %d",sum);
            printf("\n\n==============================\n");
    }
    else{
        if(sp_IM.V > 0){
            if(sp_IM.E > 0){
                int total = 0;
                for(int e=0;e<sp_IM.E;e++){
                    total += sp_IM.weights[e];
                }
                printf("\n=== Reprezentacja macierzowa ===\n");
                std::cout << "Uzyskany koszt: " << total << "\n\n";
                printf("Znaleziona sciezka\n");
                int vert = 0;
                for(int e = sp_IM.E-1;e>=0;e--){
                    vert = 0;
                    while(sp_IM.incMatrix[vert][e] != 1){vert++;}
                    printf("%d - ",vert);
                }
                int e_v = 0;
                while(sp_IM.incMatrix[e_v][0] != -1){e_v++;}

                printf("%d",e_v);
                printf("\n\n================================\n");
                total = 0;

                AdjListNode* path = sp_L.arr[start_vert].head;
                while(path){
                    total += path->weight;
                    path = sp_L.arr[path->dest].head;
                }
                printf("\n\n==== Reprezentacja listowa ====\n");
                std::cout << "Uzyskany koszt: " << total << "\n\n";
                printf("Znaleziona sciezka\n");
                path = sp_L.arr[start_vert].head;
                if(start_vert != end_vert){
                    printf("%d",start_vert);
                    while(path){
                        printf(" - %d",path->dest);
                        path = sp_L.arr[path->dest].head;
                    }
                }
            }
            else{
                printf("\n=== Reprezentacja macierzowa ===\n");
                std::cout << "Uzyskany koszt: " << 0 << "\n\n";
                printf("Znaleziona sciezka\n");
                printf("%d",end_vert);
                printf("\n\n==== Reprezentacja listowa ====\n");
                std::cout << "Uzyskany koszt: " << 0 << "\n\n";
                printf("Znaleziona sciezka\n");
                printf("%d",end_vert);
            }
            printf("\n\n===============================\n");
        }
        else{
            printf("Nie mozna wyswietlic grafu z powodu niepowodzenia algorytmu!\n");
        }
    }
}

double Options::matrix_algorithms(){
    auto start = std::chrono::high_resolution_clock::now();
    auto ending = std::chrono::high_resolution_clock::now();
    double time_elapsed = -1;
    if(problem_type == 1){
        if(algorithm == 1){
            start = std::chrono::high_resolution_clock::now();
            mst.Prim(matrix).copy_solution(mst_IM);
            ending = std::chrono::high_resolution_clock::now();
            time_elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(ending-start).count();
        }
        else{
            start = std::chrono::high_resolution_clock::now();
            mst.Kruskal(matrix).copy_solution(mst_IM);
            ending = std::chrono::high_resolution_clock::now();
            time_elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(ending-start).count();
        }
    }
    else{
        if(algorithm == 1){
            start = std::chrono::high_resolution_clock::now();
            sp.Dijkstra(matrix,start_vert,end_vert).copy_solution(sp_IM);
            ending = std::chrono::high_resolution_clock::now();
            time_elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(ending-start).count();
        }
        else{
            start = std::chrono::high_resolution_clock::now();
            sp.Ford_Bellman(matrix,start_vert,end_vert).copy_solution(sp_IM);
            ending = std::chrono::high_resolution_clock::now();
            time_elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(ending-start).count();
        }
    }
    return time_elapsed;
}
double Options::list_algorithms(){
    auto start = std::chrono::high_resolution_clock::now();
    auto ending = std::chrono::high_resolution_clock::now();
    double time_elapsed = -1;
    if(problem_type == 1){
        // Prim
        if(algorithm == 1){
            start = std::chrono::high_resolution_clock::now();
            mst.Prim_L(lista).copy_solution(mst_L,false);
            ending = std::chrono::high_resolution_clock::now();
            time_elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(ending-start).count();
        } // Kruskal
        else{
            start = std::chrono::high_resolution_clock::now();
            mst.Kruskal_L(lista).copy_solution(mst_L,false);
            ending = std::chrono::high_resolution_clock::now();
            time_elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(ending-start).count();
        }
    }
    else{ //Dijkstra
        if(algorithm == 1){
            start = std::chrono::high_resolution_clock::now();
            sp.Dijkstra_L(lista,start_vert,end_vert).copy_solution(sp_L,true);
            ending = std::chrono::high_resolution_clock::now();
            time_elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(ending-start).count();
        } //Ford-Bellman
        else{
            start = std::chrono::high_resolution_clock::now();
            sp.Ford_Bellman_L(lista,start_vert,end_vert).copy_solution(sp_L,true);
            ending = std::chrono::high_resolution_clock::now();
            time_elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(ending-start).count();
        }
    }
    return time_elapsed;
}

void Options::serie(){
    system("CLS");

    int num_of_vertices[7] = {10,20,40,75,150,250,500};
    //int num_of_vertices[3] = {10,20,40};
    //int num_of_vertices[2] = {75,150};
    //int num_of_vertices[2] = {250,500};

    int v_array_length = sizeof(num_of_vertices)/sizeof(int);
    int densities[3] = {25,50,99};
    int repeats = 0;
    double time_measuredM, time_measuredL, average_timeM, average_timeL;
    std::string files[3] = {"d-25.txt", "d-50.txt", "d-99.txt"};
    std::cout << "Zostanie przeprowadzone badanie dla 7 reprezentatywnych liczb wierzcholkow,\ndla 3 roznych gestosci\nPodaj liczbe powtorzen:";
    repeats = inputLoop(0,2000);
    choose_algorithm_info(false);

    for(int i=0;i<3;i++){               //graphs densities
        std::ofstream outFile(files[i]);
        if (!outFile.is_open()) {
            std::cout << "Blad otwarcia pliku na zapisywanie danych!\n";
            return;
        }
        outFile << files[i] << " (time in ms):\n";
        for(int j=0;j<v_array_length;j++){//graph sizes
            printf("%d vertices - %d density\n",num_of_vertices[j],densities[i]);
            average_timeM = 0;
            average_timeL = 0;
            time_measuredM = 0;
            time_measuredL = 0;
            for(int x=0;x<repeats;x++){ //repeats
                if(problem_type == 2){
                    start_vert = rand()%num_of_vertices[j];
                    do{end_vert = rand()%num_of_vertices[j];}while(end_vert==start_vert);
                }
                if(x%5 == 0){printf("%d/%d Ukonczenia\n",x,repeats);}
                generate_graph(num_of_vertices[j],densities[i]);
                time_measuredM += matrix_algorithms();
                time_measuredL += list_algorithms();
            }
            average_timeM = time_measuredM/(double)(repeats*1000000.);
            average_timeL = time_measuredL/(double)(repeats*1000000.);
            outFile << "Macierz " << num_of_vertices[j] << ": " << average_timeM << "\n";
            outFile << "Lista   " << num_of_vertices[j] << ": " << average_timeL << "\n\n";
        }
        outFile.close();
    }
}

Options::~Options(){

}
