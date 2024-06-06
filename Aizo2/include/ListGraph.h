#ifndef LISTGRAPH_H
#define LISTGRAPH_H
#include <iostream>

struct AdjListNode {
    int source;
    int dest;
    int weight;
    AdjListNode* next = nullptr;
};

struct AdjList {
    AdjListNode* head;
};

class ListGraph{
    public:
    AdjList* arr = nullptr;
    int V = -1;
    int E = -1;

        void setGraph(int V, int E);
        void addEdge(int src, int dest, int weight);
        void addDirectedEdge(int src, int dest, int weight);
        void printGraph();
        ~ListGraph();

    protected:

    private:
};

#endif // LISTGRAPH_H
