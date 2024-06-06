#ifndef MST_H
#define MST_H
#include <iostream>
#include "IncidenceGraph.h"
#include "ListGraph.h"

class MST
{
    public:
        void Prim(IncidenceGraph &graph, bool show_res);
        void Kruskal(IncidenceGraph &graph, bool show_res);

        void Prim_L(ListGraph &graph, bool show_res);
        void Kruskal_L(ListGraph &graph, bool show_res);

        int FindSet(int x, int parent[]);
        void Union(int x, int y, int parent[], int ranks[]);

        void sortEdgesByQuick(int EdgesWeights[],int edgesID[], int l, int r);
        int partitioned(int EdgesWeights[],int edgesID[], int left, int right);

        void sortEdgesByQuick_L(AdjListNode* listed_edges[],int edgesID[],int l, int r);
        int partitioned_L(AdjListNode* listed_edges[],int edgesID[],int left, int right);
    protected:

    private:
};

#endif // MST_H
