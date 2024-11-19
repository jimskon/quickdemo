#include <iostream>
#include <vector>

// Function to print the array
void printArray(const std::vector<int>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

// Partition function for Quick Sort
int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // Choosing the last element as the pivot
    int i = low - 1;       // Index of smaller element

    std::cout << "\nPartitioning around pivot " << pivot << ":\n";
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
            std::cout << "Swapping " << arr[i] << " and " << arr[j] << ": ";
            printArray(arr);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    std::cout << "Swapping pivot " << arr[high] << " to position " << i + 1 << ": ";
    printArray(arr);
    return i + 1;
}

// Quick Sort function
void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        // Partition index
        int pi = partition(arr, low, high);

        std::cout << "\nArray after partitioning: ";
        printArray(arr);

        // Recursively sort the subarrays
        std::cout << "\nSorting left subarray (index " << low << " to " << pi - 1 << "):\n";
        quickSort(arr, low, pi - 1);

        std::cout << "\nSorting right subarray (index " << pi + 1 << " to " << high << "):\n";
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    // Input array
    std::vector<int> arr = {10, 7, 8, 9, 1, 5};
    int n = arr.size();

    std::cout << "Initial array: ";
    printArray(arr);

    // Perform Quick Sort
    quickSort(arr, 0, n - 1);

    std::cout << "\nSorted array: ";
    printArray(arr);

    return 0;
}
