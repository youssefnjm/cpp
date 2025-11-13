#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "new"

int main()
{
    const Animal* meta = new Animal();
    const Animal* i = new Cat();
    const Animal* j = new Dog();
    const WrongAnimal* w = new WrongCat();

    std::cout << i->getType() << " " << std::endl;
    std::cout << j->getType() << " " << std::endl;
    
    j->makeSound();
    i->makeSound();
    meta->makeSound();
    w->makeSound();

    delete meta;
    delete i;
    delete j;
    delete w;

    return (0);
}
