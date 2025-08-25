#include "Harl.hpp"

Harl::Harl() {}
Harl::~Harl() {}

void    Harl::debug(void)
{
    std::cout << "[DEBUG]\n"
              << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger."
              << "\nI really do!" << std::endl;
}

void    Harl::info(void)
{
    std::cout << "[INFO]\n"
              << "I cannot believe adding extra bacon costs more money."
              << "\nYou didn’t put enough bacon in my burger!"
              << "\nIf you did, I wouldn’t be asking for more!" << std::endl;
}

void    Harl::warning(void)
{
    std::cout << "[WARNING]\n"
              << "I think I deserve to have some extra bacon for free."
              << "\nI’ve been coming for years whereas you started working here just last month."
              << std::endl;
}

void    Harl::error(void)
{
    std::cout << "[ERROR]\n"
              << "This is unacceptable! I want to speak to the manager now."
              << std::endl;
}

void    Harl::complain(std::string level)
{
    void    (Harl::*functionPTRS[])(void) = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };
    std::string complains[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    for (int i = 0; i < 4; i++)
    {
        if (complains[i] == level)
        {
            (this->*functionPTRS[i])();
            return ;
        }
    }
}
