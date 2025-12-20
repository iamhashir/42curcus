#include <iostream>

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try
    {
        std::cout << "\033[32m=================CREATE BUREAUCRATS=================\033[0m" << std::endl;

        Bureaucrat boss("Boss", 1);
        Bureaucrat mid("Mid", 50);
        Bureaucrat low("Low", 150);

        std::cout << boss << std::endl;
        std::cout << mid << std::endl;
        std::cout << low << std::endl;

        std::cout << "\033[32m=================CREATE FORMS=================\033[0m" << std::endl;

        ShrubberyCreationForm shrub("home");
        RobotomyRequestForm robot("Bender");
        PresidentialPardonForm pardon("Arthur Dent");

        std::cout << shrub << std::endl;
        std::cout << robot << std::endl;
        std::cout << pardon << std::endl;

        std::cout << "\033[32m===========EXECUTE UNSIGNED FORMS===========\033[0m" << std::endl;

        low.executeForm(shrub);
        mid.executeForm(robot);
        boss.executeForm(pardon);

        std::cout << "\033[32m=================SIGN FORMS=================\033[0m" << std::endl;

        low.signForm(shrub);
        mid.signForm(shrub);
        mid.signForm(robot);
        mid.signForm(pardon);
        boss.signForm(pardon);

        std::cout << "\033[34m===========EXECUTE SHRUBBERY===========\033[0m" << std::endl;

        mid.executeForm(shrub);


        std::cout << "\033[35m===========EXECUTE ROBOTOMY===========\033[0m" << std::endl;

        boss.executeForm(robot);
        boss.executeForm(robot);
        boss.executeForm(robot);

        std::cout << "\033[36m=======EXECUTE PRESIDENTIAL PARDON=======\033[0m" << std::endl;

        boss.executeForm(pardon);

        std::cout << "\033[32m========================================\033[0m" << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}

