#include "PmergeMe.hpp"
#include <cerrno>
#include <cstddef>
#include <ctime>
#include <deque>
#include <stdexcept>
#include <utility>
#include <vector>

PmergeMe::PmergeMe(void) {};
PmergeMe::~PmergeMe(void) {};
PmergeMe::PmergeMe(const PmergeMe &other) { (void)other; };
PmergeMe &PmergeMe::operator=(const PmergeMe &other) { (void) other; return (*this); };

typedef std::pair<int, int> pair;

time_t getTime(void) {
    return std::time(NULL) * 1000000;
}

// void sortDeque(std::deque<int> sequence) {
//     std::vector<std::pair<int, int> > seqDeque;
//     int straggler = -1;
    
//     if (sequence.size() % 2 == 0) {
//         for (size_t i = 0; i < sequence.size(); i++)
//             seqDeque.push_back(std::make_pair(sequence[i], sequence[i + 1]));
//     } else {
//         straggler = sequence.back();
        
//         for (size_t i = 0; i < sequence.size() - 1; i++)
//             seqDeque.push_back(std::make_pair(sequence[i], sequence[i + 1]));
//     }
// };

// std::deque<int> vectorToDeque(std::vector<int> sequence) {
//     std::deque<int> deque;

//     for (size_t i = 0; i < sequence.size(); i++)
//         deque.push_back(sequence[i]);
    
//     return deque;
// };

void inserLosers(std::vector<int> &winners, std::vector<std::pair<int, int> > &losers) {
    for (size_t i = 0; i < losers.size(); i++) {
        std::vector<int>::iterator pairesWinner = std::find(winners.begin(), winners.end(), losers[i].second);

        winners.insert(pairesWinner, losers[i].first);
    }
};

void PairAndCompare(std::vector<int> &sequence) {
    if (sequence.size() == 1)
        return ;

    std::vector<std::pair<int, int> > vectorOfPairs;
    for (size_t i = 0; i < sequence.size(); i += 2) {
        vectorOfPairs.push_back(std::make_pair(sequence[i], sequence[i + 1]));
        if (vectorOfPairs.back().second > vectorOfPairs.back().first)
            std::swap(vectorOfPairs.back().second, vectorOfPairs.back().first);
    }

    std::vector<int> winners;
    std::vector<std::pair<int, int> > losers;
    for (size_t i = 0; i < vectorOfPairs.size(); i++) {
        winners.push_back(vectorOfPairs[i].first);
        losers.push_back(std::make_pair(vectorOfPairs[i].second, vectorOfPairs[i].first));
    }

    // -------------show entry
    std::cout << "enter:   [ ";
    for (size_t i = 0; i < sequence.size(); i++) {
        std::cout << sequence[i] << ", ";
    }
    std::cout << "]" << std::endl;
    // -------------show pairs
    std::cout << "pairs:   [ ";
    for (size_t i = 0; i < vectorOfPairs.size(); i++) {
        std::cout << "(" << vectorOfPairs[i].first << ", "<< vectorOfPairs[i].second << ")"  << ", ";
    }
    std::cout << "]" << std::endl;
    // -------------show winners
    std::cout << "winners: [ ";
    for (size_t i = 0; i < winners.size(); i++) {
        std::cout << winners[i] << ", ";
    }
    std::cout << "]" << std::endl;
    // -------------show losers
    std::cout << "losers:  [ ";
    for (size_t i = 0; i < losers.size(); i++) {
        std::cout << losers[i].first << ", ";
    }
    std::cout << "]" << std::endl << std::endl;

    PairAndCompare(winners);

    inserLosers(winners, losers);

    std::cout << "insertion:  [ ";
    for (size_t i = 0; i < winners.size(); i++) {
        std::cout << winners[i] << ", ";
    }
    std::cout << "]" << std::endl << std::endl;
}

void sortVector(std::vector<int> &sequence) {
    int straggler = -1;
    if (sequence.size() % 2 != 0) {
        straggler = sequence.back();
        sequence.pop_back();
    }

    PairAndCompare(sequence);


};

std::vector<int> parsing(int ac, char **av) {
    std::vector<int> sequence;

    for (int i = 1; i < ac; i++) {
        char *end = NULL;
        errno = 0;
        long num = std::strtol(av[i], &end, 10);

        if (av[i][0] == '\0' || *end != '\0')
            throw std::runtime_error("Error: Invalid Argument (contain only numbers).");

        if (errno == ERANGE)
            throw std::runtime_error("Error: Invalid Argument (overflow).");

        sequence.push_back(num);
    }
    return sequence;
}

void PmergeMe::run(int ac, char **av) {
    std::vector<int> sequence = parsing(ac, av);

    // std::cout << "{ ";
    // for (size_t i = 0; i < sequence.size(); i++) {
    //     std::cout << sequence[i] << ", ";
    // }
    // std::cout << "}\n";

    // time_t end = getTime();

    // std::cout << "s[" << start << "] - e[" << end << "] = " << (end - start) << std::endl;

    // time_t startTime;
    // time_t endTime;
    // startTime = getTime();
    sortVector(sequence);
    // std::cout << "Time to process a range of " << ac << " elements with std::vector : " << 0 << " us" << std::endl;
    // endTime = getTime();

    // startTime = getTime();
    // sortDeque(vectorToDeque(sequence));
    // std::cout << "Time to process a range of " << ac << " elements with std::deque : " << 0 << " us" << std::endl;
    // endTime = getTime();

};
