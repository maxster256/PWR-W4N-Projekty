#include "Options.h"

bool Options::load_graph(int problem_type){ //todo list version
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
        matrix.setGraph(vertices,edges);
        lista.setGraph(vertices,edges);

        int vert = 0;
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
                //lista.addEdge(numbers[1],numbers[0],numbers[2]);
            }
            else{
                matrix.addDirectedEdge(i,numbers[0],numbers[1],numbers[2]);
                lista.addDirectedEdge(numbers[0],numbers[1],numbers[2]);
            }
            vert++;
        }
        delete token;
        free(token);
        std::cout << "\n\n";
    }
    catch(std::invalid_argument e){
        std::cout << "Przerwanie odczytu! W pliku znajduje sie niewlasciwy argument!\n"; return false;
    }

    ifile.close();
    isGenerated = true;
    return true;
}
void Options::generate_graph_info(int problem_type){
    std::cout << "Podaj liczbe wierzcholkow grafu:";
    vertices = inputLoop(2,10000);
    std::cout << "Podaj gestosc grafu w procentach:";
    density = inputLoop(1,100);

    generate_graph(problem_type);
    isGenerated = true;
}
void Options::generate_graph(int problem_type){
    matrix.~IncidenceGraph();
    lista.~ListGraph();

    int max_weight = 100;

    edges = (vertices*(vertices-1))*density/200;
    matrix.setGraph(vertices,edges);
    lista.setGraph(vertices,edges);
/*
    int *indexes = new int[edges];
    for(int i=0;i<edges;i++){
        indexes[i] = i;
    }

    for(int i=edges-1;i>0;i--){
        int j = rand()%(i+1);
        int temp = indexes[i];
        indexes[i] = indexes[j];
        indexes[j] = temp;
    }
*/
    int rand_num, src_vert, dest_vert;
    if(problem_type==1){ //no directed
        for(int v=0;v<vertices;v++){
            rand_num = rand()%max_weight+1;
            matrix.addEdge(v,v,(v+1)%vertices,rand_num);
            lista.addEdge(v,(v+1)%vertices,rand_num);
            //lista.addEdge();
        }
        for(int i=vertices;i<edges;i++){
            rand_num = rand()%max_weight+1;
            do{
                src_vert = rand()%vertices;
                do{
                    dest_vert = rand()%vertices;
                }while(src_vert==dest_vert);
            }while(check_edge(src_vert,dest_vert));

            matrix.addEdge(i,src_vert,dest_vert,rand_num);
            lista.addEdge(src_vert,dest_vert,rand_num);
        }
    }
    else{   //directed
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
            }while(check_edge(src_vert,dest_vert));

            matrix.addDirectedEdge(i,src_vert,dest_vert,rand_num);
            lista.addDirectedEdge(src_vert,dest_vert,rand_num);
        }
    }
}
bool Options::check_edge(int src, int dest){
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
void Options::choose_algorithm(int problem_type){
    if(!isGenerated){std::cout << "Operacja niemozliwa! Graf nie zostal jeszcze utworzony.\n"; return;}
    if(problem_type != 3){
        std::cout << "Wybierz algorytm:\n";
        if(problem_type == 1){
            std::cout << "(1) Algorytm Prima\n(2) Algorytm Kruskala\n";
            algorithm = inputLoop(1,2);
            if(algorithm == 1){
                mst.Prim(matrix,true);
                mst.Prim_L(lista,true);
            }
            else{
                mst.Kruskal(matrix,true);
                mst.Kruskal_L(lista,true);
            }
        }
        else{
            std::cout << "(1) Algorytm Dijkstry\n(2) Algorytm Forda-Bellmana\n";
            algorithm = inputLoop(1,2);
            std::cout << "Podaj wierzcholek poczatkowy:";
            start_vert = inputLoop(0,vertices-1);
            std::cout << "Podaj wierzcholek koncowy:";
            end_vert = inputLoop(0,vertices-1);

            if(algorithm == 1){
                sp.Dijkstra(matrix,start_vert,end_vert,true);
            }
            else{
                sp.Ford_Bellman(matrix,start_vert,end_vert,true);
            }
        }
    }
    /*
    else{

            std::cout << "Podaj wierzcholek poczatkowy:";
            start_vert = inputLoop(0,vertices-1);
            std::cout << "Podaj wierzcholek koncowy:";
            end_vert = inputLoop(0,vertices-1);

            th.Ford_Fulkerson(matrix,start_vert,end_vert);
    }*/
}

Options::~Options(){

}
