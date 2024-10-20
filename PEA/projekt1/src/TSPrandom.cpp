#include "TSPrandom.h"

int TSPrandom::calculateDistance(const std::vector<int>& path, int** matrix){
    int totalDistance = 0;
    int currentCity = 0;
    for(unsigned i = 0; i < path.size(); i++){
        totalDistance += matrix[currentCity][path[i]];
        currentCity = path[i];
    }
    totalDistance += matrix[currentCity][0]; // Powrót do miasta poczatkowego
    return totalDistance;
}

int TSPrandom::algorithm(int** matrix, int matrixS, int iterations){
    std::vector<int> cities;
    for(int i=1; i<matrixS; i++){
        cities.push_back(i);
    }
    int minDistance = INT_MAX;
    unsigned seed;
    for(int i=0; i<iterations; i++){
        seed = rand();
        shuffle(cities.begin(), cities.end(), std::default_random_engine(seed));
        int currentDistance = calculateDistance(cities, matrix);
        minDistance = std::min(minDistance, currentDistance);
    }
    return minDistance;
}
