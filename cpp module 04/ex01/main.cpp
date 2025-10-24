#include "Cat.hpp"
#include "Dog.hpp"
#include "new"

int main()
{
    Animal* buffer[] = {
        new Dog(),
        new Cat(),
    };

    for (int i = 0; i < 2; i++) 
    {
        buffer[i]->makeSound();
    }

    for (int i = 0; i < 2; i++) 
    {
        delete buffer[i];
        buffer[i] = NULL;
    }

    return (0);
}
