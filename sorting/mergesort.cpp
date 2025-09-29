#include <iostream>   // For input-output
#include <fstream>    // For file handling
#include <cmath>      // For log2

using namespace std;

// Merge two halves
int merge(int arr[], int temp[], int left, int mid, int right) {
    int comparisons = 0, i = left, j = mid + 1, k = left;
    while (i <= mid && j <= right) {
        temp[k++] = (arr[i] <= arr[j]) ? arr[i++] : arr[j++];
        comparisons++;
    }
    while (i <= mid) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];
    for (int i = left; i <= right; i++) arr[i] = temp[i];
    return comparisons;
}

// Function to implement Merge Sort
int mergeSort(int arr[], int temp[], int left, int right) {
    int comparisons = 0;
    if (left < right) {
        int mid = (left + right) / 2;
        comparisons += mergeSort(arr, temp, left, mid) + mergeSort(arr, temp, mid + 1, right);
        comparisons += merge(arr, temp, left, mid, right);
    }
    return comparisons;
}

int main() {
    // Open the output CSV file to store the results
    ofstream outputFile("mergesortcomparisons.csv");
    
    // Write header for CSV
    outputFile << "input,avgcomparisons,nlogn" << endl;

    // Loop through different input sizes (30 to 1000)
    for (int size = 30; size <= 1000; size += 10) {
        double avgComparisons = 0;
        
        // Run the algorithm 10 times for each input size
        for (int i = 0; i < 10; i++) {
            int arr[size];
            int temp[size];
            
            // Generate random input for the array
            for (int j = 0; j < size; j++) {
                arr[j] = rand() % 10000;  // Random number between 0 and 9999
            }
            
            avgComparisons += mergeSort(arr, temp, 0, size - 1);  // Call merge sort
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

