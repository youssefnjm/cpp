#include "Span.hpp"
#include <algorithm>
#include <vector>

Span::Span(void) : size(0) {}
Span::Span(unsigned int n) : size(n) {}
Span::Span(const Span &other) { *this = other; }
Span &Span::operator=(const Span &other)
{
    if (this != &other) {
        this->size = other.size;
        this->arr = other.arr;
    }
    return (*this);
}
Span::~Span(void) {}

const char* Span::ContainerIsFull::what() const throw() {
    return "Container is full !!";
};
const char* Span::NoSpanFound::what() const throw() {
    return "No span can be found.";
};

void Span::addNumber(int num) {
    if (this->arr.size() < this->size) {
        this->arr.push_back(num);
        return ;
    }
    throw Span::ContainerIsFull();
}

int Span::shortestSpan() {
    if (this->arr.size() <= 1)
        throw Span::NoSpanFound();

    std::vector<int> copy = this->arr;
    std::sort(copy.begin(), copy.end());
    int min = copy[1] - copy[0];

    for (size_t i = 0; i < (copy.size() - 1); i++) {
        if (copy[i + 1] - copy[i] < min)
            min = copy[i + 1] - copy[i];
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
