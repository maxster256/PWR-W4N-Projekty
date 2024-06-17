#ifndef MST_H
#define MST_H
#include <iostream>
#include "IncidenceGraph.h"
#include "ListGraph.h"

class MST
{
    public:
        IncidenceGraph Prim(const IncidenceGraph &graph);
        IncidenceGraph Kruskal(const IncidenceGraph &graph);

        ListGraph Prim_L(const ListGraph &graph);
        ListGraph Kruskal_L(const ListGraph &graph);

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
