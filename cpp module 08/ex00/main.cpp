#include "easyfind.hpp"
#include <cstddef>
#include <exception>
#include <vector>

#define ARRAY_SIZE 10

int main( void ) {
    try {
        std::vector<int> vecInt;

        int findInt;
        for (size_t i = 0; i <= ARRAY_SIZE; i++) {
            vecInt.push_back(i);
        }
        findInt = ARRAY_SIZE / 2;

        int valInt = easyfind(vecInt, findInt);
        std::cout << "value wanna be found: " << findInt << ", founded value: " << valInt << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    

    try {
        std::vector<long long > vecLong;
        int find;
        for (size_t i = 0; i <= ARRAY_SIZE; i++) {
            long long tmp = static_cast<long>(2147483648) + i;
            vecLong.push_back(tmp);
        }
        find = ARRAY_SIZE / 2;

        long long val = easyfind(vecLong, find);
        std::cout << "value wanna be found: " << find << " founded value: " << val << std::endl;
    
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
