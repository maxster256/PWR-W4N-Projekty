#ifndef OPTIONS_H
#define OPTIONS_H
#include "Input.h"

class Options : public Input{
public:
bool isGenerated = false;
short algorithm_type = -1;
short algorithm = -1;

    void load_graph();
    void generate_graph();
    void show_graph();
    void choose_algorithm();
private:
};

#endif // OPTIONS_H
