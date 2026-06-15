#ifndef WHATEVER_HPP
# define WHATEVER_HPP
#include <algorithm>

template <typename T>
typename T::iterator easyfind(T &container, int val)
{
    typename T::iterator it = std::find(container.begin(), container.end(), val);

    if (it != container.end())
        return it;

    return container.end();
}

#endif

