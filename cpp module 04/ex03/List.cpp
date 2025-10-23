#include "List.hpp"

List* List::_head = NULL;

// Default constructor
List::List(void) : _ptr(NULL), _next(NULL)
{
    std::cout << "List Default constructor called" << std::endl;
    return ;
}

// ____________ member function
void List::addLast(AMateria *ptr) {
    if (!ptr)
        return ;
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
        if (tmp->_ptr == node->_ptr)
        {
            delete node;
            return ;
        }
        tmp = tmp->_next;
    }
    tmp->_next = node;
}

void List::freeAll()
{
    if (!_head)
        return ;
    while (_head)
    {
        delete _head->_ptr;
        _head->_ptr = NULL;
        List* tmp = _head;
        _head = _head->_next;
        delete tmp;
    }
}