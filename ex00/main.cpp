#include <iostream>
#include "Bureaucrat.hpp"

int main()
{
    std::cout << "========== DEFAULT CONSTRUCTOR ==========" << std::endl;
    try
    {
        Bureaucrat def;
        std::cout << def << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n========== VALID CONSTRUCTION ==========" << std::endl;
    try
    {
        Bureaucrat high("High", 1);
        Bureaucrat mid("Mid", 75);
        Bureaucrat low("Low", 150);

        std::cout << high << std::endl;
        std::cout << mid << std::endl;
        std::cout << low << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n========== COPY CONSTRUCTOR ==========" << std::endl;
    try
    {
        Bureaucrat original("Original", 42);
        Bureaucrat copy(original);

        std::cout << original << std::endl;
        std::cout << copy << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n========== COPY ASSIGNMENT ==========" << std::endl;
    try
    {
        Bureaucrat a("A", 10);
        Bureaucrat b("B", 100);

        std::cout << a << std::endl;
        std::cout << b << std::endl;

        b = a;

        std::cout << b << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n========== INCREMENT / DECREMENT ==========" << std::endl;
    try
    {
        Bureaucrat b("Worker", 50);

        std::cout << b << std::endl;
        b.incGrade();
        std::cout << b << std::endl;
        b.decGrade();
        std::cout << b << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n========== INCREMENT TOO HIGH ==========" << std::endl;
    try
    {
        Bureaucrat top("Top", 1);
        top.incGrade();
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n========== DECREMENT TOO LOW ==========" << std::endl;
    try
    {
        Bureaucrat bottom("Bottom", 150);
        bottom.decGrade();
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n========== INVALID CONSTRUCTION ==========" << std::endl;
    try
    {
        Bureaucrat bad1("BadHigh", 0);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        Bureaucrat bad2("BadLow", 151);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
