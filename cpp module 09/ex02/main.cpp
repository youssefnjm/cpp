#include "PmergeMe.hpp"

int main(int ac, char **av) {
    try {
        if (ac == 1)
            throw std::runtime_error("Error: Unvalid argument numbers.");

        PmergeMe mainVar;

        std::vector<int> sequence = mainVar.Parsing(ac, av);
        std::vector<int> unsortedVector = sequence;
        std::deque<int> unsortedDeque;
        for (size_t i = 0; i < unsortedVector.size(); i++)
            unsortedDeque.push_back(unsortedVector[i]);

        time_t startTime, dorationVector, dorationDeque;

        startTime = mainVar.GetTime();
        std::vector<int> sortedVector = mainVar.SortVector(unsortedVector);
        dorationVector = mainVar.GetTime() - startTime;

        startTime = mainVar.GetTime();
        std::deque<int> sortedDeque = mainVar.Sortdeque(unsortedDeque);
        dorationDeque = mainVar.GetTime() - startTime;

        std::cout << "Before:  ";
        for (size_t i = 0; i < sequence.size(); i++)
            std::cout << sequence[i] << " ";
        std::cout << std::endl;
        std::cout << "After:   ";
        for (size_t i = 0; i < sortedVector.size(); i++)
            std::cout << sortedVector[i] << " ";
        std::cout << std::endl;
        std::cout << "Time to process a range of " << (ac - 1) << " elements with std::vector : " << dorationVector << " us" << std::endl;
        std::cout << "Time to process a range of " << (ac - 1) << " elements with std::deque : " << dorationDeque << " us" << std::endl;

    } catch (std::exception &err) {
        std::cerr << err.what() << std::endl;
        return 1;
    }

    return 0;
}
