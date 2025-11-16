#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>
#include <exception>
#include <iostream>

Base::~Base(void) {}

Base* Base::generate() {
    int i = time(NULL) % 3;

    if (i == 0)
        return new A();
    else if (i == 1)
        return new B();
    else
        return new C();
}

void Base::identify(Base* p) {
    if (dynamic_cast<A *>(p))
        std::cout << 'A' << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << 'B' << std::endl;
    else if (dynamic_cast<C *>(p))
        std::cout << 'C' << std::endl;
    else
        std::cout << "unknown" << std::endl;
};

void Base::identify(Base& p) {
    try {
        A a = dynamic_cast<A&>(p);
        std::cout << 'A' << std::endl;
    } catch (std::exception &e) {
        try {
            B b = dynamic_cast<B&>(p);
            std::cout << 'B' << std::endl;
        } catch (std::exception &e) {
            try {
                C c = dynamic_cast<C&>(p);
                std::cout << 'B' << std::endl;
            } catch (std::exception &e) {
                std::cout << "unknown" << std::endl;
            }
        }
    }
};