#ifndef TSPFULL_H
#define TSPFULL_H

#include <vector>
#include <climits>
#include <algorithm>

class TSPfull
{
    public:
        void next_perm(std::vector<int>& verts, int** matrix, int &minDistance, int x, int matrixS);
        int calculateDistance(std::vector<int>& path, int** matrix, int minDistance, int matrixS);
        int algorithm(int** matrix, int matrixS);

    protected:

    private:
};

#endif // TSPFULL_H
