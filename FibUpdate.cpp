#include <iostream>
using namespace std;

int fibonacciSearch(int arr[], int x, int n) {
    int fibM2 = 0; // Two elements before current Fibonacci number
    int fibM1 = 1; // One element before current Fibonacci number
    int fibM = fibM2 + fibM1; // Current Fibonacci number

    // Find the smallest Fibonacci number greater than or equal to n
    while (fibM < n) {
        fibM2 = fibM1;
        fibM1 = fibM;
        fibM = fibM2 + fibM1;
    }

    int offset = -1;

    while (fibM > 1) {
        int i = min(offset + fibM2, n - 1);

        if (arr[i] < x) {
            fibM = fibM1;
            fibM1 = fibM2;
            fibM2 = fibM - fibM1;
            offset = i;
        } else if (arr[i] > x) {
            fibM = fibM2;
            fibM1 = fibM1 - fibM2;
            fibM2 = fibM - fibM1;
        } else {
            return i;
        }
    }

    if (fibM1 && arr[offset + 1] == x)
        return offset + 1;

    return -1;
}

int main() {
    int arr[] = {10, 22, 35, 40, 45, 50, 80, 82, 85, 90, 100, 235};
    int n = sizeof(arr) / sizeof(arr[0);
    int x = 235;
    int ind = fibonacciSearch(arr, x, n);

    if (ind >= 0)
        cout << "Found at index: " << ind << endl;
    else
        cout << x << " isn't present in the array" << endl;

    return 0;
}
//end
