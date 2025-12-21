#include <iostream>

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    std::cout << "\033[31m========== DEFAULT CONSTRUCTORS ==========\033[0m" << std::endl;
    try
    {
        Bureaucrat defBureaucrat;
        std::cout << defBureaucrat << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n\033[32m========== CREATE BUREAUCRATS ==========\033[0m" << std::endl;
    Bureaucrat boss("Boss", 1);
    Bureaucrat mid("Mid", 50);
    Bureaucrat low("Low", 150);

    std::cout << boss << std::endl;
    std::cout << mid << std::endl;
    std::cout << low << std::endl;

    std::cout << "\n\033[33m========== CREATE FORMS ==========\033[0m" << std::endl;
    ShrubberyCreationForm shrub("home");
    RobotomyRequestForm robot("Bender");
    PresidentialPardonForm pardon("Arthur Dent");

    std::cout << shrub << std::endl;
    std::cout << robot << std::endl;
    std::cout << pardon << std::endl;

    std::cout << "\n\033[34m========== EXECUTE UNSIGNED FORMS ==========\033[0m" << std::endl;
    low.executeForm(shrub);
    mid.executeForm(robot);
    boss.executeForm(pardon);

    std::cout << "\n\033[31m========== SIGN FORMS (FAIL & SUCCESS) ==========\033[0m" << std::endl;
    low.signForm(shrub);
    mid.signForm(shrub);
    mid.signForm(robot);
    mid.signForm(pardon);
    boss.signForm(pardon);

    std::cout << "\n\033[32m========== BOUNDARY SIGN TEST ==========\033[0m" << std::endl;
    try
    {
        Bureaucrat exact("Exact", 145);
        ShrubberyCreationForm boundary("boundary");
        exact.signForm(boundary);
        std::cout << boundary << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n\033[33m========== EXECUTE SHRUBBERY ==========\033[0m" << std::endl;
    mid.executeForm(shrub);

    std::cout << "\n\033[34m========== EXECUTE ROBOTOMY (RANDOM) ==========\033[0m" << std::endl;
    boss.executeForm(robot);
    boss.executeForm(robot);
    boss.executeForm(robot);

    std::cout << "\n\033[31m========== EXECUTE PRESIDENTIAL PARDON ==========\033[0m" << std::endl;
    boss.executeForm(pardon);

    std::cout << "\n\033[32m========== BOUNDARY EXECUTE TEST ==========\033[0m" << std::endl;
    try
    {
        Bureaucrat execExact("ExecExact", 5);
        PresidentialPardonForm exactExec("Ford Prefect");
        execExact.signForm(exactExec);
        execExact.executeForm(exactExec);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
