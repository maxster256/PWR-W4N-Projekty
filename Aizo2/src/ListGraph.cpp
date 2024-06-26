#include "ListGraph.h"

void ListGraph::setGraph(int V, int E){
    this->V = V;
    this->E = 2*E;
    arr = new AdjList[V];
    for(int i = 0; i < V; i++) {
        arr[i].head = nullptr;
    }
}

void ListGraph::copy_solution(ListGraph &dest_graph, bool isDirected){
    dest_graph.setGraph(this->V, this->E);
    for(int v=0;v<dest_graph.V;v++){
        AdjListNode* edgesToCopy = this->arr[v].head;
        while(edgesToCopy){
            if(isDirected){
                dest_graph.addDirectedEdge(edgesToCopy->source, edgesToCopy->dest, edgesToCopy->weight);
            }
            else if(edgesToCopy->source < edgesToCopy->dest){
                dest_graph.addEdge(edgesToCopy->source, edgesToCopy->dest, edgesToCopy->weight);
            }
            edgesToCopy = edgesToCopy->next;
        }
    }
}

void ListGraph::addEdge(int src, int dest, int weight){
    AdjListNode* newNode = new AdjListNode;
    newNode->source = src;
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = arr[src].head;
    arr[src].head = newNode;

    newNode = new AdjListNode;
    newNode->source = dest;
    newNode->dest = src;
    newNode->weight = weight;
    newNode->next = arr[dest].head;
    arr[dest].head = newNode;
}

void ListGraph::addDirectedEdge(int src, int dest, int weight){
    AdjListNode* newNode = new AdjListNode;
    newNode->source = src;
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = arr[src].head;
    arr[src].head = newNode;
}

void ListGraph::printGraph(){
    printf("Lista sasiedztwa: (Cel:Waga)\n");
    for(int v = 0; v < V; v++){
        AdjListNode* pCrawl = arr[v].head;
        printf("Nastepnicy wierzcholka %d:",v);
        while(pCrawl){
            printf(" %d:%d ",pCrawl->dest,pCrawl->weight);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}

ListGraph::~ListGraph(){
    if(arr != nullptr){
        for (int v = 0; v < V; v++){
            AdjListNode* current = arr[v].head;
            while (current != nullptr) {
                AdjListNode* next = current->next;
                delete current;
                current = next;
            }
        }
        delete[] arr;
    }
}
