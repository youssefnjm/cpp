#include "PmergeMe.hpp"
#include <algorithm>
#include <cerrno>
#include <utility>
#include <sys/time.h>
#include <vector>

PmergeMe::PmergeMe(void) {};
PmergeMe::~PmergeMe(void) {};
PmergeMe::PmergeMe(const PmergeMe &other) { (void)other; };
PmergeMe &PmergeMe::operator=(const PmergeMe &other) { (void) other; return (*this); };

size_t PmergeMe::GetTime(void) {
    struct timeval tv;

    gettimeofday(&tv, NULL);
    return tv.tv_sec * 1000000 + tv.tv_usec;
};

// ################################## VECTOR
std::vector<size_t> PmergeMe::JacobsthalSequenceVector(size_t vecPairSize) {
    std::vector<size_t> JacSeq;

    JacSeq.push_back(0);
    JacSeq.push_back(1);
    while (JacSeq.back() < vecPairSize) {
        size_t res = JacSeq[JacSeq.size() - 1] + 2 * JacSeq[JacSeq.size() - 2];
        JacSeq.push_back(res);
    }
    return JacSeq;
};

std::vector<size_t> PmergeMe::GetInsertOrder(std::vector<size_t>& JacSeq, size_t vecPairSize) {
    std::vector<size_t> order;
    order.push_back(0);

    for (size_t i = 3; i < JacSeq.size(); i++) {
        size_t first = JacSeq[i] - 1;
        size_t second = JacSeq[i - 1];

        if (first >= vecPairSize) first = vecPairSize - 1;

        for (size_t index = first; index >= second; index--)
            order.push_back(index);
    }
    return order;
};

std::vector<int> PmergeMe::SortVector(std::vector<int> &seq) {
    if (seq.size() == 1)
        return seq;

    int straggler = -1;
    if (seq.size() % 2 != 0) {
        straggler = seq.back();
        seq.pop_back();
    }

    std::vector<std::pair<int, int> > vectorOfPairs;
    std::vector<int> winners;
    for (size_t i = 0; i < seq.size(); i += 2) {
        int bigger = seq[i];
        int smaller = seq[i + 1];
        if (smaller > bigger) 
            std::swap(bigger, smaller);
        vectorOfPairs.push_back(std::make_pair(bigger, smaller));
        winners.push_back(bigger);
    }

    winners = SortVector(winners);
    std::vector<size_t> JacSeq = JacobsthalSequenceVector(vectorOfPairs.size());
    std::vector<size_t> order = GetInsertOrder(JacSeq, vectorOfPairs.size());

    for (size_t i = 0; i < order.size(); i++) {
        size_t idx = order[i];
        std::vector<int>::iterator it = std::find(winners.begin(), winners.end(), vectorOfPairs[idx].first);
        std::vector<int>::iterator insertIn = std::lower_bound(winners.begin(), it, vectorOfPairs[idx].second);
        winners.insert(insertIn, vectorOfPairs[idx].second);
    }

    if (straggler != -1) {
        std::vector<int>::iterator insertIn = std::lower_bound(winners.begin(), winners.end(), straggler);
        winners.insert(insertIn, straggler);
    }

    return winners;
};

// ################################## DEQUE
std::deque<size_t> PmergeMe::JacobsthalSequenceDeque(size_t DecPairSize) {
    std::deque<size_t> JacSeq;

    JacSeq.push_back(0);
    JacSeq.push_back(1);
    while (JacSeq.back() < DecPairSize) {
        size_t res = JacSeq[JacSeq.size() - 1] + 2 * JacSeq[JacSeq.size() - 2];
        JacSeq.push_back(res);
    }
    return JacSeq;
};

std::deque<size_t> PmergeMe::GetInsertOrder(std::deque<size_t>& JacSeq, size_t DeqPairSize) {
    std::deque<size_t> order;
    order.push_back(0);

    for (size_t i = 3; i < JacSeq.size(); i++) {
        size_t first = JacSeq[i] - 1;
        size_t second = JacSeq[i - 1];

        if (first >= DeqPairSize)
            first = DeqPairSize - 1;

        for (size_t index = first; index >= second; index--)
            order.push_back(index);

    }
    return order;
};

std::deque<int> PmergeMe::SortDeque(std::deque<int> &seq) {
    if (seq.size() == 1)
        return seq;

    int straggler = -1;
    if (seq.size() % 2 != 0) {
        straggler = seq.back();
        seq.pop_back();
    }

    std::deque<std::pair<int, int> > dequeOfPairs;
    std::deque<int> winners;
    for (size_t i = 0; i < seq.size(); i += 2) {
        int bigger = seq[i];
        int smaller = seq[i + 1];
        if (smaller > bigger) 
            std::swap(bigger, smaller);
        dequeOfPairs.push_back(std::make_pair(bigger, smaller));
        winners.push_back(bigger);
    }

    winners = SortDeque(winners);
    std::deque<size_t> JacSeq = JacobsthalSequenceDeque(dequeOfPairs.size());
    std::deque<size_t> order = GetInsertOrder(JacSeq, dequeOfPairs.size());

    for (size_t i = 0; i < order.size(); i++) {
        size_t idx = order[i];
        std::deque<int>::iterator it = std::find(winners.begin(), winners.end(), dequeOfPairs[idx].first);
        std::deque<int>::iterator insertIn = std::lower_bound(winners.begin(), it, dequeOfPairs[idx].second);
        winners.insert(insertIn, dequeOfPairs[idx].second);
    }

    if (straggler != -1) {
        std::deque<int>::iterator insertIn = std::lower_bound(winners.begin(), winners.end(), straggler);
        winners.insert(insertIn, straggler);
    }

    return winners;
};

std::vector<int> PmergeMe::Parsing(int ac, char **av) {
    std::vector<int> sequence;

    for (int i = 1; i < ac; i++) {
        char *end = NULL;
        errno = 0;
        long num = std::strtol(av[i], &end, 10);

        if (av[i][0] == '\0' || *end != '\0')
            throw std::runtime_error("Error: Invalid Argument (should contain only numbers).");

        if (errno == ERANGE || !(num >= 0 && num <= 2147483647))
            throw std::runtime_error("Error: Invalid Argument (only positive numbers).");

        sequence.push_back(num);
    }
    return sequence;
};
