#ifndef ARRAY_HPP
# define ARRAY_HPP
#include <cstddef>
#include <exception>
# include <iostream>
#include <stdexcept>


template <typename T> class Array {
    public:
        T *a;
        size_t size;

        Array() {
            a = new T[0];
        }
        Array(unsigned int n) {
            size = n;
            a = new T[size];
        }
        Array(const Array &array) {
            this->a = NULL;
            *this = array;
        }
        Array operator =(const Array &array) {
            if (this != &array)
            {
                if (this->a != NULL)
                    delete[] this->a;
                this->a = new T[array.size];

                std::cout << "here " << std::endl;
                for (size_t i = 0; i < array.size; i++) {

                    this->a[i] = array.a[i];
                }
            }
            return *this;
        }
        
        T& operator[](size_t idx) {
            if (idx < 0 || idx >= this->size)
                throw std::out_of_range ("blah");;
            return this->a[idx];
        }

        // T& operator[](size_t idx) const {
        //     if (idx >= this->size)
        //         throw std::out_of_range ("blah");;
        //     return this->a[idx];
        // }

};


#endif

