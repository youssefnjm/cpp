#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP
# include <iostream>

struct Data {
    int x;
};

class Serializer
{
    public:
        Serializer(void);
        Serializer(const Serializer& other);
        Serializer &operator=(const Serializer &other);
        ~Serializer();

        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif

