#include <iostream>
#include <vector>
#include <algorithm>

constexpr std::size_t NOT_FOUND = static_cast<std::size_t>(-1);

std::size_t fibonacciSearch(const std::vector<int>& arr, int x) {
    std::size_t fibM2 = 0; // Two elements before current Fibonacci number
    std::size_t fibM1 = 1; // One element before current Fibonacci number
    std::size_t fibM = fibM2 + fibM1; // Current Fibonacci number

    // Find the smallest Fibonacci number greater than or equal to the array size
    while (fibM < arr.size()) {
        fibM2 = fibM1;
        fibM1 = fibM;
        fibM = fibM2 + fibM1;
    }

    std::size_t offset = NOT_FOUND; // Initialize offset with NOT_FOUND

    while (fibM > 1) {
        std::size_t i = std::min(offset + fibM2, arr.size() - 1);

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

    return NOT_FOUND;
}

int main() {
    std::vector<int> arr = {10, 22, 35, 40, 45, 50, 80, 82, 85, 90, 100, 235};
    int x = 235;
    std::size_t ind = fibonacciSearch(arr, x);

    if (ind != NOT_FOUND)
        std::cout << "Found at index: " << ind << std::endl;
    else
        std::cout << x << " isn't present in the array" << std::endl;

    return 0;
}
