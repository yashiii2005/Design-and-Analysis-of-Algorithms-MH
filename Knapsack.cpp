#include <iostream>
#include <cstring>   
using namespace std;

int dp[100][100];

int knapsackMemo(int capacity, int weights[], int values[], int n) {

    if (n == 0 || capacity == 0)
        return 0;

    if (dp[n][capacity] != -1)
        return dp[n][capacity];
    if (weights[n - 1] > capacity)
        return dp[n][capacity] = knapsackMemo(capacity, weights, values, n - 1);
    else
        return dp[n][capacity] = max(
            values[n - 1] + knapsackMemo(capacity - weights[n - 1], weights, values, n - 1),
            knapsackMemo(capacity, weights, values, n - 1)
        );
}

int main() {
    int n;
    cout << "Enter number of items: ";
    cin >> n;
    
    int values[n], weights[n];
    cout << "Enter values of items: ";

    for (int i = 0; i < n; i++)
        cin >> values[i];
    cout << "Enter weights of items: ";

    for (int i = 0; i < n; i++)
        cin >> weights[i];

    int capacity;
    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    memset(dp, -1, sizeof(dp));

    int result = knapsackMemo(capacity, weights, values, n);

    cout << "\nMaximum value that can be obtained: " << result << endl;

    return 0;
}

	

