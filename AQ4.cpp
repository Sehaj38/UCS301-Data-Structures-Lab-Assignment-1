#include <iostream>
using namespace std;

void reverseArray() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    int arr[50];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Reversed Array: ";
    for (int i = n - 1; i >= 0; i--) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void transposeMatrix() {
    int rows, cols;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    int matrix[50][50], transpose[50][50];

    cout << "Enter elements of matrix:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    // Compute transpose
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }

    cout << "\nTranspose of Matrix:\n";
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            cout << transpose[i][j] << " ";
        }
        cout << endl;
    }
}

void multiplyMatrix() {
    int m, n, p, q;
    cout << "Enter rows and columns of first matrix (A): ";
    cin >> m >> n;
    cout << "Enter rows and columns of second matrix (B): ";
    cin >> p >> q;

    if (n != p) {
        cout << "Matrix multiplication not possible (columns of A != rows of B)." << endl;
        return;
    }

    int A[50][50], B[50][50], C[50][50];

    cout << "Enter elements of first matrix (A):\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }

    cout << "Enter elements of second matrix (B):\n";
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < q; j++) {
            cin >> B[i][j];
        }
    }

    // Initialize C with 0
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < q; j++) {
            C[i][j] = 0;
        }
    }

    // Multiply
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < q; j++) {
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    cout << "\nResultant Matrix (A × B):\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < q; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int choice;

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Reverse an Array\n";
        cout << "2. Transpose a Matrix\n";
        cout << "3. Multiply Matrices\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                reverseArray();
                break;
            case 2:
                transposeMatrix();
                break;
            case 3:
                multiplyMatrix();
                break;
            case 4:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 4);

    return 0;
}
