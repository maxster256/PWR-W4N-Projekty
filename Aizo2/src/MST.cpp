#include "MST.h"

void MST::Prim(IncidenceGraph &graph, bool show_res){
    int vertices = graph.V;
    int edges = graph.E;

    bool visited[vertices];
    int key[vertices];
    int p[vertices];
    for(int v=0;v<vertices;v++){
        visited[v] = false;
        key[v] = 2147483647; //INT_MAX
        p[v] = -1;
    }
    key[0] = 0;
    p[0] = -1;

    for(int x=0;x<vertices;x++){
        int u = -1;
        // wybieranie kolejnego wierzcholka bez uzycia kolejki
        for(int i=0;i<vertices;i++) {
            if (!visited[i] && (u==-1 || key[i]<key[u])){u = i;}
        }
        visited[u] = true;

        for(int e=0;e<edges;e++){
            if(graph.incMatrix[u][e]==1){ //jesli istnieje krawedz z wybranego wierzcholka
                for(int v=0;v<vertices;v++){ //odnalezienie konca krawedzi
                    if(!visited[v] && graph.incMatrix[v][e] == 1 && graph.incMatrix[u][e] * graph.weights[e] < key[v]){
                        key[v] = graph.incMatrix[u][e] * graph.weights[e];
                        p[v] = u;
                    }
                }
            }
        }
    }

    if(show_res){
        printf("\n\n=== Reprezentacja macierzowa ===\n");
        printf("Uzyskane drzewo\n\n0 jest wierzcholkiem poczatkowym\n");
        int sum = 0;
        for(int i=1;i<vertices;i++){
            printf("Krawedz %d - %d | waga krawedzi: %d\n",i,p[i],key[i]);
            sum+=key[i];
        }

        printf("Calkowita waga drzewa: %d",sum);
        printf("\n\n================================\n");
    }
}

void MST::Kruskal(IncidenceGraph &graph, bool show_res){
    int vertices = graph.V;
    int edges = graph.E;

    int p[vertices];
    int ranks[vertices];
    int sortedEdgesID[edges]; //tablica przechowujaca indeksy krawedzi posortowanych
    int finaltree[vertices-1]; // tablica do przechowania indeksow krawedzi tworzacych drzewo MST
    for(int v=0;v<vertices;v++){
        p[v] = v;
        ranks[v] = 0;
    }
    for(int e=0;e<edges;e++){
        sortedEdgesID[e]=e;
    }
    //wykonanie sortowania krawedzi (sortowaniem szybkim)
    sortEdgesByQuick(graph.weights,sortedEdgesID,0,edges-1);

    int treeEdge = 0;
    for(int e=0;e<edges;e++){
        int u = -1, v = -1,vert = 0;
        do{ //petla do znalezienia zrodla i konca aktualnie rozpatrywanej krawedzi
            if(graph.incMatrix[vert][sortedEdgesID[e]] != 0){
                if(u != -1){v = vert; break;}
                u = vert;
            }
            vert++;
        }while(u == -1 || v == -1);
        //sprawdzenie czy grafu do ktorych naleza wierzcholki sa juz polaczone
        if(FindSet(u,p) != FindSet(v,p)){
            finaltree[treeEdge] = sortedEdgesID[e]; //dodanie krawedzi do rozwiazania
            treeEdge++;
            Union(u,v,p,ranks); //laczenie grafow, ktorych czescia sa wierzcholki
        }
    }
    if(show_res){
        printf("\n\n=== Reprezentacja macierzowa ===\n");
        printf("Krawedzie tworzace drzewo:\n");
        int totalWeight = 0;
        for(int e=0;e<edges;e++){
            for(int i=0;i<vertices-1;i++){
                if(finaltree[i] == e){
                    int vert = 0;
                    while(graph.incMatrix[vert][e] == 0){vert++;}
                        printf("Krawedz %d - ",vert);
                    do{vert++;}while(graph.incMatrix[vert][e] == 0);
                    printf("%d | Waga krawedzi: %d\n",vert,graph.incMatrix[vert][e] * graph.weights[e]);
                    totalWeight+=graph.incMatrix[vert][e] * graph.weights[e];
                }
            }
        }
        printf("Calkowita waga drzewa to %d",totalWeight);
        printf("\n\n================================\n");
    }
}

void MST::Prim_L(ListGraph &graph, bool show_res){
    int vertices = graph.V;

    bool visited[vertices];
    int key[vertices];
    int p[vertices];
    for(int v=0;v<vertices;v++){
        visited[v] = false;
        key[v] = 2147483647; //INT_MAX
        p[v] = -1;
    }
    key[0] = 0;
    p[0] = -1;

    for(int x=0;x<vertices;x++){
        int u = -1;
        // wybieranie kolejnego wierzcholka bez uzycia kolejki
        for(int i=0;i<vertices;i++) {
            if (!visited[i] && (u==-1 || key[i]<key[u])){u = i;}
        }
        visited[u] = true;

        AdjListNode* neighborNodes = graph.arr[u].head;
        while(neighborNodes){ //sprawdzenie wszystkich krawedzi wychodzacych z aktualnego wierzcholka
            int node = neighborNodes->dest;
            if(u!=node && !visited[node] && neighborNodes->weight < key[node]){
                key[node] = neighborNodes->weight;
                p[node] = u;
            }
            neighborNodes = neighborNodes->next;
        }
    }
    if(show_res){
        printf("\n\n==== Reprezentacja listowa ====\n");
        printf("Uzyskane drzewo\n\n0 jest wierzcholkiem poczatkowym\n");
        int sum = 0;
        for(int i=1;i<vertices;i++){
            printf("Krawedz %d - %d | waga krawedzi: %d\n",i,p[i],key[i]);
            sum+=key[i];
        }
        printf("Calkowita waga drzewa: %d",sum);
        printf("\n\n==============================\n");
    }
}

