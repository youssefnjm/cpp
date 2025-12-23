#include "iter.hpp"
#include <array>

void fun(int &a) {
    std::cout << a << " ";
    a += 10;
}

int main() {
    std::array<int, 5> arr;

    for (size_t i = 0; i < arr.size(); i++)
        arr[i] = i;

    for (size_t i = 0; i < arr.size(); i++)
        std::cout << arr[i] << " ";

    std::cout << std::endl;

    iter(&arr[0], 5, fun);

    std::cout << std::endl;

    for (size_t i = 0; i < arr.size(); i++)
        std::cout << arr[i] << " " << std::endl;
    return 0;
}