#pragma once
#include <vector>
#include "../visualizer.h"

/**
 * @class MergeSort
 * @brief Merge Sort implementation - O(n log n)
 */
class MergeSort {
public:
    static void sort(std::vector<int>& arr, Visualizer* viz) {
        mergeSort(arr, 0, arr.size() - 1, viz);
    }
    
private:
    static void mergeSort(std::vector<int>& arr, int left, int right, Visualizer* viz) {
        if (left < right) {
            int mid = left + (right - left) / 2;
            
            mergeSort(arr, left, mid, viz);
            mergeSort(arr, mid + 1, right, viz);
            merge(arr, left, mid, right, viz);
        }
    }
    
    static void merge(std::vector<int>& arr, int left, int mid, int right, Visualizer* viz) {
        std::vector<int> temp;
        int i = left, j = mid + 1;
        
        while (i <= mid && j <= right) {
            viz->compare(i, j);
            
            if (arr[i] <= arr[j]) {
                temp.push_back(arr[i++]);
            } else {
                temp.push_back(arr[j++]);
            }
        }
        
        while (i <= mid) temp.push_back(arr[i++]);
        while (j <= right) temp.push_back(arr[j++]);
        
        for (int k = left, idx = 0; k <= right; k++, idx++) {
            arr[k] = temp[idx];
            viz->mark(k, "yellow");
        }
    }
};
