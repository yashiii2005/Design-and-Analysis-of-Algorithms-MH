#include <iostream>   // For input-output
#include <fstream>    // For file handling
#include <algorithm>  // For std::swap
#include <cmath>      // For log2

using namespace std;

// Function to heapify a subtree rooted at index i
int heapify(int arr[], int n, int i) {
    int comparisons = 0, largest = i, left = 2 * i + 1, right = 2 * i + 2;
    
    if (left < n && arr[left] > arr[largest]) { largest = left; comparisons++; }
    if (right < n && arr[right] > arr[largest]) { largest = right; comparisons++; }
    
    if (largest != i) {
        swap(arr[i], arr[largest]);
        comparisons += heapify(arr, n, largest);
    }
    return comparisons;
}

// Function to implement Heap Sort
int heapSort(int arr[], int n) {
    int comparisons = 0;
    
    for (int i = n / 2 - 1; i >= 0; --i) comparisons += heapify(arr, n, i);
    for (int i = n - 1; i >= 1; --i) {
        swap(arr[0], arr[i]);
        comparisons += heapify(arr, i, 0);
    }

    return comparisons;
}


int main() {
    // Open the output CSV file to store the results
    ofstream outputFile("heapsortcomparisons.csv");
    
    // Loop through different input sizes (30 to 1000)
    for (int size = 30; size <= 1000; size += 10) {
        double avgComparisons = 0;
        
        // Run the algorithm 10 times for each input size
        for (int i = 0; i < 10; i++) {
            int arr[size];
            
            // Generate random input for the array
            for (int j = 0; j < size; j++) {
                arr[j] = rand() % 10000;  // Random number between 0 and 9999
            }
            
            avgComparisons += heapSort(arr, size);  // Call insertion sort
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
