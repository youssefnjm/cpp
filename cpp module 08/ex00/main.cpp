#include "easyfind.hpp"
#include <cstddef>
#include <exception>
#include <vector>
#include <list>
#include <deque>
#include <iostream>

#define ARRAY_SIZE 10
#define FIND_VAL 3

int main( void )
{
    // ################### vector 
    try {
        std::vector<int> conatiner;

        for (size_t i = 0; i <= ARRAY_SIZE; i++) {
            conatiner.push_back(i);
        }

        int valInt = easyfind(conatiner, FIND_VAL);
        std::cout << "founded value: " << valInt << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    // ################### list 
    try {
        std::list<int> conatiner;

        for (size_t i = 0; i <= ARRAY_SIZE; i++) {
            conatiner.push_back(i);
        }

        int valInt = easyfind(conatiner, FIND_VAL);
        std::cout << "founded value: " << valInt << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    // ################### deque 
    try {
        std::deque<int> conatiner;

        for (size_t i = 0; i < ARRAY_SIZE; i++) {
            conatiner.push_back(i);
        }

        int valInt = easyfind(conatiner, FIND_VAL);
        std::cout << "founded value: " << valInt << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
