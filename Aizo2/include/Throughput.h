#ifndef THROUGHPUT_H
#define THROUGHPUT_H
#include <iostream>
#include <cstring>
#include "IncidenceGraph.h"
#include "ListGraph.h"

class Throughput
{
    public:
        void Ford_Fulkerson(IncidenceGraph &graph, int start_vert, int end_vert);
        bool bfs(IncidenceGraph &residualGraph, int start_vert, int end_vert, int parent[]);
    protected:

    private:
};

#endif // THROUGHPUT_H
