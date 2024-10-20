#ifndef TSPRANDOM_H
#define TSPRANDOM_H

#include <vector>
#include <climits>
#include <time.h>
#include <random>
#include <algorithm>

class TSPrandom
{
    public:
        int calculateDistance(const std::vector<int>& path, int** matrix);
        int algorithm(int** matrix, int matrixS, int iterations);

    protected:

    private:
};

#endif // TSPRANDOM_H
