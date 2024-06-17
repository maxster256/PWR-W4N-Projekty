#include "Throughput.h"

void Throughput::Ford_Fulkerson(IncidenceGraph &graph, int start_vert, int end_vert){
    int vertices = graph.V;
    int edges = graph.E;

    IncidenceGraph residualGraph;
    residualGraph.setGraph(vertices,edges);
    for (int i=0; i<vertices; i++) {
        memcpy(residualGraph.incMatrix[i], graph.incMatrix[i], edges*sizeof(int));
    }
    for(int e=0;e<edges;e++){
        residualGraph.weights[e] = graph.weights[e];
    }


    int* parent = new int[vertices];
    int max_flow = 0;

    while(bfs(residualGraph, start_vert, end_vert, parent)){
        int path_flow = 2147483647; //INT_MAX
        for(int v=end_vert; v!=start_vert; v=parent[v]){
            int u = parent[v];
            for (int e=0; e <edges;e++){
                if (residualGraph.incMatrix[u][e] == 1 && residualGraph.incMatrix[v][e] == -1){
                    path_flow = std::min(path_flow, residualGraph.incMatrix[u][e] * residualGraph.weights[e]);
                }
            }
        }

        for(int v=end_vert; v!=start_vert; v=parent[v]){
            int u=parent[v];
            for (int e=0; e <edges; e++){
                if (residualGraph.incMatrix[u][e] == 1 && residualGraph.incMatrix[v][e] == -1){
                    residualGraph.incMatrix[v][e] = residualGraph.incMatrix[u][e];
                    residualGraph.incMatrix[u][e] = 0;
                } else if (residualGraph.incMatrix[u][e] == 1 && residualGraph.incMatrix[v][e] == -1){
                    residualGraph.incMatrix[u][e] = residualGraph.incMatrix[v][e];
                    residualGraph.incMatrix[v][e] = 0;
                }
            }
        }

        max_flow+=path_flow;
    }
    delete[] parent;

    printf("\n%d\n",max_flow);
}

bool Throughput::bfs(IncidenceGraph &residualGraph, int start_vert, int end_vert, int parent[]){
    int vertices = residualGraph.V;
    int edges = residualGraph.E;

    bool* visited = new bool[vertices];
    for(int i=0;i<vertices;i++){
        visited[i] = false;
    }
    memset(visited, 0, vertices * sizeof(bool));

    // Tablica symuluj¹ca kolejkê
    int* queue_ = new int[vertices];
    int front_ = 0, rear = 0;

    queue_[rear++] = start_vert;
    visited[start_vert] = true;
    parent[start_vert] = -1;

    while (front_ < rear) {
        int u = queue_[front_++];
        for (int e = 0; e <edges; e++){
            if(residualGraph.incMatrix[u][e] == 1){
                for(int v=0; v<vertices; v++){
                    if(!visited[v] && residualGraph.incMatrix[v][e] == -1){
                        if(v == end_vert){
                            parent[v] = u;
                            delete[] visited;
                            delete[] queue_;
                            return true;
                        }
                        queue_[rear++] = v;
                        parent[v] = u;
                        visited[v] = true;
                    }
                }
            }
        }
    }

    delete[] visited;
    delete[] queue_;
    return false;
}
