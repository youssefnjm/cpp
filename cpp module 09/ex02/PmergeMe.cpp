#include "PmergeMe.hpp"
#include <algorithm>
#include <cerrno>
#include <cstddef>
#include <ctime>
#include <deque>
#include <iterator>
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

// std::deque<int> vectorToDeque(std::vector<int> sequence) {
//     std::deque<int> deque;

//     for (size_t i = 0; i < sequence.size(); i++)
//         deque.push_back(sequence[i]);
    
//     return deque;
// };

std::vector<size_t> JacobsthalSequence(size_t vecPairSize) {
    std::vector<size_t> JacSeq;

    JacSeq.push_back(0);
    JacSeq.push_back(1);
    while (JacSeq.back() < vecPairSize) {
        size_t res = JacSeq[JacSeq.size() - 1] + 2 * JacSeq[JacSeq.size() - 2];
        JacSeq.push_back(res);
    }
    return JacSeq;
}

std::vector<size_t> InsertOrder(std::vector<size_t>& JacSeq, size_t vecPairSize) {
    std::vector<size_t> order;
    order.push_back(0);

    for (size_t i = 3; i < JacSeq.size(); i++) {
        size_t first = JacSeq[i] - 1;
        size_t second = JacSeq[i - 1];

        if (first >= vecPairSize)
            first = vecPairSize - 1;

        std::cout << "first: " << first << " second: " << second << std::endl;

        for (size_t index = first; index >= second; index--)
            order.push_back(index);

    }
    return order;
};

void sortByOrder(std::vector<std::pair<int, int> > &vectorOfPairs, std::vector<int> &newSeq, std::vector<size_t> &order) {
    for (size_t i = 0; i < order.size(); i++) {
        size_t idx = order[i];
        int winnerPair = vectorOfPairs[idx].first;
        int loserPair = vectorOfPairs[idx].second;
        
        std::vector<int>::iterator it = std::find(newSeq.begin(), newSeq.end(), winnerPair);

        std::vector<int>::iterator insertIn = std::lower_bound(newSeq.begin(), it, loserPair);

        newSeq.insert(insertIn, loserPair);
    }
};

std::vector<int> sortVector(std::vector<int> &seq) {
    // -------------show entry
    std::cout << "enter:   [ ";
    for (size_t i = 0; i < seq.size(); i++) {
        std::cout << seq[i] << ", ";
    }
    std::cout << "]" << std::endl;

    if (seq.size() == 1)
        return seq;

    int straggler = -1;
    if (seq.size() % 2 != 0) {
        straggler = seq.back();
        seq.pop_back();
    }

    std::vector<std::pair<int, int> > vectorOfPairs;
    for (size_t i = 0; i < seq.size(); i += 2) {
        vectorOfPairs.push_back(std::make_pair(seq[i], seq[i + 1]));
        if (vectorOfPairs.back().second > vectorOfPairs.back().first)
            std::swap(vectorOfPairs.back().second, vectorOfPairs.back().first);
    }

    std::vector<int> newSeq;
    for (size_t i = 0; i < vectorOfPairs.size(); i++) {
        newSeq.push_back(vectorOfPairs[i].first);
    }


    std::vector<int> winner = sortVector(newSeq);

    // -------------show pairs
    std::cout << "\npairs:   [ ";
    for (size_t i = 0; i < vectorOfPairs.size(); i++) {
        std::cout << "(" << vectorOfPairs[i].first << ", "<< vectorOfPairs[i].second << ")"  << ", ";
    }
    std::cout << "]" << std::endl;

    // -------------show winners
    std::cout << "winner:  [ ";
    for (size_t i = 0; i < winner.size(); i++) {
        std::cout << winner[i] << ", ";
    }
    std::cout << "]" << std::endl;

    std::vector<size_t> JacSeq = JacobsthalSequence(vectorOfPairs.size());
    // -------------show winners
    std::cout << "JacSeq:  [ ";
    for (size_t i = 0; i < JacSeq.size(); i++) {
        std::cout << JacSeq[i] << ", ";
    }
    std::cout << "]" << std::endl;

    std::vector<size_t> order = InsertOrder(JacSeq, vectorOfPairs.size());

    // -------------show winners
    std::cout << "order:   [ ";
    for (size_t i = 0; i < order.size(); i++) {
        std::cout << order[i] << ", ";
    }
    std::cout << "]" << std::endl;

    sortByOrder(vectorOfPairs, winner, order);

    if (straggler != -1) {
        std::vector<int>::iterator insertIn = std::lower_bound(winner.begin(), winner.end(), straggler);

        winner.insert(insertIn, straggler);
    }

    std::cout << "aftSort: [ ";
    for (size_t i = 0; i < winner.size(); i++) {
        std::cout << winner[i] << ", ";
    }
    std::cout << "]" << std::endl;

    return winner;
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
    std::vector<int> res = sortVector(sequence);
    std::cout << "\n########### final = { ";
    for (size_t i = 0; i < res.size(); i++) {
        std::cout << res[i] << ", ";
    }
    std::cout << "} ###########\n";
    // std::cout << "Time to process a range of " << ac << " elements with std::vector : " << 0 << " us" << std::endl;
    // endTime = getTime();

    // startTime = getTime();
    // sortDeque(vectorToDeque(sequence));
    // std::cout << "Time to process a range of " << ac << " elements with std::deque : " << 0 << " us" << std::endl;
    // endTime = getTime();

};
