#pragma once
#include <vector>
#include "../visualizer.h"

/**
 * @class BubbleSort
 * @brief Bubble Sort implementation - O(n²)
 */
class BubbleSort {
public:
    static void sort(std::vector<int>& arr, Visualizer* viz) {
        int n = arr.size();
        
        for (int i = 0; i < n - 1; i++) {
            bool swapped = false;
            
            for (int j = 0; j < n - i - 1; j++) {
                viz->compare(j, j + 1);
                
                if (arr[j] > arr[j + 1]) {
                    viz->swap(j, j + 1);
                    std::swap(arr[j], arr[j + 1]);
                    swapped = true;
                }
            }
            
            viz->mark(n - i - 1, "green");
            
            if (!swapped) break; // Array is sorted
        }
    }
};
