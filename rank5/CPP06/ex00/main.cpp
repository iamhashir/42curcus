#include <iostream>
#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Usage: ./convert <literal>" << std::endl;
        return 1;
    }

    try
    {   
        std::cout<<"\033[32m=========="<<std::endl;
        ScalarConverter::convert(av[1]);
        std::cout<<"==========\033[0m";
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
