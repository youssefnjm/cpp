#include "./Serializer.hpp"

int main() {
    Data *data = new Data();
    data->x = 5;

    uintptr_t address = Serializer::serialize(data);

    std::cout << "address: " << address << "\n";

    Data *ptr = Serializer::deserialize(address);
    
    std::cout << "after cast: " << ptr->x << "\n";

    delete data;

    return (0);
}