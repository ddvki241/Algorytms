#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

double Y(double x, int n) {
    if (x < 0) {
        double product = 1.0;
        for (int i = 1; i <= n - 1; i++) {
            double sum = 0.0;
            for (int j = 1; j <= n; j++) {
                sum += i / (pow(j, 2) - x);
            }
            product *= sum;
        }
        return product;
    } else {
        double sum = 0.0;
        for (int i = 1; i <= n - 1; i++) {
            sum += pow(i, 3);
        }
        return x - sum;
    }
}

int main() {
    ifstream inFile("input.txt");
    if (!inFile.is_open()) {
        cerr << "Error opening input.txt" << endl;
        return 1;
    }

    int rows, cols;
    inFile >> rows >> cols;

    int** array1 = new int* [rows];
    for (int i = 0; i < rows; i++) {
        array1[i] = new int[cols];
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            inFile >> array1[i][j];
        }
    }
    inFile.close();

    int n;
    cout << "Input your n: ";
    cin >> n;

    double** array2 = new double* [rows];
    for (int i = 0; i < rows; i++) {
        array2[i] = new double[cols];
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            array2[i][j] = y(array1[i][j], n);
        }
    }

    ofstream outFile("output.txt");
    if (!outFile.is_open()) {
        cerr << "Error opening output.txt" << endl;
        return 1;
    }

    cout << "\nResult (y(x, n)):\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << array2[i][j] << "\t";
            outFile << array2[i][j] << " ";
        }
        cout << endl;
        outFile << endl;
    }

    outFile.close();

    for (int i = 0; i < rows; i++) {
        delete[] array1[i];
        delete[] array2[i];
    }
    delete[] array1;
    delete[] array2;

    return 0;
}
