#include "ScavTrap.hpp"

int main()
{
	ScavTrap warrior("1337");
	ScavTrap copyBot(warrior);
	ScavTrap assignBot("temp");

	assignBot = warrior;

	warrior.attack("target");
	warrior.takeDamage(30);
	warrior.beRepaired(20);
	warrior.guardGate();

	copyBot.takeDamage(150);
	copyBot.attack("dummy");
	copyBot.beRepaired(50);
	copyBot.guardGate();

	for (int i = 0; i < 5; ++i)
	{
		assignBot.attack("practice-dummy");
		assignBot.beRepaired(5);
	}

	return 0;
}