#pragma once
#include <vector>
#include "../visualizer.h"

/**
 * @class SelectionSort
 * @brief Selection Sort implementation - O(n²)
 */
class SelectionSort {
public:
    static void sort(std::vector<int>& arr, Visualizer* viz) {
        int n = arr.size();
        
        for (int i = 0; i < n - 1; i++) {
            int minIdx = i;
            
            for (int j = i + 1; j < n; j++) {
                viz->compare(minIdx, j);
                
                if (arr[j] < arr[minIdx]) {
                    minIdx = j;
                }
            }
            
            if (minIdx != i) {
                viz->swap(i, minIdx);
                std::swap(arr[i], arr[minIdx]);
            }
            
            viz->mark(i, "green");
        }
    }
};
