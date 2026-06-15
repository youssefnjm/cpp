#include "MutantStack.hpp"
#include <iostream>

// int main()
// {
//     MutantStack<int> mstack;
//     mstack.push(5);
//     mstack.push(17);

//     std::cout << mstack.top() << std::endl;
//     mstack.pop();
//     std::cout << mstack.size() << std::endl;

//     mstack.push(3);
//     mstack.push(5);
//     mstack.push(737);
//     //[...]
//     mstack.push(0);

//     MutantStack<int>::iterator it = mstack.begin();
//     MutantStack<int>::iterator ite = mstack.end();
    
//     ++it;
//     --it;
//     while (it != ite)
//     {
//         std::cout << *it << std::endl;
//         ++it;
//     }

//     std::stack<int> s(mstack);
//     return 0;
// }


void printStack(const MutantStack<int> &ms) {
    MutantStack<int>::const_iterator it = ms.begin();
    std::cout << "{ ";
    while (it != ms.end()) {
        std::cout << *it << ", ";
        it++;
    }
    std::cout << "}" << std::endl;
}

int main() {
    MutantStack<int> ms1;
    ms1.push(0);
    ms1.push(1);
    ms1.push(2);
    ms1.push(3);

    MutantStack<int> ms2;
    ms1.swap(ms2);

    if (ms1.empty() && !ms2.empty())
        std::cout << "container swaped succesfully!!" << std::endl;

    std::cout << "ms1: ";
    printStack(ms1);

    std::cout << "ms2: ";
    printStack(ms2);

    return 0;
}