# Sorting Techniques Visualiser

A comprehensive interactive visualization tool for understanding and comparing sorting algorithms. Watch real-time animations of 10+ sorting algorithms side-by-side, analyze performance metrics, and learn algorithm behavior.

## 🎯 Features

### Sorting Algorithms Included
- **Bubble Sort** - O(n²) comparison-based
- **Selection Sort** - O(n²) in-place
- **Insertion Sort** - O(n²) adaptive
- **Merge Sort** - O(n log n) divide-and-conquer
- **Quick Sort** - O(n log n) average, O(n²) worst
- **Heap Sort** - O(n log n) guaranteed
- **Shell Sort** - O(n log n) to O(n²)
- **Counting Sort** - O(n+k) non-comparison
- **Radix Sort** - O(d·n) linear time
- **Bucket Sort** - O(n+k) average

### 📊 Visualization Features
- **Real-time animation** with adjustable speed
- **Step-by-step execution** - Pause and step through operations
- **Color-coded elements** - Show comparisons, swaps, sorted regions
- **Performance metrics** - Comparisons, swaps, memory usage in real-time
- **Array size control** - 10 to 1000 elements
- **Input patterns** - Random, nearly sorted, reversed, few unique values

### 📈 Analysis Tools
- **Performance comparison** - Run algorithms side-by-side
- **Complexity analysis** - Theoretical vs. actual performance
- **Statistics** - Track operations and performance
- **Export results** - Save benchmark data

---

## 🚀 Getting Started

### Requirements
- **C++17** compiler (GCC, Clang, MSVC)
- **CMake 3.10+**
- **Windows/Linux/macOS**

### Quick Start

```bash
# Clone repository
git clone https://github.com/YOUR_USERNAME/Sorting-Techniques-Visualiser.git
cd Sorting-Techniques-Visualiser

# Create build directory
mkdir build
cd build

# Build project
cmake .. -DCMAKE_BUILD_TYPE=Release
cmake --build .

# Run
./sorting_visualiser
```

---

## 💻 Usage Guide

### Basic Controls

| Action | Control |
|--------|---------|
| Play/Pause | Space or Click button |
| Speed Control | Arrow keys or slider |
| Reset | R key or Reset button |
| Randomize | Ctrl+R |
| Change Array Size | Input or slider |

### Algorithm Comparison

1. **Select algorithms** to compare
2. **Choose array size** and input pattern
3. **Click "Compare All"** to run simultaneously
4. **Watch visualizations** with synchronized timing
5. **Review statistics** in results panel

---

## 📊 Algorithm Details

### O(n²) Algorithms

#### Bubble Sort
- **Best:** O(n) - already sorted
- **Average:** O(n²)
- **Worst:** O(n²) - reverse sorted
- **Space:** O(1)
- **Stable:** Yes

#### Selection Sort
- **Best/Average/Worst:** O(n²)
- **Space:** O(1)
- **Stable:** No

#### Insertion Sort
- **Best:** O(n)
- **Average/Worst:** O(n²)
- **Space:** O(1)
- **Stable:** Yes

### O(n log n) Algorithms

#### Merge Sort
- **Best/Average/Worst:** O(n log n)
- **Space:** O(n)
- **Stable:** Yes

#### Quick Sort
- **Best/Average:** O(n log n)
- **Worst:** O(n²)
- **Space:** O(log n)
- **Stable:** No

#### Heap Sort
- **Best/Average/Worst:** O(n log n)
- **Space:** O(1)
- **Stable:** No

### Linear Time Algorithms

#### Counting Sort
- **Best/Average/Worst:** O(n+k)
- **Space:** O(k)
- **Stable:** Yes

#### Radix Sort
- **Best/Average/Worst:** O(d·n)
- **Space:** O(n+k)
- **Stable:** Yes

---

## 🏗️ Project Structure

```
Sorting-Techniques-Visualiser/
├── src/
│   ├── main.cpp
│   ├── visualizer.h
│   ├── algorithms/
│   │   ├── BubbleSort.h
│   │   ├── SelectionSort.h
│   │   ├── InsertionSort.h
│   │   ├── MergeSort.h
│   │   ├── QuickSort.h
│   │   ├── HeapSort.h
│   │   ├── ShellSort.h
│   │   ├── CountingSort.h
│   │   ├── RadixSort.h
│   │   └── BucketSort.h
│   ├── utils/
│   │   ├── ArrayGenerator.h
│   │   ├── Timer.h
│   │   └── Statistics.h
│   └── ui/
│       ├── Renderer.h
│       ├── Controls.h
│       └── Layout.h
├── web/
│   ├── index.html
│   ├── css/
│   │   └── style.css
│   └── js/
│       ├── visualizer.js
│       └── algorithms.js
├── .gitignore
├── CMakeLists.txt
├── README.md
└── LICENSE
```

---

## 🎓 Educational Uses

### Computer Science Students
- Understand algorithm behavior visually
- Compare different approaches
- Analyze time/space complexity empirically
- Learn best/average/worst case scenarios

### Algorithm Analysis
- See why O(n²) is slower than O(n log n)
- Understand impact of array patterns on performance
- Visualize divide-and-conquer strategies
- Compare stable vs. unstable algorithms

---

## 📝 License

MIT License - Free to use and modify

---

## 🔗 Resources

- [Sorting Algorithm Visualization](https://www.cs.usfca.edu/~galles/visualization/ComparisonSort.html)
- [Big O Cheat Sheet](https://www.bigocheatsheet.com/)
- [Algorithm Complexity Analysis](https://www.geeksforgeeks.org/analysis-of-algorithms/)

