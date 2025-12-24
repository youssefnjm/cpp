#ifndef ARRAY_HPP
# define ARRAY_HPP
#include <cstddef>
#include <exception>
# include <iostream>
#include <stdexcept>


template <typename T> class Array {
    public:
        T *arr;
        size_t size;

        Array() {
            size = 0;
            arr = new T[0];
        }
        Array(unsigned int n) {
            size = n;
            arr = new T[size];
        }
        Array(const Array &other) {
            this->arr = NULL;
            *this = other;
        }
        Array& operator =(const Array &other) {
            if (this != &other)
            {
                delete[] this->arr;

                this->size = other.size;
                this->arr = new T[size];

                for (size_t i = 0; i < this->size; i++) {
                    this->arr[i] = other.arr[i];
                }
            }
            return *this;
        }

        T& operator[](size_t idx) {
            if (idx >= this->size)
                throw std::out_of_range ("indx out of range");
            return this->arr[idx];
        }
};

#endif