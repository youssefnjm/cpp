#ifndef SPAN_HPP
# define SPAN_HPP
#include <cstddef>
#include <vector>

class Span
{
    private:
        size_t size;
        std::vector<long> arr;
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

        template<typename T>
        void addRange(T begin, T end) {
            if (begin == end)
                return ;
            T tmp = begin;
            while (tmp != end) {
                this->addNumber(*tmp);
                tmp++;
            }
        };

        class ContainerIsFull : public std::exception {
            const char* what() const throw();
        };
        class NoSpanFound : public std::exception {
            const char* what() const throw();
        };
};

#endif