void MST::Kruskal_L(ListGraph &graph, bool show_res){
    int vertices = graph.V;
    int edges = graph.E;

    int p[vertices];
    int ranks[vertices];
    int finaltree[vertices-1]; //tablica do przechowania indeksow krawedzi tworzacych rozwiazanie
    int sortedEdgesID[edges];
    AdjListNode* listed_edges[edges]; //tablica do przechowania wszystkich polaczen w postaci latwej do sortowania

    int index = 0;
    AdjListNode* nod;
    for(int v=0;v<vertices;v++){
        nod = graph.arr[v].head;
        while(nod){
            listed_edges[index] = nod;
            index++;
            nod = nod->next;
        }
    }

    for(int v=0;v<vertices;v++){
        p[v] = v;
        ranks[v] = 0;
    }
    for(int e=0;e<edges;e++){
        sortedEdgesID[e]=e;
    }

    sortEdgesByQuick_L(listed_edges,sortedEdgesID,0,edges-1);

    int treeEdge = 0;
    for(int e=0;e<edges;e++){
        // poczatek oraz koniec polaczenia pobierany ze struktury
        int u = listed_edges[sortedEdgesID[e]]->source;
        int v = listed_edges[sortedEdgesID[e]]->dest;

        if(FindSet(u,p) != FindSet(v,p)){
            finaltree[treeEdge] = sortedEdgesID[e];
            treeEdge++;
            Union(u,v,p,ranks);
        }
    }
    if(show_res){
        printf("\n\n==== Reprezentacja listowa ====\n");
        printf("Krawedzie tworzace drzewo:\n");
        int totalWeight = 0;
        for(int e=0;e<edges;e++){
            for(int i=0;i<vertices-1;i++){
                if(finaltree[i] == e){
                    printf("Krawedz %d - %d | Waga krawedzi: %d\n",listed_edges[e]->source,listed_edges[e]->dest,listed_edges[e]->weight);
                    totalWeight+=listed_edges[e]->weight;
                }
            }
        }
        printf("Calkowita waga drzewa to %d",totalWeight);
        printf("\n\n==============================\n");
    }
}

int MST::FindSet(int x, int parent[]){
    if(parent[x] != x){
        parent[x] = FindSet(parent[x],parent);
    }
    return parent[x];
}

void MST::Union(int x, int y, int parent[], int ranks[]){
    int a = FindSet(x,parent);
    int b = FindSet(y,parent);
    if(ranks[a]<ranks[b]){
        parent[a]=b;
    }
    else{
        parent[b]=a;
    }
    if(ranks[a]==ranks[b]){
        ranks[a]++;
    }
}

void MST::sortEdgesByQuick(int EdgesWeights[],int edgesID[],int l, int r){
    if(l>=r)    {return;}
    int m = partitioned(EdgesWeights, edgesID, l, r);
    sortEdgesByQuick(EdgesWeights, edgesID, l, m);
    sortEdgesByQuick(EdgesWeights, edgesID, m+1, r);
}

int MST::partitioned(int EdgesWeights[],int edgesID[],int left, int right){
    int pivot = EdgesWeights[edgesID[(left+right)/2]];
    int l=left; int r = right;
    while(true){
        while(EdgesWeights[edgesID[l]]<pivot){l++;}
        while(EdgesWeights[edgesID[r]]>pivot){r--;}
        if(l < r){
            std::swap(edgesID[l],edgesID[r]);
            l++;
            r--;
        }
        else{
            if (r == right) {r--;}
            return r;
        }
    }
}

void MST::sortEdgesByQuick_L(AdjListNode* listed_edges[],int edgesID[],int l, int r){
    if(l>=r)    {return;}
    int m = partitioned_L(listed_edges, edgesID, l, r);
    sortEdgesByQuick_L(listed_edges, edgesID, l, m);
    sortEdgesByQuick_L(listed_edges, edgesID, m+1, r);
}

int MST::partitioned_L(AdjListNode* listed_edges[],int edgesID[],int left, int right){
    int pivot = listed_edges[edgesID[(left+right)/2]]->weight;
    int l=left; int r = right;
    while(true){
        while(listed_edges[edgesID[l]]->weight<pivot){l++;}
        while(listed_edges[edgesID[r]]->weight>pivot){r--;}
        if(l < r){
            std::swap(edgesID[l],edgesID[r]);
            l++;
            r--;
        }
        else{
            if (r == right) {r--;}
            return r;
        }
    }
}
