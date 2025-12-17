#ifndef WHATEVER_HPP
# define WHATEVER_HPP
# include <iostream>

class Whatever
{
    public:
        Whatever(void);
        Whatever(const Whatever& other);
        Whatever &operator=(const Whatever &other);
        ~Whatever();
};

#endif

