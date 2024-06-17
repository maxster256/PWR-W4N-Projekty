#ifndef SHORTEST_PATH_H
#define SHORTEST_PATH_H
#include <iostream>
#include <limits.h>
#include "IncidenceGraph.h"
#include "ListGraph.h"

class Shortest_path
{
    public:
        IncidenceGraph Dijkstra(IncidenceGraph &graph, int start_vert, int end_vert);
        IncidenceGraph Ford_Bellman(IncidenceGraph &graph, int start_vert, int end_vert);

        ListGraph Dijkstra_L(ListGraph &graph, int start_vert, int end_vert);
        ListGraph Ford_Bellman_L(ListGraph &graph, int start_vert, int end_vert);
    protected:

    private:
};

#endif // SHORTEST_PATH_H
