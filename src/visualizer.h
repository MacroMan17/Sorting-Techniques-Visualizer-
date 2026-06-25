#pragma once
#include <vector>
#include <string>
#include <chrono>
#include <iostream>

/**
 * @class Visualizer
 * @brief Main visualization engine for sorting algorithms
 */
class Visualizer {
private:
    int width, height;
    bool running;
    std::vector<int> array;
    std::string currentAlgorithm;
    bool isPaused;
    int speed; // 1-100
    
    // Statistics
    long long comparisons;
    long long swaps;
    std::chrono::high_resolution_clock::time_point startTime;
    
public:
    Visualizer(int w, int h) 
        : width(w), height(h), running(true), isPaused(false), speed(50),
          comparisons(0), swaps(0) {
        startTime = std::chrono::high_resolution_clock::now();
        initializeArray(100);
    }
    
    bool isRunning() const { return running; }
    void handleInput() {
        // TODO: Implement input handling
        // For now, just allow running for demonstration
    }
    
    void update() {
        // TODO: Implement update logic
    }
    
    void render() {
        // TODO: Implement rendering
        // For now, just update terminal output periodically
        static int frameCount = 0;
        if (++frameCount % 100 == 0) {
            std::cout << "Frame: " << frameCount << std::endl;
        }
    }
    
    // Callback functions for algorithms
    void compare(int i, int j) {
        comparisons++;
        std::cout << "Comparing " << array[i] << " and " << array[j] << std::endl;
    }
    
    void swap(int i, int j) {
        swaps++;
        std::swap(array[i], array[j]);
        std::cout << "Swapping positions " << i << " and " << j << std::endl;
    }
    
    void mark(int i, const std::string& color) {
        // TODO: Mark element with color for visualization
        std::cout << "Marking index " << i << " as " << color << std::endl;
    }
    
    std::vector<int>& getArray() { return array; }
    
    long long getComparisons() const { return comparisons; }
    long long getSwaps() const { return swaps; }
    
    void resetStatistics() {
        comparisons = 0;
        swaps = 0;
        startTime = std::chrono::high_resolution_clock::now();
    }
    
    double getElapsedTime() const {
        auto now = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(now - startTime);
        return duration.count() / 1000.0;
    }
    
    void setPaused(bool paused) { isPaused = paused; }
    bool getPaused() const { return isPaused; }
    
    void setSpeed(int s) { speed = (s < 1) ? 1 : (s > 100) ? 100 : s; }
    int getSpeed() const { return speed; }
    
    void printStatistics() const {
        std::cout << "=============== Statistics ===============" << std::endl;
        std::cout << "Comparisons: " << comparisons << std::endl;
        std::cout << "Swaps: " << swaps << std::endl;
        std::cout << "Time: " << getElapsedTime() << "s" << std::endl;
        std::cout << "Array Size: " << array.size() << std::endl;
        std::cout << "=========================================" << std::endl;
    }
    
private:
    void initializeArray(int size) {
        array.clear();
        array.reserve(size);
        
        // Generate random array
        for (int i = 0; i < size; i++) {
            array.push_back(rand() % (size * 2));
        }
    }
};
