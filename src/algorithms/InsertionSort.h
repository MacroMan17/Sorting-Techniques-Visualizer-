#pragma once
#include <vector>
#include "../visualizer.h"

/**
 * @class InsertionSort
 * @brief Insertion Sort implementation - O(n²)
 */
class InsertionSort {
public:
    static void sort(std::vector<int>& arr, Visualizer* viz) {
        int n = arr.size();
        
        for (int i = 1; i < n; i++) {
            int key = arr[i];
            int j = i - 1;
            
            while (j >= 0 && arr[j] > key) {
                viz->compare(j, i);
                arr[j + 1] = arr[j];
                viz->swap(j, j + 1);
                j--;
            }
            
            arr[j + 1] = key;
            viz->mark(i, "green");
        }
    }
};
