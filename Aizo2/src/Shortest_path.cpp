#include "Shortest_path.h"
#include <chrono>

IncidenceGraph Shortest_path::Dijkstra(IncidenceGraph &graph, int start_vert, int end_vert){

    int vertices = graph.V;
    int edges = graph.E;

    IncidenceGraph solution;

    bool visited[vertices];
    int d[vertices];
    int p[vertices];
    for(int v=0;v<vertices;v++){
        visited[v] = false;
        d[v] = INT_MAX; //INT_MAX
        p[v] = -1;
    }
    d[start_vert] = 0;
    for(int x=0;x<vertices;x++){
        int u = -1;
        // szukanie nierozpatrywanego wierzcholka o najmniejszej odleglosci (bez zastosowania kolejki)
        for(int i=0;i<vertices;i++) {
            if (!visited[i] && (u==-1 || d[i]<d[u])){u = i;}
        }
        visited[u] = true;

        for(int j=0;j<edges;j++) {
            if(graph.incMatrix[u][j] == 1){ // jesli krawedz wychodzi z rozpatrywanego wierzcholka
                for(int v=0; v<vertices; v++){
                    if(graph.incMatrix[v][j] == -1) { // jesli znalezioy zostal koniec krawedzi
                        if(!visited[v] && d[v] > d[u] + graph.weights[j] && d[u] != INT_MAX) {
                            d[v] = d[u] + graph.weights[j];
                            p[v] = u;
                        }
                    }
                }
            }
        }
    }

    if(d[end_vert] != INT_MAX){
        int path_edges = 0;
        int next_vert = p[end_vert];
        if(end_vert != start_vert){
            path_edges++;
            //petla do zliczenia liczby krawedzi miedzy wskazanymi wierzcholkami
            while(next_vert != start_vert){
                path_edges++;
                next_vert = p[next_vert];
            }
        }
        solution.setGraph(vertices,path_edges);
        path_edges = 0;
        next_vert = end_vert;
        if(end_vert != start_vert){
            //petla do dodania krawedzi tworzacych rozwiazanie do grafu wynikowego
            while(next_vert != start_vert){
                solution.addDirectedEdge(path_edges,p[next_vert],next_vert,d[next_vert]-d[p[next_vert]]);
                path_edges++;
                next_vert = p[next_vert];
            }
        }
    }
    else{
        printf("Nie istnieje sciezka o poczatku w (%d) i koncu w (%d)\n",start_vert,end_vert);
        solution.setGraph(0,0);
    }
    return solution;
}

IncidenceGraph Shortest_path::Ford_Bellman(IncidenceGraph &graph, int start_vert, int end_vert){
    int vertices = graph.V;
    int edges = graph.E;

    IncidenceGraph solution;

    int d[vertices];
    int p[vertices];
    for(int v=0;v<vertices;v++){
        d[v] = INT_MAX; //INT_MAX
        p[v] = -1;
    }
    d[start_vert] = 0;
    for(int i=1;i<vertices;i++){ //petla wykonujaca sie v-1 razy
        for(int e=0;e<edges;e++){ //petla do proby relaksacji kazdej z krawedzi
            int u = -1, v = -1, vert = 0;
            while(u == -1 || v == -1){ //petla do odnalezienia zrodla i konca krawedzi
                if(graph.incMatrix[vert][e] == 1){
                        u = vert;
                }
                else if(graph.incMatrix[vert][e] == -1){
                        v = vert;
                } // u source ; v destination
                vert++;
            }
            //proba relaksacji
            if (d[v] > d[u] + graph.weights[e] && d[u] != INT_MAX){
                d[v] = d[u] + graph.weights[e];
                p[v] = u;
            }
        }
    }
    //petla do sprawdzenia czy nie wystapil cykl ujemny osiagalny z wierzcholka startowego
    for(int e=0;e<edges;e++){
        int u = -1, v = -1, vert = 0;
        while(u == -1 || v == -1){ //petla do odnalezienia zrodla i konca krawedzi
            if(graph.incMatrix[vert][e] == 1){
                    u = vert;
            }
            else if(graph.incMatrix[vert][e] == -1){
                    v = vert;
            } // u source ; v destination
            vert++;
        }
        if (d[v] > d[u] + graph.weights[e] && d[u] != INT_MAX){
            std::cout << "Nieprawidlowa droga! Wystapil cykl ujemny!\n"; solution.setGraph(0,0); return solution;
        }
    }

    if(d[end_vert] != INT_MAX){
        int path_edges = 0;
        int next_vert = p[end_vert];
        if(end_vert != start_vert){
            path_edges++;
            while(next_vert != start_vert){
                path_edges++;
                next_vert = p[next_vert];
            }
        }
        solution.setGraph(vertices,path_edges);
        path_edges = 0;
        next_vert = end_vert;
        if(end_vert != start_vert){
            while(next_vert != start_vert){
                solution.addDirectedEdge(path_edges,p[next_vert],next_vert,d[next_vert]-d[p[next_vert]]);
                path_edges++;
                next_vert = p[next_vert];
            }
        }
    }
    else{
        printf("Nie istnieje sciezka o poczatku w (%d) i koncu w (%d)\n",start_vert,end_vert);
        solution.setGraph(0,0);
    }
    return solution;
}

