#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
    public:
        typedef typename std::stack<T>::container_type::iterator iterator;
        typedef typename std::stack<T>::container_type::const_iterator const_iterator;

        MutantStack() {};
        MutantStack(const MutantStack<T> &other) { *this = other; };
        ~MutantStack() {};
        MutantStack &operator=(const MutantStack<T> &other) {
            if (this != &other)
                std::stack<T>::operator=(other);
            return *this;
        };

        iterator begin(void) {
            return this->c.begin();
        };
        iterator end(void) {
            return this->c.end();
        };

        const_iterator begin(void) const {
            return this->c.begin();
        };
        const_iterator end(void) const {
            return this->c.end();
        };
};

#endif
