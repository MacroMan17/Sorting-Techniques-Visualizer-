# Setup Instructions

## GitHub Repository Creation

### Step 1: Create Repository on GitHub

1. Go to https://github.com/new
2. Fill in details:
   - **Repository name:** `Sorting-Techniques-Visualiser`
   - **Description:** "Interactive visualization tool for sorting algorithms with real-time animations and performance analysis"
   - **Visibility:** Public
   - **Initialize with README:** No (already have one)
3. Click "Create repository"
4. Copy the repository URL (format: `https://github.com/YOUR_USERNAME/Sorting-Techniques-Visualiser.git`)

### Step 2: Push to GitHub

From your project directory:

```bash
git init
git add .
git commit -m "Initial commit: Complete Sorting Techniques Visualiser project"
git remote add origin https://github.com/YOUR_USERNAME/Sorting-Techniques-Visualiser.git
git branch -M main
git push -u origin main
```

---

## Building C++ Version

### Requirements
- CMake 3.10+
- C++17 compiler (GCC, Clang, MSVC)

### Build Steps

```bash
cd Sorting-Techniques-Visualiser
mkdir build
cd build

cmake .. -DCMAKE_BUILD_TYPE=Release
cmake --build .

# Run
./sorting_visualiser
```

---

## Running Web Version

Simply open `web/index.html` in your browser!

```bash
# Or run a local server
python -m http.server 8000
# Visit http://localhost:8000/web/
```

---

## Project Features

✅ 6 sorting algorithms implemented in C++  
✅ Complete web version with visualizations  
✅ Real-time performance metrics  
✅ Multiple input patterns  
✅ Fully documented code  
✅ MIT License  

---

## Next Steps

1. Add more algorithms (Shell Sort, Counting Sort, Radix Sort)
2. Implement graphics library (SDL2 or SFML)
3. Add more visualization features
4. Create unit tests
5. Add more documentation