ListGraph Shortest_path::Dijkstra_L(ListGraph &graph, int start_vert, int end_vert){
    int vertices = graph.V;

    ListGraph solution;
    solution.setGraph(vertices, vertices-1);

    bool visited[vertices];
    int d[vertices];
    int p[vertices];
    for(int v=0;v<vertices;v++){
        visited[v] = false;
        d[v] = INT_MAX; //INT_MAX
        p[v] = -1;
    }
    d[start_vert] = 0;
    for(int x=0;x<vertices;x++){
        int u = -1;
        // szukanie nierozpatrywanego wierzcholka o najmniejszej odleglosci (bez zastosowania kolejki)
        for(int i=0;i<vertices;i++) {
            if (!visited[i] && (u==-1 || d[i]<d[u])){u = i;}
        }
        visited[u] = true;

        AdjListNode* u_vert = graph.arr[u].head;
        while(u_vert){ //petla do proby relaksacji wszystkich krawedzi wychodzacych z rozpatrywanego wierzcholka
            int v = u_vert->dest;
            if(!visited[v] && d[v] > d[u] + u_vert->weight && d[u] != INT_MAX) {
                d[v] = d[u] + u_vert->weight;
                p[v] = u;
            }
            u_vert = u_vert->next;
        }
    }
    if(d[end_vert] != INT_MAX){
        int path_edges = 0;
        int next_vert = p[end_vert];
        if(end_vert != start_vert){
            path_edges++;
            while(next_vert != start_vert){
                path_edges++;
                next_vert = p[next_vert];
            }
        }
        solution.setGraph(vertices,path_edges);
        next_vert = end_vert;
        if(end_vert != start_vert){
            while(next_vert != start_vert){
                solution.addDirectedEdge(p[next_vert],next_vert,d[next_vert]-d[p[next_vert]]);
                next_vert = p[next_vert];
            }
        }
    }
    else{
        printf("Nie istnieje sciezka o poczatku w (%d) i koncu w (%d)\n",start_vert,end_vert);
        solution.setGraph(0,0);
    }
    return solution;
}
ListGraph Shortest_path::Ford_Bellman_L(ListGraph &graph, int start_vert, int end_vert){
    int vertices = graph.V;

    ListGraph solution;

    int d[vertices];
    int p[vertices];
    for(int v=0;v<vertices;v++){
        d[v] = INT_MAX; //INT_MAX
        p[v] = -1;
    }
    d[start_vert] = 0;

    int u,v;
    for(int i=1;i<vertices;i++){ //petla wykonujaca sie v-1 razy
        for(int j=0;j<vertices;j++){ //petla do proby relaksacji kazdej z krawedzi (podejmowana jest proba relaksacji kazdej z krawedzi wychodzacej z aktualnego wierzcholka, a nastepnie wybierany jes kolejny wierzcholek)

            AdjListNode* u_vert = graph.arr[j].head;
            if(u_vert){
               u = u_vert->source;
                while(u_vert){ //proba relaksacji wszystkich krawedzi wychodzacych z aktualnego wierzcholka
                    v = u_vert->dest;
                    if(d[v] > d[u] + u_vert->weight && d[u] != INT_MAX) {
                        d[v] = d[u] + u_vert->weight;
                        p[v] = u;
                    }
                    u_vert = u_vert->next;
                }
            }
        }
    }

    for(int j=0;j<vertices;j++){
        AdjListNode* u_vert = graph.arr[v].head;
        if(u_vert){
            u = u_vert->source;
            while(u_vert){
                v = u_vert->dest;
                if(d[v] > d[u] + u_vert->weight && d[u] != INT_MAX) {
                    std::cout << "Nieprawidlowa droga! Wystapil cykl ujemny!\n"; solution.setGraph(0,0); return solution;
                }
                u_vert = u_vert->next;
            }
        }
    }
    if(d[end_vert] != INT_MAX){
        int path_edges = 0;
        int next_vert = p[end_vert];
        if(end_vert != start_vert){
            path_edges++;
            while(next_vert != start_vert){
                path_edges++;
                next_vert = p[next_vert];
            }
        }
        solution.setGraph(vertices,path_edges);
        next_vert = end_vert;
        if(end_vert != start_vert){
            while(next_vert != start_vert){
                solution.addDirectedEdge(p[next_vert],next_vert,d[next_vert]-d[p[next_vert]]);
                next_vert = p[next_vert];
            }
        }
    }
    else{
        printf("Nie istnieje sciezka o poczatku w (%d) i koncu w (%d)\n",start_vert,end_vert);
        solution.setGraph(0,0);
    }
    return solution;
}
