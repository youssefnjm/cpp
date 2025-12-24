#ifndef WHATEVER_HPP
# define WHATEVER_HPP
#include <cstddef>
#include <exception>
# include <iostream>

class ValueNotFound : public std::exception {
    const char* what() const throw() {
        return "value not found!!";
    }
};

template <typename T> int easyfind(T &x, int y)
{
    for (size_t i = 0; i < x.size(); i++) {
        if (y == x[i])
            return x[i];
    }
    throw ValueNotFound();
}

#endif

