#include "PmergeMe.hpp"
#include <deque>


int main(int ac, char **av) {
    PmergeMe mainVar;
    try {
        if (ac == 1)
            throw std::runtime_error("Error: Unvalid argument numbers.");

        std::vector<int> unsortedVector = mainVar.Parsing(ac, av);
        std::deque<int> unsortedDeque;
        for (size_t i = 0; i < unsortedVector.size(); i++)
            unsortedDeque.push_back(unsortedVector[i]);

        std::cout << "Before:  ";
        for (size_t i = 0; i < unsortedVector.size(); i++)
            std::cout << unsortedVector[i] << " ";
        std::cout << std::endl;

        time_t startTime;
        time_t doration;

        startTime = mainVar.GetTime();
        std::vector<int> sortedVector = mainVar.SortVector(unsortedVector);
        doration = mainVar.GetTime() - startTime;

        std::cout << "After:   ";
        for (size_t i = 0; i < sortedVector.size(); i++)
            std::cout << sortedVector[i] << " ";
        std::cout << std::endl;

        std::cout << "Time to process a range of " << ac << " elements with std::vector : " << doration << " us" << std::endl;

        startTime = mainVar.GetTime();
        std::deque<int> sortedDeque = mainVar.Sortdeque(unsortedDeque);
        doration = mainVar.GetTime() - startTime;
        std::cout << "Time to process a range of " << ac << " elements with std::deque : " << doration << " us" << std::endl;

    } catch (std::exception &err) {
        std::cerr << err.what() << std::endl;
        return 1;
    }

    return 0;
}
