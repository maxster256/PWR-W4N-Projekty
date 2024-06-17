#ifndef INCIDENCEGRAPH_H
#define INCIDENCEGRAPH_H
#include <iostream>

class IncidenceGraph
{
    public:
    int V=-1, E=-1;
    int* weights = nullptr;
    int** incMatrix = nullptr;

        void setGraph(int V, int E);
        void copy_solution(IncidenceGraph &dest_graph);
        void addEdge(int edgeIndex, int src, int dest, int weight);
        void addDirectedEdge(int edgeIndex, int src, int dest, int weight);
        void printGraph();
        ~IncidenceGraph();

    protected:

    private:
};

#endif // INCIDENCEGRAPH_H
