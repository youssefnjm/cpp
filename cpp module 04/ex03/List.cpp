#include "List.hpp"

List* List::_head = NULL;

// Default constructor
List::List(void) : _ptr(NULL), _next(NULL)
{
    std::cout << "Default constructor called" << std::endl;
    return ;
}

// Destructor
List::~List(void)
{
    std::cout << "Destructor called" << std::endl;
    return ;
}

// ____________ member function
void List::add_last(AMateria *ptr) {

    List *node = new List;
    node->_ptr = ptr;
    node->_next = NULL;

    if (_head == NULL)
    {
        _head = node;
        return ;
    }
    List *tmp = _head;
    while (tmp->_next != NULL) {
        tmp = tmp->_next;
    }
    tmp->_next = node;
}

void List::free_all()
{
    if (!_head)
        return ;
    while (_head)
    {
        delete _head->_ptr;
        List* tmp = _head;
        _head = _head->_next;
        delete tmp;
    }
}