#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
    public:
        MutantStack() {};
        MutantStack(const MutantStack<T> &other) {
            *this = other;
        };
        MutantStack &operator=(const MutantStack<T> &other) {
            if (this != &other) {
                std::stack<T>::operator=(other);
            }
            return *this;
        };
        ~MutantStack() {};

        typedef typename std::stack<T>::container_type::iterator iterator;

        iterator begin(void) {
            return this->c.begin();
        };
        iterator end(void) {
            return this->c.end();
        };

};

#endif