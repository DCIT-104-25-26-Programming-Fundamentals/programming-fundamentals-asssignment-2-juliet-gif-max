// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int MAX_SIZE = 10;

void readMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

void displayMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}

void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    int transposed[MAX_SIZE][MAX_SIZE];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }

    cout << "\nTransposed Matrix:\n";
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            cout << setw(5) << transposed[i][j];
        }
        cout << endl;
    }
}

void addMatrices(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    int result[MAX_SIZE][MAX_SIZE];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }

    cout << "\nSum Matrix:\n";
    displayMatrix(result, rows, cols);
}

void multiplyMatrices(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int rowsA, int colsA, int colsB) {
    int result[MAX_SIZE][MAX_SIZE] = {0};

    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            for (int k = 0; k < colsA; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    cout << "\nProduct Matrix:\n";
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            cout << setw(5) << result[i][j];
        }
        cout << endl;
    }
}

int main() {
    int choice;
    int rows, cols, rowsB, colsB;
    int matrixA[MAX_SIZE][MAX_SIZE];
    int matrixB[MAX_SIZE][MAX_SIZE];

    cout << "Matrix Operations\n";
    cout << "1. Transpose Matrix\n";
    cout << "2. Add Two Matrices\n";
    cout << "3. Multiply Two Matrices\n";
    cout << "Choose an option: ";
    cin >> choice;

    switch (choice) {
        case 1:
            cout << "Enter number of rows: ";
            cin >> rows;
            cout << "Enter number of columns: ";
            cin >> cols;
            readMatrix(matrixA, rows, cols);
            cout << "\nOriginal Matrix:\n";
            displayMatrix(matrixA, rows, cols);
            transposeMatrix(matrixA, rows, cols);
            break;

        case 2:
            cout << "Enter rows for matrix A: ";
            cin >> rows;
            cout << "Enter columns for matrix A: ";
            cin >> cols;
            cout << "Enter matrix A:\n";
            readMatrix(matrixA, rows, cols);

            cout << "Enter rows for matrix B: ";
            cin >> rowsB;
            cout << "Enter columns for matrix B: ";
            cin >> colsB;

            if (rows != rowsB || cols != colsB) {
                cout << "Error: Matrices must be the same size." << endl;
                return 0;
            }

            cout << "Enter matrix B:\n";
            readMatrix(matrixB, rowsB, colsB);

            cout << "\nMatrix A:\n";
            displayMatrix(matrixA, rows, cols);
            cout << "\nMatrix B:\n";
            displayMatrix(matrixB, rowsB, colsB);
            addMatrices(matrixA, matrixB, rows, cols);
            break;

        case 3:
            cout << "Enter rows for matrix A: ";
            cin >> rows;
            cout << "Enter columns for matrix A: ";
            cin >> cols;
            cout << "Enter matrix A:\n";
            readMatrix(matrixA, rows, cols);

            cout << "Enter rows for matrix B: ";
            cin >> rowsB;
            cout << "Enter columns for matrix B: ";
            cin >> colsB;

            if (cols != rowsB) {
                cout << "Error: Number of columns in A must equal number of rows in B." << endl;
                return 0;
            }

            cout << "Enter matrix B:\n";
            readMatrix(matrixB, rowsB, colsB);

            cout << "\nMatrix A:\n";
            displayMatrix(matrixA, rows, cols);
            cout << "\nMatrix B:\n";
            displayMatrix(matrixB, rowsB, colsB);
            multiplyMatrices(matrixA, matrixB, rows, cols, colsB);
            break;

        default:
            cout << "Invalid choice." << endl;
            break;
    }

    return 0;
}

