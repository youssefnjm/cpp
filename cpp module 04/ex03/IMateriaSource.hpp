#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP
# include <iostream>

class AMateria;

class IMateriaSource
{
    public:
        IMateriaSource(void);
        IMateriaSource(const IMateriaSource& other);
        IMateriaSource &operator=(const IMateriaSource &other);
        virtual ~IMateriaSource();

        virtual void learnMateria(AMateria *tmp) = 0;
        virtual AMateria* createMateria(std::string material) = 0;

};

#endif

