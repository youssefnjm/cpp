#include "Cat.hpp"
#include "Dog.hpp"
#include "new"

void gg(){
    system("leaks a.out");
}
int main()
{
    atexit(gg);

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


    // Dog *dog1 = new Dog();
    // Dog *dog2 = new Dog();

    // *dog1 = *dog2;

    // delete dog1;
    // delete dog2;

    return (0);
}
