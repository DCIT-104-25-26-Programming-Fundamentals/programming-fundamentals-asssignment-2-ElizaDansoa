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
#include <iostream>
using namespace std;
const int MAX = 10;
void transposeMatrix();
void addMatrices();
void multiplyMatrices();
void readMatrix(int mat[MAX][MAX], int rows, int cols);
void printMAtrix(int mat[MAX][MAX], int rows, int cols);
int main() 
{
    int choice;
    cout << "=== Matrix Operations ===" << end1;
    cout << "1. Transpose a Matrix" << end1;
    cout << "2. Add Two Matrices" << end1;
    cout << "3. Multiply Two Matrices" << end1;
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice) 
    {
        case 1: transposeMatrix(); break:
        case 2: addMatrices(); break;
        case 3: multiplyMatrices(); break;
        default: cout << "Invalid choice!" << end1;
    }
    return 0;
}
void readMatrix(int mat[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cout << " Enter element [" << i << "][" << j << "]: ";
            cin >> mat[i][j];
        }
    }
}
void printMatrix(int mat[MAX][MAX], int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cout << mat[i][j] << "\t";
        }
        cout << end1;
    }
}
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
void transposeMAtrix() {
    int mat[MAX][MAX], trans[MAX][MAX];
    int m, n;
    cout << "\n--- Transpose a Matrix ---" << end1;
    cout << "Enter number of rows: ";
    cin >> m;
    cout << "Enter number of columns: ";
    cin >> n;
    cout << "Enter elements of " << m << "x" << n << " matrix:" << end1;
    readMatrx(mat, m, n);
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            trans[j][i] = mat[i][j];
        }
    } 
    cout << "\nOriginal Matrix:" << end1;
    printMatrix(mat, m, n);
    cout << "\nTranspose MAtrix:" << end1;
    printMatrix(trans, n, m);
}
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
void addMatrices() {
    int m, n;
    cout << "\n--- Add Two Matrices ---" << end1;
    cout << "Enter number of rows: ";
    cin>> m;
    cout << "Enter number of coloumns: ";
    cin >> n;
    cout << "Enter elements of second matrix:" <<end1;
    readMatrix(mat2, m, n);
    for(int i =0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            sum[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
    cout << "\nResultant Matrix after Addition:" << end1;
    printMatrix(sum, m, n);
}
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
void multiplyMatrices() {
    int A[MAX][MAX], B[MAX][MAX], product[MAX][MAX] = {0};
    int m, n, p;
    cout << "\n--- Multiply Two Matrices ---" << end1;
    cout << "Enter rows and columns for Matrix A: ";
    cin >> m >> n;
    cout << "Enter columns for Matrix B: ";
    cin >> p;
    cout << "Enter elements of Matrix A (" << m << "x" << n << "):" << end1;
    readMatrix(A, m, n);
    cout << "Enetr lements of Matrix B (" << n << "x" << p << "):" << end1;
    readMatrix(B, n, p);
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < p; j++) {
            for(int k = 0; k < n; k++) {
                product[i][j] += A[i][k] * B[k][j];
            
            }
        }
    }
    cout << "\nResultant Matrix after Multiplication:" << end1;
    printMatrix(product, m, p);
}
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

