#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    std::cout << "\033[32m========== FORM CONSTRUCTOR ERRORS ==========\033[0m" << std::endl;
    try
    {
        Form f("TooHigh", 0, 10);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        Form f("TooLow", 10, 151);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n\033[32m========== DEFAULT FORM ==========\033[0m" << std::endl;
    try
    {
        Form f;
        std::cout << f << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n\033[32m========== VALID OBJECTS ==========\033[0m" << std::endl;
    Bureaucrat boss("Boss", 1);
    Bureaucrat mid("Mid", 75);
    Bureaucrat low("Low", 150);

    Form secret("Secret", 10, 5);
    Form paperwork("Paperwork", 140, 100);

    std::cout << boss << std::endl;
    std::cout << mid << std::endl;
    std::cout << low << std::endl;
    std::cout << secret << std::endl;
    std::cout << paperwork << std::endl;

    std::cout << "\n\033[32m========== SIGN FAILURE ==========\033[0m" << std::endl;
    low.signForm(secret);

    std::cout << "\n\033[32m========== SIGN SUCCESS ==========\033[0m" << std::endl;
    boss.signForm(secret);
    std::cout << secret << std::endl;

    std::cout << "\n\033[32m========== BOUNDARY SIGN (EQUAL GRADE) ==========\033[0m" << std::endl;
    try
    {
        Bureaucrat exact("Exact", 140);
        Form boundary("Boundary", 140, 140);
        exact.signForm(boundary);
        std::cout << boundary << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n\033[32m========== RE-SIGN TEST ==========\033[0m" << std::endl;
    boss.signForm(secret);

    std::cout << "\n\033[32m========== COPY CONSTRUCTOR ==========\033[0m" << std::endl;
    Form copy(secret);
    std::cout << copy << std::endl;

    std::cout << "\n\033[32m========== COPY ASSIGNMENT ==========\033[0m" << std::endl;
    Form assigned("Assigned", 50, 50);
    assigned = paperwork;
    std::cout << assigned << std::endl;

    std::cout << "\n\033[32m========== END ==========\033[0m" << std::endl;
    return 0;
}
