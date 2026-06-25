#pragma once
#include <string>
#include <iostream>

/**
 * @struct AlgorithmStats
 * @brief Statistics for a sorting algorithm run
 */
struct AlgorithmStats {
    std::string algorithmName;
    long long comparisons;
    long long swaps;
    long long arrayAccesses;
    double timeMs;
    int arraySize;
    
    AlgorithmStats(const std::string& name = "", int size = 0)
        : algorithmName(name), comparisons(0), swaps(0), arrayAccesses(0),
          timeMs(0), arraySize(size) {}
    
    void print() const {
        std::cout << "===== " << algorithmName << " =====" << std::endl;
        std::cout << "Array Size: " << arraySize << std::endl;
        std::cout << "Comparisons: " << comparisons << std::endl;
        std::cout << "Swaps: " << swaps << std::endl;
        std::cout << "Array Accesses: " << arrayAccesses << std::endl;
        std::cout << "Time: " << timeMs << " ms" << std::endl;
        std::cout << std::endl;
    }
    
    double getOperationsPerSecond() const {
        if (timeMs == 0) return 0;
        return (comparisons + swaps) / (timeMs / 1000.0);
    }
};
