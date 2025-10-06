#include <iostream>
using namespace std;

int main() {
    // Define two 2x2 matrices
    int A[2][2], B[2][2], C[2][2];

    cout << "Enter elements of first 2x2 matrix (A):\n";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> A[i][j];
        }
    }

    cout << "Enter elements of second 2x2 matrix (B):\n";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> B[i][j];
        }
    }

    // Applying Strassen’s formula:
    // Let’s store shortcut multiplication results as M1, M2...M7
    int M1 = (A[0][0] + A[1][1]) * (B[0][0] + B[1][1]);
    int M2 = (A[1][0] + A[1][1]) * B[0][0];
    int M3 = A[0][0] * (B[0][1] - B[1][1]);
    int M4 = A[1][1] * (B[1][0] - B[0][0]);
    int M5 = (A[0][0] + A[0][1]) * B[1][1];
    int M6 = (A[1][0] - A[0][0]) * (B[0][0] + B[0][1]);
    int M7 = (A[0][1] - A[1][1]) * (B[1][0] + B[1][1]);

    // Now calculate the final product matrix C
    C[0][0] = M1 + M4 - M5 + M7;  // C11
    C[0][1] = M3 + M5;            // C12
    C[1][0] = M2 + M4;            // C21
    C[1][1] = M1 - M2 + M3 + M6;  // C22

    // Output the result
    cout << "\nResultant Matrix (C = A × B) using Strassen’s Algorithm:\n";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

