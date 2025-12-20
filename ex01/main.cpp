#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    std::cout << "==== Constructor tests ====" << std::endl;
    try
    {
        Form badHigh("BadHigh", 0, 10);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        Form badLow("BadLow", 10, 151);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n==== Valid objects ====" << std::endl;
    Bureaucrat boss("Boss", 1);
    Bureaucrat intern("Intern", 150);

    Form topSecret("TopSecret", 10, 5);
    Form paperwork("Paperwork", 140, 100);

    std::cout << boss << std::endl;
    std::cout << intern << std::endl;
    std::cout << topSecret << std::endl;
    std::cout << paperwork << std::endl;

    std::cout << "\n==== Signing attempts ====" << std::endl;

    intern.signForm(topSecret);
    boss.signForm(topSecret);

    std::cout << topSecret << std::endl;

    intern.signForm(paperwork);
    boss.signForm(paperwork);

    std::cout << paperwork << std::endl;

    std::cout << "\n==== Re-signing test ====" << std::endl;
    boss.signForm(topSecret);

    std::cout << "\n==== Copy & assignment tests ====" << std::endl;
    Form copy = paperwork;
    std::cout << copy << std::endl;

    Form assigned("Assigned", 50, 50);
    assigned = paperwork;
    std::cout << assigned << std::endl;

    return 0;
}
