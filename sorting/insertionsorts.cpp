#include <iostream>   // For input-output
#include <fstream>    // For file handling
#include <algorithm>  // For std::swap
#include <cmath>      // For log2

using namespace std;

// Function to implement Insertion Sort
int insertionSort(int arr[], int n) {
    int comparisons = 0;  // Initialize comparison count
    for (int i = 1; i < n; ++i) {
        int key = arr[i];  // Element to be inserted
        int j = i - 1;
        
        // Move elements of arr[0..i-1] that are greater than key
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
            ++comparisons;  // Count comparison
        }
        arr[j + 1] = key;  // Insert the key into the correct position
    }
    return comparisons;  // Return the total comparisons
}

int main() {
    // Open the output CSV file to store the results
    ofstream outputFile("insertionsortcomparisons.csv");
    
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
            
            avgComparisons += insertionSort(arr, size);  // Call insertion sort
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

