#ifndef OPTIONS_H
#define OPTIONS_H

#include <iostream>
#include <fstream>
#include <algorithm>
#include <chrono>
#include <climits>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <random>

#include "Input.h"
#include "TSPfull.h"
#include "TSPneighbour.h"
#include "TSPrandom.h"

class Options
{
    public:
        std::string text_file;
        int matrix_size, algorithm, symmetric, iterations = 1000;
        // asymetryczny 1, symetryczny 2
        int removed_matrix_size, cycle_length;
        int** TSPmatrix = nullptr;
        bool isGenerated = false;

        Input inputC;

        void create_matrix(int mSize);
        void remove_matrix();
        void set_iterations_num(int m_size);
        bool load_graph();
        void generate_graph_info();
        void generate_graph(int matrix_s);
        void show_graph();
        bool choose_algorithm_info(bool input);
        void choose_algorithm(bool results);
        void print_solution(int alg, int solution);
        double matrix_algorithms();
        void serie();

        virtual ~Options();

    protected:

    private:
};

#endif // OPTIONS_H
