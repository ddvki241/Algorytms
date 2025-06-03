#include <iostream>
#include <cstdlib>
#include <ctime>
#define N 5
#define SIZE (10 * N % 51)

using namespace std;

void printArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void selectSort(int a[], int size) {
    cout << "\n Select Sort: \n";
    for (int i = 0; i < size - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < size; ++j) {
            if (a[j] < a[minIndex])
                minIndex = j;
        }
        if (minIndex != i) {
            int temp = a[i];
            a[i] = a[minIndex];
            a[minIndex] = temp;
        }

        cout << "After pass " << i + 1 << ": ";
        printArray(a, size);
    }
    cout << "Sorted array: ";
    printArray(a, size);
}

void insertSort(int a[], int size) {
    cout << "\n Insert Sort: \n";
    for (int i = 1; i < size; ++i) {
        int temp = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > temp) {
            a[j + 1] = a[j];
            --j;
        }
        a[j + 1] = temp;

        cout << "After pass " << i << ": ";
        printArray(a, size);
    }
    cout << "Sorted array: ";
    printArray(a, size);
}

void bubbleSort(int a[], int size) {
    cout << "\n Bubble Sort: \n";
    for (int pass = 0; pass < size - 1; ++pass) {
        for (int j = 0; j < size - pass - 1; ++j) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
        cout << "After pass " << pass + 1 << ": ";
        printArray(a, size);
    }
    cout << "Sorted array: ";
    printArray(a, size);
}

int main() {
    int srand(time(0));
    int unsortedArr[SIZE];

    cout << "Initial array: ";
    for (int i = 0; i < SIZE; ++i) {
        unsortedArr[i] = -20 * N + rand() % (40 * N + 1);
        cout << unsortedArr[i] << " ";
    }
    cout << endl;

    int selectArr[SIZE], insertArr[SIZE], bubbleArr[SIZE];
    for (int i = 0; i < SIZE; ++i) {
        selectArr[i] = insertArr[i] = bubbleArr[i] = unsortedArr[i];
    }

    selectSort(selectArr, SIZE);
    insertSort(insertArr, SIZE);
    bubbleSort(bubbleArr, SIZE);

    return 0;
}
