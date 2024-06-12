#ifndef OPTIONS_H
#define OPTIONS_H

#include <iostream>
#include <fstream>
#include <algorithm>
#include <chrono>
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
int problem_type = -1;

    void create_matrix();

    bool load_graph();

    void generate_graph_info();
    void generate_graph(int vertices, int density);

    bool check_edge(int src, int dest);

    void show_graph();

    void choose_algorithm_info(bool input);
    void choose_algorithm(bool results);
    double matrix_algorithms(bool results);
    double list_algorithms(bool results);

    void serie();
    virtual ~Options();

private:
};

#endif // OPTIONS_H
