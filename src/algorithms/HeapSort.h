#pragma once
#include <vector>
#include "../visualizer.h"

/**
 * @class HeapSort
 * @brief Heap Sort implementation - O(n log n)
 */
class HeapSort {
public:
    static void sort(std::vector<int>& arr, Visualizer* viz) {
        int n = arr.size();
        
        // Build max heap
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(arr, n, i, viz);
        }
        
        // Extract elements from heap
        for (int i = n - 1; i > 0; i--) {
            viz->swap(0, i);
            std::swap(arr[0], arr[i]);
            
            heapify(arr, i, 0, viz);
            viz->mark(i, "green");
        }
    }
    
private:
    static void heapify(std::vector<int>& arr, int n, int i, Visualizer* viz) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        
        if (left < n) {
            viz->compare(left, largest);
            if (arr[left] > arr[largest]) {
                largest = left;
            }
        }
        
        if (right < n) {
            viz->compare(right, largest);
            if (arr[right] > arr[largest]) {
                largest = right;
            }
        }
        
        if (largest != i) {
            viz->swap(i, largest);
            std::swap(arr[i], arr[largest]);
            heapify(arr, n, largest, viz);
        }
    }
};
