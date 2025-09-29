#include <iostream>   // For input-output
#include <fstream>    // For file handling
#include <algorithm>  // For sorting and std::swap
#include <cmath>      // For log2

using namespace std;

// Function to implement Binary Search
int binarySearch(int arr[], int n, int target) {
    int comparisons = 0;  // Initialize comparison count
    int left = 0, right = n - 1;
    
    while (left <= right) {
        ++comparisons;  // Count comparison
        int mid = left + (right - left) / 2;  // Find middle index
        
        if (arr[mid] == target) {
            break;  // Element found, exit loop
        } else if (arr[mid] < target) {
            left = mid + 1;  // Search the right half
        } else {
            right = mid - 1;  // Search the left half
        }
    }
    return comparisons;  // Return the total comparisons
}

int main() {
    // Open the output CSV file to store the results
    ofstream outputFile("binarysearchcomparisons.csv");

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
            
            sort(arr, arr + size);  // Sort the array for binary search
            int target = rand() % 10000;  // Random target number
            avgComparisons += binarySearch(arr, size, target);  // Call binary search
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

