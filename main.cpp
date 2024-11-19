#include <iostream>
#include <vector>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

// Function to print the current state of the array
void printArray(const std::vector<int>& arr, int pivotIndex = -1, int left = -1, int right = -1) {
    for (int i = 0; i < (int) arr.size(); ++i) {
        if (i == pivotIndex)
            std::cout << "[" << arr[i] << "] "; // Highlight pivot
        else if (i == left)
            std::cout << "{" << arr[i] << "} "; // Highlight left
        else if (i == right)
            std::cout << "(" << arr[i] << ") "; // Highlight right
        else
            std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

// Partition function
int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // Choose the last element as pivot
    int i = low - 1;       // Index of smaller element

    std::cout << "Pivot chosen: " << pivot << "\n";

    for (int j = low; j < high; ++j) {
        if (arr[j] < pivot) {
            ++i;
            std::swap(arr[i], arr[j]);
            std::cout << "Swapped " << arr[i] << " and " << arr[j] << " -> ";
            printArray(arr, high, i, j);
        }
    }
    std::swap(arr[i + 1], arr[high]); // Place pivot in the correct position
    std::cout << "Placed pivot " << pivot << " -> ";
    printArray(arr, i + 1);
    return i + 1;
}

// QuickSort function
void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        std::cout << "Sorting range: ";
        printArray(arr, -1, low, high);

        int pi = partition(arr, low, high); // Partition index

        std::cout << "Partitioned at index " << pi << "\n";

        quickSort(arr, low, pi - 1);  // Sort the left subarray
        quickSort(arr, pi + 1, high); // Sort the right subarray
    }
}

// Function to generate a random array
std::vector<int> generateRandomArray(int size, int minValue, int maxValue) {
    std::vector<int> arr(size);
    for (int& num : arr) {
        num = minValue + rand() % (maxValue - minValue + 1);
    }
    return arr;
}

int main() {
    std::srand(std::time(nullptr)); // Seed the random number generator

    // Generate a random array
    int size = 10; // Size of the array
    int minValue = 1, maxValue = 100; // Range of random values
    std::vector<int> arr = generateRandomArray(size, minValue, maxValue);

    std::cout << "Initial random array: ";
    printArray(arr);

    quickSort(arr, 0, arr.size() - 1);

    std::cout << "Sorted array: ";
    printArray(arr);

    return 0;
}
