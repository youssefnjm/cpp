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

template <typename T> int easyfind(T &container, int val)
{
    typename T::iterator res = std::find(container.begin(), container.end(), val);

    if (res == container.end())
        throw ValueNotFound();

    return *res;
}

#endif

