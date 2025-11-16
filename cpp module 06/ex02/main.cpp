#include "./Base.hpp"

int main()
{
    Base tmp;

    Base *ptr = tmp.generate();
    tmp.identify(ptr);

    Base &ref = *ptr;
    tmp.identify(ref);
    
    delete ptr;
    return (0);
}