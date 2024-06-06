#include "Shortest_path.h"

void Shortest_path::Dijkstra(IncidenceGraph &graph, int start_vert, int end_vert, bool show_res){
    int vertices = graph.V;
    int edges = graph.E;

    bool visited[vertices];
    int d[vertices];
    int p[vertices];
    for(int v=0;v<vertices;v++){
        visited[v] = false;
        d[v] = 2147483647; //INT_MAX
        p[v] = -1;
    }
    d[start_vert] = 0;
    for(int x=0;x<vertices;x++){
        int u = -1;
        for(int i=0;i<vertices;i++) {
            if (!visited[i] && (u==-1 || d[i]<d[u])){u = i;}
        }
        visited[u] = true;

        if(u == end_vert){
            if(show_res){
                std::cout << "Uzyskany koszt: " << d[u] << "\n\n";
                printf("Znaleziona sciezka (poczatek od prawej)\n%d - ",u);
                while(p[u] != start_vert){
                    printf("%d - ",p[u]);
                    p[u] = p[p[u]];
                }
                printf("%d\n",p[u]);
            }
            return;
        }
        for(int j=0;j<edges;j++) {
            if(graph.incMatrix[u][j] == 1){
                for(int v=0; v<vertices; v++){
                    if(graph.incMatrix[v][j] == -1) {
                        //int weight = graph.incMatrix[v][j] * (-1);
                        if(!visited[v] && d[v] > d[u] + graph.weights[j]) {
                            d[v] = d[u] + graph.weights[j];
                            p[v] = u;
                        }
                    }
                }
            }
        }
    }
}

void Shortest_path::Ford_Bellman(IncidenceGraph &graph, int start_vert, int end_vert, bool show_res){
    int vertices = graph.V;
    int edges = graph.E;

    int d[vertices];
    int p[vertices];
    for(int v=0;v<vertices;v++){
        d[v] = 2147483647; //INT_MAX
        p[v] = -1;
    }
    d[start_vert] = 0;
    for(int i=1;i<vertices;i++){
        //bool relaxed = false;
        for(int e=0;e<edges;e++){
            int u = -1, v = -1, vert = 0;
            while(u == -1 || v == -1){
                if(graph.incMatrix[vert][e] > 0){
                        u = vert;
                }
                else if(graph.incMatrix[vert][e] < 0){
                        v = vert;
                } // u source ; v destination
                vert++;
            }
            if (d[v] > d[u] + graph.weights[e]){
                d[v] = d[u] + graph.weights[e];
                p[v] = u;
                //relaxed = true;
            }
        }
        //if(relaxed){break;}
    }
    if(show_res){
        std::cout << "Uzyskany koszt: " << d[end_vert] << "\n\n";
        printf("Znaleziona sciezka (poczatek od prawej)\n%d - ",end_vert);
        while(p[end_vert] != start_vert){
            printf("%d - ",p[end_vert]);
            p[end_vert] = p[p[end_vert]];
        }
        printf("%d\n",p[end_vert]);
    }
    return;

}
