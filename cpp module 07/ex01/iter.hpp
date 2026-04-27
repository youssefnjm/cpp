#ifndef ITER_HPP
# define ITER_HPP
#include <cstddef>

template <typename T1, typename T2>

void iter(T1 *arr, size_t len, void (*fun)(T2 &))
{
    for (size_t i = 0; i < len; i++) {
        fun(arr[i]);
    }
}

#endif