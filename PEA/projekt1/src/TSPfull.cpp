#include "TSPfull.h"

//rekurencyjna funkcja do odnajdywania kolejnych permutacji
void TSPfull::next_perm(std::vector<int>& verts, int** matrix, int &minDistance, int x, int matrixS){
    if(x==0){
        minDistance = calculateDistance(verts, matrix, minDistance, matrixS);
    }
    else{
        for(int j=0;j<x;j++){
            std::swap(verts[j], verts[x-1]);
            next_perm(verts, matrix, minDistance, x-1, matrixS);
            std::swap(verts[j], verts[x-1]);
        }
    }
}

int TSPfull::calculateDistance(std::vector<int>& path, int** matrix, int minDistance, int matrixS){
    int currentDistance = 0;
    int currentCity = 0;

    for(int i=0; i<matrixS-1; i++){
        currentDistance += matrix[currentCity][path[i]];
        currentCity = path[i];
    }
    currentDistance += matrix[currentCity][0];  // Powrót do miasta poczatkowego
    minDistance = std::min(minDistance, currentDistance);
    return minDistance;
}

int TSPfull::algorithm(int** matrix, int matrixS){
    std::vector<int> cities;
    for (int i=1; i<matrixS; i++){
        cities.push_back(i);
    }
    int minDistance = INT_MAX;
    next_perm(cities, matrix, minDistance, matrixS - 1, matrixS);
    return minDistance;
}
