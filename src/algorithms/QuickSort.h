#pragma once
#include <vector>
#include "../visualizer.h"

/**
 * @class QuickSort
 * @brief Quick Sort implementation - O(n log n) average, O(n²) worst
 */
class QuickSort {
public:
    static void sort(std::vector<int>& arr, Visualizer* viz) {
        quickSort(arr, 0, arr.size() - 1, viz);
    }
    
private:
    static void quickSort(std::vector<int>& arr, int low, int high, Visualizer* viz) {
        if (low < high) {
            int pi = partition(arr, low, high, viz);
            
            quickSort(arr, low, pi - 1, viz);
            quickSort(arr, pi + 1, high, viz);
        }
    }
    
    static int partition(std::vector<int>& arr, int low, int high, Visualizer* viz) {
        int pivot = arr[high];
        int i = low - 1;
        
        for (int j = low; j < high; j++) {
            viz->compare(j, high);
            
            if (arr[j] < pivot) {
                i++;
                viz->swap(i, j);
                std::swap(arr[i], arr[j]);
            }
        }
        
        viz->swap(i + 1, high);
        std::swap(arr[i + 1], arr[high]);
        return i + 1;
    }
};
