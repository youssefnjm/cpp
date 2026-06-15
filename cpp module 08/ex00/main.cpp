#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>
#include <iostream>

#define ARRAY_SIZE 10
#define FIND_VAL 5

int main( void )
{
    // ################### vector 
    std::vector<int> vector;
    for (size_t i = 0; i <= ARRAY_SIZE; i++)
        vector.push_back(i);

    std::vector<int>::iterator vectorIt = easyfind(vector, FIND_VAL);
    if (vectorIt != vector.end())
        std::cout << "founded value from vector: " << *vectorIt << std::endl;
    else
        std::cout << "value not found from vector!" << std::endl;


    // ################### list 
    std::list<int> list;
    for (size_t i = 0; i <= ARRAY_SIZE; i++)
        list.push_back(i);

    std::list<int>::iterator listIt = easyfind(list, FIND_VAL);
    if (listIt != list.end())
        std::cout << "founded value from list: " << *listIt << std::endl;
    else
        std::cout << "value not found from list!" << std::endl;


    // ################### deque 
    std::deque<int> deque;
    for (size_t i = 0; i < ARRAY_SIZE; i++)
        deque.push_back(i);

    std::deque<int>::iterator dequeIt = easyfind(deque, FIND_VAL);
    if (dequeIt != deque.end())
        std::cout << "founded value from deque: " << *dequeIt << std::endl;
    else
        std::cout << "value not found from deque!" << std::endl;

    return 0;
}
