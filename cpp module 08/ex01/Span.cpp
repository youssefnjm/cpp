#include "Span.hpp"
#include <cstddef>

Span::Span(void) : size(0) {}

Span::Span(unsigned int n) : size(n) {}

Span::Span(const Span &other)
{
    size = other.size;
    *this = other;
}

Span &Span::operator=(const Span &other)
{
    if (this != &other) {
        for (size_t i = 0; i < other.arr.size(); i++) {
            arr[i] = other.arr[i];
        }
    }
    return (*this);
}

Span::~Span(void) {}

const char* Span::ContainerIsFull::what() const throw() {
    return "Container is full !!";
};
const char* Span::NoSpanFound::what() const throw() {
    return "no span can be found.";
};

void Span::addNumber(int num) {
    if (this->arr.size() < this->size) {
        this->arr.push_back(num);
        return;
    }
    throw Span::ContainerIsFull();
}

int Span::shortestSpan() {
    if (this->size <= 1)
        throw Span::NoSpanFound();

    int min = arr[0] - arr[1];
    for (size_t i = 0; i < this->size; i++)
    {
        for (size_t j = 0; j < this->size; j++) {
            if (i == j)
                continue ;
            
            int res = arr[i] - arr[j];
            if (res >= 0 && min >= res)
                min = res;
        }
    }
    return min;
};

int Span::longestSpan() {
    if (this->size <= 1)
        throw Span::NoSpanFound();

    int max = arr[0] - arr[1];
    for (size_t i = 0; i < this->size; i++)
    {
        for (size_t j = 0; j < this->size; j++) {
            if (i == j)
                continue ;
            
            int res = arr[i] - arr[j];
            if (res >= 0 && max <= res)
                max = res;
        }
    }
    return max;
};

