#include "Span.hpp"
#include <array>
#include <exception>
#include <iostream>

# define SIZE_ARR 5
int main()
{
    Span s = Span(5);

    s.addNumber(6);
    s.addNumber(3);
    s.addNumber(17);
    s.addNumber(9);
    s.addNumber(11);

    std::cout << s.shortestSpan() << std::endl;
    std::cout << s.longestSpan() << std::endl;

    std::cout << std::endl;

    try {
        Span sp = Span(SIZE_ARR);
        // std::array<int, SIZE_ARR> arr = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
        std::array<int, SIZE_ARR> arr = { 6, 3, 17, 9, 11};

        sp.addRange(arr.begin(), arr.end());

        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch (std::exception &exception) {
        std::cout << exception.what();
    }

    return (0);
}