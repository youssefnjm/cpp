#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <iostream>
#include <vector>
#include <deque>

class PmergeMe
{
    private:
        std::deque<size_t> JacobsthalSequenceDeque(size_t DecPairSize);
        std::deque<size_t> GetInsertOrder(std::deque<size_t>& JacSeq, size_t vecPairSize);

        std::vector<size_t> JacobsthalSequenceVector(size_t vecPairSize);
        std::vector<size_t> GetInsertOrder(std::vector<size_t>& JacSeq, size_t vecPairSize);
        
    public:
        PmergeMe(void);
        PmergeMe(const PmergeMe& other);
        PmergeMe &operator=(const PmergeMe &other);
        ~PmergeMe();

        size_t GetTime(void);
        std::vector<int> Parsing(int ac, char **av);
        std::deque<int> SortDeque(std::deque<int> &seq);
        std::vector<int> SortVector(std::vector<int> &seq);
};

#endif
