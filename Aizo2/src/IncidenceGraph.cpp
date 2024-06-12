#include "IncidenceGraph.h"

void IncidenceGraph::setGraph(int V, int E){
    this->V = V;
    this->E = E;
    incMatrix = new int*[V];
    weights = new int[E];
    for(int i = 0; i < V; ++i){
        if(V>900){printf("%d\n",i);}
        incMatrix[i] = new int[E];
        for(int j = 0; j < E; ++j){
            incMatrix[i][j] = 0;
        }
    }
}

void IncidenceGraph::addEdge(int edgeIndex, int src, int dest, int weight) {
    if(src == dest) {incMatrix[src][edgeIndex] = 2; return;}
    if(edgeIndex < E && src < V && dest < V){
        incMatrix[src][edgeIndex] = 1;
        incMatrix[dest][edgeIndex] = 1;
        weights[edgeIndex] = weight;
    }
}

void IncidenceGraph::addDirectedEdge(int edgeIndex, int src, int dest, int weight){
    if(src == dest) {incMatrix[src][edgeIndex] = 2; return;}
    if(edgeIndex < E && src < V && dest < V){
        incMatrix[src][edgeIndex] = 1;
        incMatrix[dest][edgeIndex] = -1;
        weights[edgeIndex] = weight;
    }
}

void IncidenceGraph::printGraph(){
    printf("Macierz incydencji:\n");
    printf("Wagi:");
    for(int i=0;i<E;i++){
        printf("%6d",weights[i]);
    }
    printf("\n     ");
    for(int i=0;i<E;i++){
        printf("|k%-4d",i);
    }
    printf("\n");
    for(int i=0;i<V;i++){
        printf("v%-4d",i);
        for(int j=0;j<E;j++){
            printf("|%5d",incMatrix[i][j]);
        }
        printf("\n");
    }
}

IncidenceGraph::~IncidenceGraph(){
    if(incMatrix != nullptr){
        for (int i = 0; i < V; i++) {
            delete[] incMatrix[i];
        }
        delete[] incMatrix;
    }
    if(weights != nullptr){
        delete[] weights;
    }
}
