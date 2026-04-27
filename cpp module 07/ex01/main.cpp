#include "iter.hpp"
#include <iostream>

#define ARR_SIZE 5

void MultiplieByTen(int &n1) {
    n1 = n1 * 10;
}

int main() {
    int arr[ARR_SIZE];

    for (int i = 0; i < ARR_SIZE; i++)
        arr[i] = i;

    std::cout << "before: ";
    for (size_t i = 0; i < ARR_SIZE; i++)
        std::cout << arr[i] << " ";

    std::cout << "\n";

    iter(arr, 5, MultiplieByTen);

    std::cout << "\nafter: ";
    for (size_t i = 0; i < ARR_SIZE; i++)
        std::cout << arr[i] << " ";

    return 0;
}