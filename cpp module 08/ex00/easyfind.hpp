#ifndef WHATEVER_HPP
# define WHATEVER_HPP
#include <algorithm>
#include <exception>

class ValueNotFound : public std::exception
{
    const char* what() const throw() {
        return "value not found!!";
    };
};

template <typename T>
int easyfind(T &container, int val)
{
    if (std::find(container.begin(), container.end(), val) == container.end())
        throw ValueNotFound();

    return val;
}

#endif

