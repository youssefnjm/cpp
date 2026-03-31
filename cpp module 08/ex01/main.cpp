#include "Span.hpp"
#include <cstddef>
#include <exception>
#include <iostream>
#include <vector>

# define SIZE_ARR 10000

int main()
{
    Span sp = Span(5);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    std::cout << "------------------------------" << std::endl;

    try {
        Span sp = Span(SIZE_ARR);

        std::vector<int> range;
        for (size_t i = 0; i < SIZE_ARR; i++) {
            range.push_back(i);
        }

        sp.addRange(range.begin(), range.end());

        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch (std::exception &exception) {
        std::cout << exception.what() << std::endl;
    }

    return (0);
}
