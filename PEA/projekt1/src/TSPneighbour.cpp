#include "TSPneighbour.h"

int TSPneighbour::algorithm(int** matrix, int matrixS){
    std::vector<bool> visited(matrixS, false);
    int currentCity = 0;
    visited[currentCity] = true;
    int totalDistance = 0;

    for(int i=0; i<matrixS-1; i++){
        int nextCity = -1;
        int minDistance = INT_MAX;
        for(int j=0; j<matrixS; j++){
            if(!visited[j] && matrix[currentCity][j] < minDistance){
                minDistance = matrix[currentCity][j];
                nextCity = j;
            }
        }
        visited[nextCity] = true;
        totalDistance += minDistance;
        currentCity = nextCity;
    }
    // Powrót do miasta poczatkowego
    totalDistance += matrix[currentCity][0];
    return totalDistance;
}
