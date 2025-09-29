#include <iostream>   // For input-output
#include <fstream>    // For file handling
#include <cmath>      // For log2

using namespace std;

// Function to implement Linear Search
int linearSearch(int arr[], int n, int target) {
    int comparisons = 0;  // Initialize comparison count
    for (int i = 0; i < n; ++i) {
        ++comparisons;  // Count comparison
        if (arr[i] == target) {
            break;  // Element found, exit loop
        }
    }
    return comparisons;  // Return the total comparisons
}

int main() {
    // Open the output CSV file to store the results
    ofstream outputFile("linearsortcomparisons.csv", ios::app);

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
            
            int target = rand() % 10000;  // Random target number
            avgComparisons += linearSearch(arr, size, target);  // Call linear search
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

