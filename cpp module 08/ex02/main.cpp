#include "MutantStack.hpp"
#include <deque>
#include <iostream>

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


    // std::cout << "-------------cars-------------" << std::endl;
    // MutantStack<std::string> mutantstack;

    // mutantstack.push("bmw");
    // mutantstack.push("audi");
    // mutantstack.push("mercideces");
    // mutantstack.push("dacia");

    // MutantStack<std::string>::iterator itEnd =  mutantstack.end();

    // MutantStack<std::string>::iterator find = std::find(mutantstack.begin(), itEnd, "dacia");


    // if (find == itEnd) {
    //     std::cout << "dacia not found!!\n";
    //     return 1;
    // }

    // *find = "volkswagen";

    // while (mutantstack.size()) {
    //     std::cout << mutantstack.top() << " | ";
    //     mutantstack.pop();
    // }

    // std::cout << std::endl;

    return 0;
}
