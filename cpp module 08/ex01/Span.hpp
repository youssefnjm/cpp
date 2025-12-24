#ifndef SPAN_HPP
# define SPAN_HPP
#include <cstddef>
# include <iostream>

class Span
{
    private:
        size_t pos;
        size_t size;
        int *arr;
    public:
        Span(void);
        Span(unsigned int n);
        Span(const Span& other);
        Span &operator=(const Span &other);
        ~Span();

        void addNumber(int num);
        void addMore(int num);
        int shortestSpan();
        int longestSpan();

        class ContainerIsFull : public std::exception {
            const char* what() const throw();
        };
        class NoSpanFound : public std::exception {
            const char* what() const throw();
        };
};

#endif

