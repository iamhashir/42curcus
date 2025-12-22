#include <iostream>
#include "Serializer.hpp"

int main() {
    Data data;
    data.value = 42;

    uintptr_t raw = Serializer::serialize(&data);
    Data* back = Serializer::deserialize(raw);

    std::cout << "Original address: " << &data << std::endl;
    std::cout << "Deserialized address: " << back << std::endl;

    if (back == &data)
        std::cout << "Pointers are equal" << std::endl;
    else
        std::cout << "Pointers are NOT equal" << std::endl;

    return 0;
}
