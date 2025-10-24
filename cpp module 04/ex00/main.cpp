#include "Cat.hpp"
#include "Dog.hpp"
#include "new"

int main()
{
    const Animal* meta = new Animal();
    const Animal* i = new Cat();
    const Animal* j = new Dog();

    std::cout << i->getType() << " " << std::endl;
    std::cout << j->getType() << " " << std::endl;
    
    j->makeSound();
    i->makeSound();
    meta->makeSound();

    delete meta;
    delete i;
    delete j;

    return (0);
}
