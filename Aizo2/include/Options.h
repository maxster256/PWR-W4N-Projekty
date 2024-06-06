#ifndef OPTIONS_H
#define OPTIONS_H
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Input.h"
#include "MST.h"
#include "Shortest_path.h"
#include "IncidenceGraph.h"
#include "ListGraph.h"

class Options : public Input{
private:
    MST mst;
    Shortest_path sp;
    //Throughput th;

    IncidenceGraph matrix;
    ListGraph lista;
public:

bool isGenerated = false;
short algorithm = -1;
std::string text_file;
int vertices = 0, edges = 0, density = 0;
int start_vert = 0, end_vert = 0;

    void create_matrix();

    bool load_graph(int problem_type);

    void generate_graph_info(int problem_type);
    void generate_graph(int problem_type);

    bool check_edge(int src, int dest);

    void show_graph();

    void choose_algorithm(int problem_type);
    virtual ~Options();

private:
};

#endif // OPTIONS_H
