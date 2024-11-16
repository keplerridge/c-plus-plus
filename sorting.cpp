#include <iostream>
#include <vector>

// Merge function to merge two halves of the array
void merge(std::vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Temporary arrays for left and right sub-arrays
    std::vector<int> leftArr(n1), rightArr(n2);

    // Copy data into temporary arrays
    for (int i = 0; i < n1; i++) {
        leftArr[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++) {
        rightArr[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = left;
    // Merge the temporary arrays back into arr[]
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of leftArr[]
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // Copy the remaining elements of rightArr[]
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

// Merge Sort function
void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Recursively sort the two halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

// Partition function for Quick Sort
int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    // Rearranging elements based on pivot
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Quick Sort function
void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        // Recursively sort the two partitions
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Bubble Sort function
void bubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    // Loop through all elements
    for (int i = 0; i < n - 1; i++) {
        // Last i elements are already sorted
        for (int j = 0; j < n - i - 1; j++) {
            // Swap if the element is greater than the next one
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Function to print the array
void printArray(const std::vector<int>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    // Initial unsorted arrays for each sort method
    std::vector<int> arrMerge = {45, -32, 18, -71, 29, -18, 90, 10, -38, -57, 14, -99, -50, 65, 22, 75, 92, -60, -43, 50};   // Array for merge sort
    std::vector<int> arrQuick = {-74, 51, 34, -95, -33, -60, 18, 58, -72, 79, 55, -60, 16, 46, 18, -71, -59, 89, -9, -61};   // Array for quick sort
    std::vector<int> arrBubble = {17, 6, -72, -41, -28, 47, -51, 80, -47, -81, 11, 18, 1, 55, 61, 38, -91, 68, -28, 390};  // Array for bubble sort

    // Display original arrays
    std::cout << "Original Array for Merge Sort: ";
    printArray(arrMerge);
    
    std::cout << "Original Array for Quick Sort: ";
    printArray(arrQuick);
    
    std::cout << "Original Array for Bubble Sort: ";
    printArray(arrBubble);

    // Merge Sort
    mergeSort(arrMerge, 0, arrMerge.size() - 1);
    std::cout << "Sorted with Merge Sort: ";
    printArray(arrMerge);

    // Quick Sort
    quickSort(arrQuick, 0, arrQuick.size() - 1);
    std::cout << "Sorted with Quick Sort: ";
    printArray(arrQuick);

    // Bubble Sort
    bubbleSort(arrBubble);
    std::cout << "Sorted with Bubble Sort: ";
    printArray(arrBubble);

    return 0;
}
