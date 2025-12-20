#include "./Serializer.hpp"

int main() {
    Data *a = new Data();    
    a->x = 5;

    uintptr_t k = Serializer::serialize(a);
    Data *b = Serializer::deserialize(k);
    
    std::cout << b->x << std::endl;

    delete a;

    return (0);
}