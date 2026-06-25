#pragma once
#include <chrono>

/**
 * @class Timer
 * @brief High-resolution timer for performance measurement
 */
class Timer {
private:
    std::chrono::high_resolution_clock::time_point startTime;
    
public:
    Timer() : startTime(std::chrono::high_resolution_clock::now()) {}
    
    void reset() {
        startTime = std::chrono::high_resolution_clock::now();
    }
    
    double elapsed() const {
        auto now = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(now - startTime);
        return duration.count() / 1000.0;
    }
    
    long long elapsedMillis() const {
        auto now = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(now - startTime);
        return duration.count();
    }
    
    long long elapsedMicros() const {
        auto now = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(now - startTime);
        return duration.count();
    }
};
