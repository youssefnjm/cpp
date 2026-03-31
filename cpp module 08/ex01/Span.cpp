#include "Span.hpp"
#include <algorithm>
#include <cstddef>
#include <vector>

Span::Span(void) : size(0) {}

Span::Span(unsigned int n) : size(n) {}

Span::Span(const Span &other) { *this = other; }

Span &Span::operator=(const Span &other)
{
    if (this != &other) {
        size = other.size;

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

    std::sort(this->arr.begin(), this->arr.end());
    int min = this->arr[1] - this->arr[0];

    for (size_t i = 0; i < (this->arr.size() - 1); i++) {
        if (arr[i + 1] - arr[i] < min)
            min = arr[i + 1] - arr[i];
    }

    return min;
};

int Span::longestSpan() {
    if (this->size <= 1)
        throw Span::NoSpanFound();

    std::vector<int>::iterator min = std::min_element(this->arr.begin(), this->arr.end());
    std::vector<int>::iterator max = std::max_element(this->arr.begin(), this->arr.end());

    return *max - *min;
};
