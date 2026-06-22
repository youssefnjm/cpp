#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <iostream>

class PmergeMe
{
    public:
        PmergeMe(void);
        PmergeMe(const PmergeMe& other);
        PmergeMe &operator=(const PmergeMe &other);
        ~PmergeMe();

        static void run(int ac, char **av);
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