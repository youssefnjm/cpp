#ifndef ITER_HPP
# define ITER_HPP
#include <cstddef>

template <typename T1>

void iter(T1 *arr, size_t len, void (*fun)(T1 &))
{
    for (size_t i = 0; i < len; i++) {
        fun(arr[i]);
    }
}

#endif