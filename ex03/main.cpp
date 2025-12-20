#include <iostream>

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"

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

        std::cout << "\033[32m=================INTERN CREATES FORMS=================\033[0m" << std::endl;

        Intern intern;

        AForm *shrub = intern.makeForm("shrubbery creation", "home");
        AForm *robot = intern.makeForm("robotomy request", "Bender");
        AForm *pardon = intern.makeForm("presidential pardon", "Arthur Dent");
        AForm *shrub1 = intern.makeForm("presidential pardon", "Arthur Dent");

        std::cout << "\033[32m===========EXECUTE UNSIGNED FORMS===========\033[0m" << std::endl;

        low.executeForm(*shrub);
        mid.executeForm(*robot);
        boss.executeForm(*pardon);

        std::cout << "\033[32m=================SIGN FORMS=================\033[0m" << std::endl;

        low.signForm(*shrub);
        mid.signForm(*shrub);
        mid.signForm(*robot);
        mid.signForm(*pardon);
        boss.signForm(*pardon);

        std::cout << "\033[34m===========EXECUTE SHRUBBERY===========\033[0m" << std::endl;

        mid.executeForm(*shrub);
        boss.executeForm(*shrub1);

        std::cout << "\033[35m===========EXECUTE ROBOTOMY===========\033[0m" << std::endl;

        mid.executeForm(*robot);
        boss.executeForm(*robot);
        boss.executeForm(*robot);
        boss.executeForm(*robot);

        std::cout << "\033[36m=======EXECUTE PRESIDENTIAL PARDON=======\033[0m" << std::endl;

        boss.executeForm(*pardon);

        std::cout << "\033[32m========================================\033[0m" << std::endl;

        delete shrub;
        delete robot;
        delete pardon;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
