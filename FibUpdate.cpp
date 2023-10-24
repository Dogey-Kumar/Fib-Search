#include <iostream>
#include <vector>
#include <algorithm>

size_t fibonacciSearch(const std::vector<int>& arr, int x) {
    size_t fibM2 = 0; // Two elements before current Fibonacci number
    size_t fibM1 = 1; // One element before current Fibonacci number
    size_t fibM = fibM2 + fibM1; // Current Fibonacci number

    // Find the smallest Fibonacci number greater than or equal to the array size
    while (fibM < arr.size()) {
        fibM2 = fibM1;
        fibM1 = fibM;
        fibM = fibM2 + fibM1;
    }

    size_t offset = -1;

    while (fibM > 1) {
        size_t i = std::min(offset + fibM2, arr.size() - 1);

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
    std::vector<int> arr = {10, 22, 35, 40, 45, 50, 80, 82, 85, 90, 100, 235};
    int x = 235;
    size_t ind = fibonacciSearch(arr, x);

    if (ind != -1)
        std::cout << "Found at index: " << ind << std::endl;
    else
        std::cout << x << " isn't present in the array" << std::endl;

    return 0;
}
