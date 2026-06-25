/**
 * Main Visualizer Application
 */

class Visualizer {
    constructor() {
        this.canvas = document.getElementById('canvas');
        this.ctx = this.canvas.getContext('2d');
        this.resizeCanvas();
        
        this.array = [];
        this.algorithm = 'bubble';
        this.speed = 50;
        this.isRunning = false;
        this.isPaused = false;
        
        this.stats = {
            comparisons: 0,
            swaps: 0,
            startTime: 0
        };
        
        this.colors = {
            default: '#7c6cf7',
            compared: '#f7896a',
            swapped: '#4dc6f7',
            sorted: '#3ecf8e',
            accessing: '#f7d46a'
        };
        
        this.initializeControls();
        this.generateNewArray();
        this.draw();
    }
    
    resizeCanvas() {
        const rect = this.canvas.parentElement.getBoundingClientRect();
        this.canvas.width = rect.width;
        this.canvas.height = rect.height;
    }
    
    initializeControls() {
        document.getElementById('arraySize').addEventListener('change', (e) => {
            document.getElementById('sizeDisplay').textContent = e.target.value;
            this.generateNewArray();
        });
        
        document.getElementById('speed').addEventListener('change', (e) => {
            this.speed = e.target.value;
            document.getElementById('speedDisplay').textContent = e.target.value + 'x';
        });
        
        document.getElementById('algorithm').addEventListener('change', (e) => {
            this.algorithm = e.target.value;
            this.generateNewArray();
        });
        
        document.getElementById('play').addEventListener('click', () => this.startSort());
        document.getElementById('pause').addEventListener('click', () => this.togglePause());
        document.getElementById('reset').addEventListener('click', () => this.generateNewArray());
        
        window.addEventListener('resize', () => this.resizeCanvas());
    }
    
    generateNewArray() {
        const size = parseInt(document.getElementById('arraySize').value);
        const pattern = document.getElementById('pattern').value;
        this.array = generateArray(size, pattern);
        this.resetStats();
        this.draw();
    }
    
    resetStats() {
        this.stats.comparisons = 0;
        this.stats.swaps = 0;
        this.stats.startTime = Date.now();
        this.updateStats();
    }
    
    async startSort() {
        if (this.isRunning) return;
        this.isRunning = true;
        this.isPaused = false;
        this.resetStats();
        
        const callbacks = {
            compare: (i, j) => {
                this.stats.comparisons++;
                this.highlighted = [i, j];
                this.draw();
            },
            swap: (i, j) => {
                this.stats.swaps++;
                this.draw();
            },
            mark: (i, color) => {
                // Mark element as sorted
                this.draw();
            }
        };
        
        try {
            Algorithms[this.algorithm](this.array, callbacks);
            this.highlighted = [];
            this.draw();
        } finally {
            this.isRunning = false;
            this.updateStats();
        }
    }
    
    togglePause() {
        this.isPaused = !this.isPaused;
    }
    
    updateStats() {
        document.getElementById('comparisons').textContent = this.stats.comparisons;
        document.getElementById('swaps').textContent = this.stats.swaps;
        const elapsed = ((Date.now() - this.stats.startTime) / 1000).toFixed(2);
        document.getElementById('time').textContent = elapsed;
    }
    
    draw() {
        this.ctx.fillStyle = '#0a0a10';
        this.ctx.fillRect(0, 0, this.canvas.width, this.canvas.height);
        
        if (this.array.length === 0) return;
        
        const barWidth = this.canvas.width / this.array.length;
        const maxValue = Math.max(...this.array);
        
        for (let i = 0; i < this.array.length; i++) {
            const height = (this.array[i] / maxValue) * (this.canvas.height * 0.9);
            const x = i * barWidth;
            const y = this.canvas.height - height;
            
            // Determine color
            let color = this.colors.default;
            if (this.highlighted && this.highlighted.includes(i)) {
                color = this.colors.compared;
            }
            
            this.ctx.fillStyle = color;
            this.ctx.fillRect(x, y, barWidth - 2, height);
        }
        
        this.updateStats();
    }
}

// Initialize when DOM is ready
document.addEventListener('DOMContentLoaded', () => {
    window.visualizer = new Visualizer();
});
