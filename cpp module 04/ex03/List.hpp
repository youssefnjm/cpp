#ifndef LIST_HPP
# define LIST_HPP
#include "AMateria.hpp"

class AMateria;

struct List
{
    static List *_head;
    AMateria *_ptr;
    List *_next;

    List(void);

    static void addLast(AMateria *ptr);
    static void freeAll();
    
};


#endif

