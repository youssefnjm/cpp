#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP
#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class AMateria;
class IMateriaSource;

class MateriaSource : public IMateriaSource
{
    protected:
        AMateria* _inventory[4];
    public:
        MateriaSource(void);
        MateriaSource(const MateriaSource& other);
        MateriaSource &operator=(const MateriaSource &other);
        ~MateriaSource();

        void learnMateria(AMateria *tmp);
        AMateria* createMateria(std::string material);
};

#endif

