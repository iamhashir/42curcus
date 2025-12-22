#include "Base.hpp"
#include <iostream>

int main()
{
    Base* obj = generate();

    std::cout << "Pointer identify: ";
    identify(obj);

    std::cout << "Reference identify: ";
    identify(*obj);

    delete obj;
    return 0;
}
