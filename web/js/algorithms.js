/**
 * Sorting Algorithm Implementations
 */

const Algorithms = {
    bubble: function(arr, callbacks) {
        const n = arr.length;
        for (let i = 0; i < n - 1; i++) {
            for (let j = 0; j < n - i - 1; j++) {
                callbacks.compare(j, j + 1);
                if (arr[j] > arr[j + 1]) {
                    [arr[j], arr[j + 1]] = [arr[j + 1], arr[j]];
                    callbacks.swap(j, j + 1);
                }
            }
            callbacks.mark(n - i - 1, 'green');
        }
    },

    selection: function(arr, callbacks) {
        const n = arr.length;
        for (let i = 0; i < n - 1; i++) {
            let minIdx = i;
            for (let j = i + 1; j < n; j++) {
                callbacks.compare(minIdx, j);
                if (arr[j] < arr[minIdx]) {
                    minIdx = j;
                }
            }
            if (minIdx !== i) {
                [arr[i], arr[minIdx]] = [arr[minIdx], arr[i]];
                callbacks.swap(i, minIdx);
            }
            callbacks.mark(i, 'green');
        }
    },

    insertion: function(arr, callbacks) {
        const n = arr.length;
        for (let i = 1; i < n; i++) {
            let key = arr[i];
            let j = i - 1;
            while (j >= 0 && arr[j] > key) {
                callbacks.compare(j, i);
                arr[j + 1] = arr[j];
                callbacks.swap(j, j + 1);
                j--;
            }
            arr[j + 1] = key;
            callbacks.mark(i, 'green');
        }
    },

    merge: function(arr, callbacks) {
        const mergeSort = (left, right) => {
            if (left < right) {
                const mid = Math.floor((left + right) / 2);
                mergeSort(left, mid);
                mergeSort(mid + 1, right);
                merge(left, mid, right);
            }
        };

        const merge = (left, mid, right) => {
            const temp = [];
            let i = left, j = mid + 1;
            while (i <= mid && j <= right) {
                callbacks.compare(i, j);
                if (arr[i] <= arr[j]) {
                    temp.push(arr[i++]);
                } else {
                    temp.push(arr[j++]);
                }
            }
            while (i <= mid) temp.push(arr[i++]);
            while (j <= right) temp.push(arr[j++]);
            for (let k = left, idx = 0; k <= right; k++, idx++) {
                arr[k] = temp[idx];
                callbacks.mark(k, 'yellow');
            }
        };

        mergeSort(0, arr.length - 1);
    },

    quick: function(arr, callbacks) {
        const quickSort = (low, high) => {
            if (low < high) {
                const pi = partition(low, high);
                quickSort(low, pi - 1);
                quickSort(pi + 1, high);
            }
        };

        const partition = (low, high) => {
            const pivot = arr[high];
            let i = low - 1;
            for (let j = low; j < high; j++) {
                callbacks.compare(j, high);
                if (arr[j] < pivot) {
                    i++;
                    [arr[i], arr[j]] = [arr[j], arr[i]];
                    callbacks.swap(i, j);
                }
            }
            [arr[i + 1], arr[high]] = [arr[high], arr[i + 1]];
            callbacks.swap(i + 1, high);
            return i + 1;
        };

        quickSort(0, arr.length - 1);
    },

    heap: function(arr, callbacks) {
        const heapify = (n, i) => {
            let largest = i;
            const left = 2 * i + 1;
            const right = 2 * i + 2;
            if (left < n) {
                callbacks.compare(left, largest);
                if (arr[left] > arr[largest]) largest = left;
            }
            if (right < n) {
                callbacks.compare(right, largest);
                if (arr[right] > arr[largest]) largest = right;
            }
            if (largest !== i) {
                [arr[i], arr[largest]] = [arr[largest], arr[i]];
                callbacks.swap(i, largest);
                heapify(n, largest);
            }
        };

        const n = arr.length;
        for (let i = Math.floor(n / 2) - 1; i >= 0; i--) {
            heapify(n, i);
        }
        for (let i = n - 1; i > 0; i--) {
            [arr[0], arr[i]] = [arr[i], arr[0]];
            callbacks.swap(0, i);
            heapify(i, 0);
            callbacks.mark(i, 'green');
        }
    }
};

// Array generator
function generateArray(size, pattern = 'random') {
    const arr = [];
    switch (pattern) {
        case 'random':
            for (let i = 0; i < size; i++) {
                arr.push(Math.floor(Math.random() * size * 2));
            }
            break;
        case 'sorted':
            for (let i = 0; i < size; i++) {
                arr.push(i);
            }
            break;
        case 'reverse':
            for (let i = size; i > 0; i--) {
                arr.push(i);
            }
            break;
        case 'nearly':
            for (let i = 0; i < size; i++) {
                arr.push(i);
            }
            for (let i = 0; i < size / 10; i++) {
                const idx1 = Math.floor(Math.random() * size);
                const idx2 = Math.floor(Math.random() * size);
                [arr[idx1], arr[idx2]] = [arr[idx2], arr[idx1]];
            }
            break;
        case 'few':
            for (let i = 0; i < size; i++) {
                arr.push(Math.floor(Math.random() * 5));
            }
            break;
    }
    return arr;
}
