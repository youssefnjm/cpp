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
    // std::cout << "enter: [ ";
    // for (size_t i = 0; i < sequence.size(); i++) {
    //     std::cout << sequence[i] << ", ";
    // }
    // std::cout << "]" << std::endl;
    // // -------------show pairs
    // std::cout << "pairs: [ ";
    // for (size_t i = 0; i < vectorOfPairs.size(); i++) {
    //     std::cout << "(" << vectorOfPairs[i].first << ", "<< vectorOfPairs[i].second << ")"  << ", ";
    // }
    // std::cout << "]" << std::endl;
    // // -------------show winners
    // std::cout << "winners: [ ";
    // for (size_t i = 0; i < winners.size(); i++) {
    //     std::cout << winners[i] << ", ";
    // }
    // std::cout << "]" << std::endl;
    // // -------------show losers
    // std::cout << "losers: [ ";
    // for (size_t i = 0; i < losers.size(); i++) {
    //     std::cout << losers[i] << ", ";
    // }
    // std::cout << "]" << std::endl << std::endl;