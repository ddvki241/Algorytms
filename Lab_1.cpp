#include <iostream>
#include <cmath>

using namespace std;

bool readData(double& start, double& end, double& step, int& n) {
    cout << "Input start, end of interval, step and value of n: ";
    cin >> start >> end >> step >> n;
    if (start >= end || step <= 0 || n <= 0) {
        cerr << "Wrong data" << endl;
        return false;
    }
    return true;
}

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

void outputData(double start, double end, double step, int n) {
    cout << "x\ty" << endl;
    for (double x = start; x <= end; x += step) {
        cout << x << "\t" << Y(x, n) << endl;
    }
}

int main() {
    double start, end, step;
    int n;
    if (readData(start, end, step, n)) {
        outputData(start, end, step, n);
        return 0;
    }
    return -1;
}
