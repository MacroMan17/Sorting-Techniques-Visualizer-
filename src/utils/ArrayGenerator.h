#pragma once
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>

/**
 * @class ArrayGenerator
 * @brief Generate test arrays with various patterns
 */
class ArrayGenerator {
public:
    enum Pattern {
        RANDOM,
        SORTED,
        REVERSE_SORTED,
        NEARLY_SORTED,
        FEW_UNIQUE
    };
    
    static std::vector<int> generate(int size, Pattern pattern) {
        std::vector<int> arr(size);
        std::mt19937 gen(time(0));
        std::uniform_int_distribution<> dis(1, size * 2);
        
        switch (pattern) {
            case RANDOM:
                for (int i = 0; i < size; i++) {
                    arr[i] = dis(gen);
                }
                break;
                
            case SORTED:
                for (int i = 0; i < size; i++) {
                    arr[i] = i;
                }
                break;
                
            case REVERSE_SORTED:
                for (int i = 0; i < size; i++) {
                    arr[i] = size - i;
                }
                break;
                
            case NEARLY_SORTED:
                for (int i = 0; i < size; i++) {
                    arr[i] = i;
                }
                // Shuffle 10%
                for (int i = 0; i < size / 10; i++) {
                    int idx1 = dis(gen) % size;
                    int idx2 = dis(gen) % size;
                    std::swap(arr[idx1], arr[idx2]);
                }
                break;
                
            case FEW_UNIQUE:
                for (int i = 0; i < size; i++) {
                    arr[i] = dis(gen) % 5; // Only 5 unique values
                }
                break;
        }
        
        return arr;
    }
};
