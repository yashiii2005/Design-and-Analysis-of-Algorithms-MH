#include <iostream>   // For input-output
#include <fstream>    // For file handling
#include <algorithm>  // For std::swap
#include <cmath>      // For log2

using namespace std;

// Function to perform the partitioning step in Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Pivot element is taken as the last element
    int i = low - 1;        // Pointer for the smaller element

    for (int j = low; j < high; j++) {
        // If current element is smaller than or equal to the pivot
        if (arr[j] <= pivot) {
            i++;  // Increment the smaller element pointer
            swap(arr[i], arr[j]);  // Swap elements
        }
    }
    // Place the pivot in the correct position
    swap(arr[i + 1], arr[high]);
    return i + 1;  // Return the partition index
}

// Function to implement Quick Sort
void quickSort(int arr[], int low, int high, int &comparisons) {
    if (low < high) {
        // Partition the array into two sub-arrays
        int pi = partition(arr, low, high);

        comparisons += (high - low);  // Add comparisons made in the partitioning step

        // Recursively sort the sub-arrays
        quickSort(arr, low, pi - 1, comparisons);
        quickSort(arr, pi + 1, high, comparisons);
    }
}

int main() {
    // Open the output CSV file to store the results
    ofstream outputFile("quicksortcomparisons.csv");

    // Loop through different input sizes (30 to 1000)
    for (int size = 30; size <= 1000; size += 10) {
        double avgComparisons = 0;

        // Run the algorithm 10 times for each input size
        for (int i = 0; i < 10; i++) {
            int arr[size];
            int comparisons = 0;  // Initialize comparison count for this run
            
            // Generate random input for the array
            for (int j = 0; j < size; j++) {
                arr[j] = rand() % 10000;  // Random number between 0 and 9999
            }

            quickSort(arr, 0, size - 1, comparisons);  // Sort the array using Quick Sort
            avgComparisons += comparisons;  // Add the comparisons made during this run
        }

        avgComparisons /= 10;  // Average comparisons over 10 runs
        double nlogn = size * log2(size);  // Calculate n * log(n)

        // Write the results to the CSV file
        outputFile << size << "," << avgComparisons << "," << nlogn << endl;
    }

    // Close the output file
    outputFile.close();
    return 0;
}

