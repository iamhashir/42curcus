#include "ClapTrap.hpp"

int main()
{
	ClapTrap a("42");
	ClapTrap b("421");
	b = a;
	a.attack("212");
	a.takeDamage(5);
	a.beRepaired(10);
	b.attack("121");
	b.takeDamage(5);
	b.beRepaired(10);
	return 0;
}
