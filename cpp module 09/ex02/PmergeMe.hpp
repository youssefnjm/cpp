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

        std::vector<size_t> GetInsertOrder(std::vector<size_t>& JacSeq, size_t vecPairSize);
        std::vector<size_t> JacobsthalSequenceVector(size_t vecPairSize);
        
    public:
        PmergeMe(void);
        PmergeMe(const PmergeMe& other);
        PmergeMe &operator=(const PmergeMe &other);
        ~PmergeMe();

        static size_t GetTime(void);
        std::vector<int> Parsing(int ac, char **av);
        std::deque<int> Sortdeque(std::deque<int> &seq);
        std::vector<int> SortVector(std::vector<int> &seq);
};

#endif


    // // -------------show entry
    // std::cout << "enter:   [ ";
    // for (size_t i = 0; i < seq.size(); i++) {
    //     std::cout << seq[i] << ", ";
    // }
    // std::cout << "]" << std::endl;

    // // -------------show pairs
    // std::cout << "\npairs:   [ ";
    // for (size_t i = 0; i < vectorOfPairs.size(); i++) {
    //     std::cout << "(" << vectorOfPairs[i].first << ", "<< vectorOfPairs[i].second << ")"  << ", ";
    // }
    // std::cout << "]" << std::endl;

    // // -------------show winners
    // std::cout << "winner:  [ ";
    // for (size_t i = 0; i < winner.size(); i++) {
    //     std::cout << winner[i] << ", ";
    // }
    // std::cout << "]" << std::endl;

    // // -------------show JacSeq
    // std::cout << "JacSeq:  [ ";
    // for (size_t i = 0; i < JacSeq.size(); i++) {
    //     std::cout << JacSeq[i] << ", ";
    // }
    // std::cout << "]" << std::endl;

    
    // // -------------show order
    // std::cout << "order:   [ ";
    // for (size_t i = 0; i < order.size(); i++) {
    //     std::cout << order[i] << ", ";
    // }
    // std::cout << "]" << std::endl;

    // // -------------after sort
    // std::cout << "aftSort: [ ";
    // for (size_t i = 0; i < winner.size(); i++) {
    //     std::cout << winner[i] << ", ";
    // }
    // std::cout << "]" << std::endl;