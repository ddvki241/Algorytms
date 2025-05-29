#include <iostream>
#include <cmath>
#include <output.table_h>

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
    }
    else {
        double sum = 0.0;
        for (int i = 1; i <= n - 1; i++) {
            sum += pow(i, 3);
        }
        return x - sum;
    }
}
double quadraticX(double x, double n) {
    return x * x - 4x + n;
}
int main() {
    double start, end, step;
    int n;

    cout << "Enter start, end, step, n:";
    cin >> start >> end >> step >> n;

    cout << "\nTable for Y:" << endl;
    outputTable(start, end, step, Y);

    cout << "\nTable for quadraticX:" << endl;
    outputTable(start, end, step, quadraticX);

    return 0;
}
