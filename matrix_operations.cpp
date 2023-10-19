#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

void matrix_prints(int a[100][100], int b[100][100], int size);
void matrix_add(int a[100][100], int b[100][100], int size);
void matrix_multiply(int a[100][100], int b[100][100], int size);
void matrix_subtract(int a[100][100], int b[100][100], int size);


int main() {
    ifstream inputfile("matrix_input.txt");
    if (!(inputfile)){
        cerr << "Failed to open input file" << std::endl;
        return 1;
    }
    int n;
    inputfile >> n;
    int matrix1[100][100];
    int matrix2[100][100];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            inputfile >> matrix1[i][j];
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            inputfile >> matrix2[i][j];
        }
    }
    cout << "Name: Benjamin Kozlowski\nLab 6: Matrix Manipulation\n";
    matrix_prints(matrix1, matrix2, n);
    matrix_add(matrix1, matrix2, n);
    matrix_multiply(matrix1, matrix2, n);
    matrix_subtract(matrix1, matrix2, n);
}

void matrix_prints(int a[100][100], int b[100][100], int size){
    cout << "\nMatrix A:\n\n";
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << "\nMatrix B:\n\n";
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
}

void matrix_add(int a[100][100], int b[100][100], int size){
    int newmatrix[100][100];
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            newmatrix[i][j] = a[i][j] + b[i][j];
        }
    }
    cout << "\nMatrix Sum (A + B)\n\n";
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            cout << setw(2) << setfill(' ') << newmatrix[i][j] << " ";
        }
        cout << endl;
    }

}

void matrix_multiply(int a[100][100], int b[100][100], int size){
    int newmatrix[100][100] = {{0}};
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            for (int k = 0; k < size; k++){
                newmatrix[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    cout << "\nMatrix Product (A * B)\n\n";
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            cout << setw(3) << setfill(' ') << newmatrix[i][j] << " ";
        }
        cout << endl;
    }
}

void matrix_subtract(int a[100][100], int b[100][100], int size){
    int newmatrix[100][100];
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            newmatrix[i][j] = a[i][j] - b[i][j];
        }
    }
    cout << "\nMatrix Difference (A - B)\n\n";
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            cout << setw(3) << setfill(' ') << newmatrix[i][j] << " ";
        }
        cout << endl;
    }
}

