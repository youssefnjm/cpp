#include "MutantStack.hpp"
#include <iostream>

int main()
{
    // MutantStack<int> mstack;

    // mstack.push(5);
    // mstack.push(17);

    // std::cout << mstack.top() << std::endl;

    // mstack.pop();

    // std::cout << mstack.size() << std::endl;

    // mstack.push(3);
    // mstack.push(5);
    // mstack.push(737);
    // //[...]
    // mstack.push(0);

    // MutantStack<int>::iterator it = mstack.begin();
    // MutantStack<int>::iterator ite = mstack.end();
    
    // ++it;
    // --it;
    // while (it != ite)
    // {
    //     std::cout << *it << std::endl;
    //     ++it;
    // }

    // std::stack<int> s(mstack);


    std::cout << "-------------cars-------------" << std::endl;
    MutantStack<std::string> carsContainer1;

    carsContainer1.push("bmw");
    carsContainer1.push("audi");
    carsContainer1.push("mercideces");
    carsContainer1.push("dacia");

    MutantStack<std::string> carsContainer2;
    carsContainer1.swap(carsContainer2);

    if (carsContainer1.empty() && !carsContainer2.empty()) {
        std::cout << "container swaped succesfully\n";
    }

    std::cout << "carsContainer1 { ";
    while (carsContainer1.size()) {
        std::cout << carsContainer1.top() << ", ";
        carsContainer1.pop();
    }
    std::cout << "}" << std::endl;

    std::cout << "carsContainer2 { ";
    while (carsContainer2.size()) {
        std::cout << carsContainer2.top() << ", ";
        carsContainer2.pop();
    }
    std::cout << "}" << std::endl;

    return 0;
}
