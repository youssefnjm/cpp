#ifndef ITER_HPP
# define ITER_HPP
# include <iostream>

template <typename T1, typename T2, typename T3>

void iter(T1 *arr, T2 len, T3 fun)
{
    for (T2 i = 0; i < len; i++){
        fun(arr[i]);
    };
}

#endif

