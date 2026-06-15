#ifndef SPAN_HPP
# define SPAN_HPP
# include <cstddef>
#include <iterator>
# include <vector>

class Span
{
    private:
        size_t size;
        std::vector<int> arr;
    public:
        Span(void);
        Span(unsigned int n);
        Span(const Span& other);
        Span &operator=(const Span &other);
        ~Span();

        void addNumber(int num);
        int shortestSpan();
        int longestSpan();

        template<typename T>
        void addRange(T begin, T end) {
            if (this->arr.size() + (size_t)std::distance(begin, end) > this->size)
                throw ContainerIsFull();

            arr.insert(arr.end(), begin, end);
        };

        class ContainerIsFull : public std::exception {
            const char* what() const throw();
        };
        class NoSpanFound : public std::exception {
            const char* what() const throw();
        };
};

#endif

