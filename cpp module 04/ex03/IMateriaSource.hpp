#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP
# include <iostream>

class AMateria;

class IMateriaSource
{
    public:

        virtual ~IMateriaSource();

        virtual void learnMateria(AMateria *tmp) = 0;
        virtual AMateria* createMateria(std::string material) = 0;

};

#endif

