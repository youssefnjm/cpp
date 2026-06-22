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
#include <sys/time.h>

PmergeMe::PmergeMe(void) {};
PmergeMe::~PmergeMe(void) {};
PmergeMe::PmergeMe(const PmergeMe &other) { (void)other; };
PmergeMe &PmergeMe::operator=(const PmergeMe &other) { (void) other; return (*this); };

typedef std::pair<int, int> pair;

size_t getTime(void) {
    struct timeval tv;

    gettimeofday(&tv, NULL);
    return tv.tv_sec * 1000000 + tv.tv_usec;
};

std::vector<size_t> JacobsthalSequenceV(size_t vecPairSize) {
    std::vector<size_t> JacSeq;

    JacSeq.push_back(0);
    JacSeq.push_back(1);
    while (JacSeq.back() < vecPairSize) {
        size_t res = JacSeq[JacSeq.size() - 1] + 2 * JacSeq[JacSeq.size() - 2];
        JacSeq.push_back(res);
    }
    return JacSeq;
};

std::vector<size_t> GetInsertOrder(std::vector<size_t>& JacSeq, size_t vecPairSize) {
    std::vector<size_t> order;
    order.push_back(0);

    for (size_t i = 3; i < JacSeq.size(); i++) {
        size_t first = JacSeq[i] - 1;
        size_t second = JacSeq[i - 1];

        if (first >= vecPairSize)
            first = vecPairSize - 1;

        for (size_t index = first; index >= second; index--)
            order.push_back(index);

    }
    return order;
};

std::vector<int> SortVector(std::vector<int> &seq) {
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

    std::vector<int> winner = SortVector(newSeq);

    std::vector<size_t> JacSeq = JacobsthalSequenceV(vectorOfPairs.size());
    std::vector<size_t> order = GetInsertOrder(JacSeq, vectorOfPairs.size());

    for (size_t i = 0; i < order.size(); i++) {
        size_t idx = order[i];
        int winnerPair = vectorOfPairs[idx].first;
        int loserPair = vectorOfPairs[idx].second;
        
        std::vector<int>::iterator it = std::find(winner.begin(), winner.end(), winnerPair);

        std::vector<int>::iterator insertIn = std::lower_bound(winner.begin(), it, loserPair);

        winner.insert(insertIn, loserPair);
    }

    if (straggler != -1) {
        std::vector<int>::iterator insertIn = std::lower_bound(winner.begin(), winner.end(), straggler);

        winner.insert(insertIn, straggler);
    }

    return winner;
};
// ################################## DEQUE
std::deque<size_t> JacobsthalSequenceD(size_t vecPairSize) {
    std::deque<size_t> JacSeq;

    JacSeq.push_back(0);
    JacSeq.push_back(1);
    while (JacSeq.back() < vecPairSize) {
        size_t res = JacSeq[JacSeq.size() - 1] + 2 * JacSeq[JacSeq.size() - 2];
        JacSeq.push_back(res);
    }
    return JacSeq;
};

std::deque<size_t> GetInsertOrder(std::deque<size_t>& JacSeq, size_t vecPairSize) {
    std::deque<size_t> order;
    order.push_back(0);

    for (size_t i = 3; i < JacSeq.size(); i++) {
        size_t first = JacSeq[i] - 1;
        size_t second = JacSeq[i - 1];

        if (first >= vecPairSize)
            first = vecPairSize - 1;

        for (size_t index = first; index >= second; index--)
            order.push_back(index);

    }
    return order;
};

std::deque<int> Sortdeque(std::deque<int> &seq) {
    if (seq.size() == 1)
        return seq;

    int straggler = -1;
    if (seq.size() % 2 != 0) {
        straggler = seq.back();
        seq.pop_back();
    }

    std::deque<std::pair<int, int> > dequeOfPairs;
    for (size_t i = 0; i < seq.size(); i += 2) {
        dequeOfPairs.push_back(std::make_pair(seq[i], seq[i + 1]));
        if (dequeOfPairs.back().second > dequeOfPairs.back().first)
            std::swap(dequeOfPairs.back().second, dequeOfPairs.back().first);
    }

    std::deque<int> newSeq;
    for (size_t i = 0; i < dequeOfPairs.size(); i++) {
        newSeq.push_back(dequeOfPairs[i].first);
    }

    std::deque<int> winner = Sortdeque(newSeq);

    std::deque<size_t> JacSeq = JacobsthalSequenceD(dequeOfPairs.size());
    std::deque<size_t> order = GetInsertOrder(JacSeq, dequeOfPairs.size());

    for (size_t i = 0; i < order.size(); i++) {
        size_t idx = order[i];
        int winnerPair = dequeOfPairs[idx].first;
        int loserPair = dequeOfPairs[idx].second;
        
        std::deque<int>::iterator it = std::find(winner.begin(), winner.end(), winnerPair);

        std::deque<int>::iterator insertIn = std::lower_bound(winner.begin(), it, loserPair);

        winner.insert(insertIn, loserPair);
    }

    if (straggler != -1) {
        std::deque<int>::iterator insertIn = std::lower_bound(winner.begin(), winner.end(), straggler);

        winner.insert(insertIn, straggler);
    }

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
};

void PmergeMe::run(int ac, char **av) {
    std::vector<int> unsortedVector = parsing(ac, av);
    std::deque<int> unsortedDeque;

    for (size_t i = 0; i < unsortedVector.size(); i++)
        unsortedDeque.push_back(unsortedVector[i]);

    std::cout << "Before:  ";
    for (size_t i = 0; i < unsortedVector.size(); i++) {
        std::cout << unsortedVector[i] << " ";
    }
    std::cout << std::endl;

    time_t startTime;
    time_t doration;

    startTime = getTime();
    std::vector<int> sorted = SortVector(unsortedVector);
    doration = getTime() - startTime;

    std::cout << "After:   ";
    for (size_t i = 0; i < sorted.size(); i++) {
        std::cout << sorted[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Time to process a range of " << ac << " elements with std::vector : " << doration << " us" << std::endl;

    startTime = getTime();
    Sortdeque(unsortedDeque);
    doration = getTime() - startTime;
    std::cout << "Time to process a range of " << ac << " elements with std::deque : " << doration << " us" << std::endl;

};
