#ifndef SHORTEST_PATH_H
#define SHORTEST_PATH_H
#include <iostream>
#include <limits.h>
#include "IncidenceGraph.h"
#include "ListGraph.h"

class Shortest_path
{
    public:
        void Dijkstra(IncidenceGraph &graph, int start_vert, int end_vert, bool show_res);
        void Ford_Bellman(IncidenceGraph &graph, int start_vert, int end_vert, bool show_res);

        void Dijkstra_L(ListGraph &graph, int start_vert, int end_vert, bool show_res);
        void Ford_Bellman_L(ListGraph &graph, int start_vert, int end_vert, bool show_res);
    protected:

    private:
};

#endif // SHORTEST_PATH_H