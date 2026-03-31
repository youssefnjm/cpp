#include "MutantStack.hpp"
#include <algorithm>
#include <cstddef>
#include <deque>
#include <iostream>
#include <list>
#include <vector>
#define MAX_VAL 10

int main()
{
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << mstack.top() << std::endl;

    mstack.pop();

    std::cout << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }

    std::stack<int> s(mstack);


    // std::vector<std::string> array = { "bmw", "audi", "mercideces", "dacia" };

    // std::cout << "-------------MutantStack-------------" << std::endl;
    // MutantStack<std::string> mstack;

    // mstack.push("bmw");
    // mstack.push("audi");
    // mstack.push("mercideces");
    // mstack.push("dacia");

    // MutantStack<std::string>::iterator it = mstack.begin();
    // MutantStack<std::string>::iterator itEnd =  mstack.end();
    // *it = "volkswagen";

    // while (it != itEnd) {
    //     *it = "dacia";
    //     it++;
    // }

    // it = mstack.begin();
    // while (it != itEnd) {
    //     std::cout << *it << " | ";
    //     ++it;
    // }
    
    // std::cout << "\n-------------vector-------------" << std::endl;
    // std::vector<std::string> s;
    // s.push_back("bmw");
    // s.push_back("audi");
    // s.push_back("mercideces");
    // s.push_back("dacia");

    // MutantStack<std::string>::iterator itt = mstack.begin();
    // MutantStack<std::string>::iterator ittEnd =  mstack.end();

    // *itt = "volkswagen";

    // while (itt != ittEnd) {
    //     *itt = "dacia";
    //     itt++;
    // }
    // itt = mstack.begin();
    // while (itt != ittEnd) {
    //     std::cout << *itt << " | ";
    //     ++itt;
    // }

    return 0;
}
