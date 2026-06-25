#include <iostream>
#include <vector>
#include "visualizer.h"
#include "algorithms/BubbleSort.h"
#include "algorithms/SelectionSort.h"
#include "algorithms/InsertionSort.h"
#include "algorithms/MergeSort.h"
#include "algorithms/QuickSort.h"
#include "algorithms/HeapSort.h"

int main(int argc, char* argv[]) {
    std::cout << "Sorting Techniques Visualiser v1.0" << std::endl;
    std::cout << "===================================" << std::endl;
    std::cout << std::endl;
    
    // Initialize visualizer
    Visualizer viz(1024, 768);
    
    std::cout << "Available Algorithms:" << std::endl;
    std::cout << "  1. Bubble Sort" << std::endl;
    std::cout << "  2. Selection Sort" << std::endl;
    std::cout << "  3. Insertion Sort" << std::endl;
    std::cout << "  4. Merge Sort" << std::endl;
    std::cout << "  5. Quick Sort" << std::endl;
    std::cout << "  6. Heap Sort" << std::endl;
    std::cout << std::endl;
    
    // Test with sample data
    std::vector<int> testArray = {64, 34, 25, 12, 22, 11, 90, 88, 45, 50};
    
    std::cout << "Original array: ";
    for (int x : testArray) std::cout << x << " ";
    std::cout << std::endl << std::endl;
    
    // Run visualizer main loop
    while (viz.isRunning()) {
        viz.handleInput();
        viz.update();
        viz.render();
    }
    
    return 0;
}
