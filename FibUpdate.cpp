#include <iostream>
#include <vector>
#include <algorithm>

constexpr std::size_t NOT_FOUND = static_cast<std::size_t>(-1);

// Function to calculate Fibonacci numbers
std::size_t calculateFibonacci(std::size_t n) {
    if (n <= 1) return n;
    std::size_t fibM2 = 0;
    std::size_t fibM1 = 1;
    std::size_t fibM = fibM2 + fibM1;
    for (std::size_t i = 2; i <= n; ++i) {
        fibM = fibM1 + fibM2;
        fibM2 = fibM1;
        fibM1 = fibM;
    }
    return fibM;
}

std::size_t fibonacciSearch(const std::vector<int>& arr, int x) {
    std::size_t fibM = 0;
    std::size_t offset = NOT_FOUND;

    // Find the smallest Fibonacci number greater than or equal to the array size
    while (calculateFibonacci(fibM) < arr.size()) {
        fibM++;
    }

    while (fibM > 0) {
        std::size_t i = std::min(offset + calculateFibonacci(fibM - 2), arr.size() - 1);

        if (arr[i] < x) {
            fibM--;
            offset = i;
        } else if (arr[i] > x) {
            fibM -= 2;
        } else {
            return i;
        }
    }

    if (offset < arr.size() - 1 && arr[offset + 1] == x)
        return offset + 1;

    return NOT_FOUND;
}

int main() {
    std::vector<int> arr = {10, 22, 35, 40, 45, 50, 80, 82, 85, 90, 100, 235};
    int x = 235;
    
    if (!std::is_sorted(arr.begin(), arr.end())) {
        std::cout << "Array must be sorted for Fibonacci search to work." << std::endl;
        return 1;
    }

    std::size_t ind = fibonacciSearch(arr, x);

    if (ind != NOT_FOUND)
        std::cout << "Found at index: " << ind << std::endl;
    else
        std::cout << x << " isn't present in the array" << std::endl;

    return 0;
}
