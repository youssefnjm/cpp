#ifndef LIST_HPP
# define LIST_HPP
#include "AMateria.hpp"

class AMateria;
struct List
{
    protected:
    public:
        static List *_head;
        AMateria *_ptr;
        List *_next;

        List(void);
        ~List();

        static void add_last(AMateria *ptr);
        static void free_all();

};


#endif

