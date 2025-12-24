#include "Span.hpp"
#include <cstddef>

Span::Span(void) : pos(0), size(0), arr(NULL) {}

Span::Span(unsigned int n) : pos(0), size(n), arr(new int[n]) {}

Span::Span(const Span &other)
{
    arr = NULL;
    size = other.size;
    pos = 0;
    *this = other;
}

Span &Span::operator=(const Span &other)
{
    if (this != &other) {
        delete[] arr;

        arr = new int[size];
        
        for (; pos < size; pos++) {
            arr[pos] = other.arr[pos];
        }
    }
    return (*this);
}

Span::~Span(void)
{
    delete[] arr; 
}

const char* Span::ContainerIsFull::what() const throw() {
    return "no span can be found.";
};
const char* Span::NoSpanFound::what() const throw() {
    return "no span can be found.";
};

void Span::addNumber(int num) {
    if (this->pos < this->size) {
        this->arr[this->pos] = num;
        this->pos++;
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
