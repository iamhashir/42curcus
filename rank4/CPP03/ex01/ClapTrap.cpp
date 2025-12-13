#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap()
	: _name(""), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Default constructor called\n";
}

ClapTrap::ClapTrap(const std::string &name)
	: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Parametrized constructor called\n";
}

ClapTrap::ClapTrap(const ClapTrap& other)
: _name(other._name),
  _hitPoints(other._hitPoints),
  _energyPoints(other._energyPoints),
  _attackDamage(other._attackDamage)
{
    std::cout << "Copy constructor called\n";
}


ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "Copy assignment operator called\n";
	if (this != &other)
	{
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called\n";
}

void ClapTrap::setAttackDamage(int dmg)
{
	_attackDamage = (dmg < 0 ? 0 : dmg);
}

void ClapTrap::attack(const std::string &target)
{
	if (_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " can't attack (HP=0)\n";
		return;
	}
	if (_energyPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " has no energy\n";
		return;
	}
	--_energyPoints;
	std::cout << "ClapTrap " << _name << " attacks " << target
			  << ", causing " << _attackDamage << " points of damage! (EP=" << _energyPoints << ")\n";
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " already down\n";
		return;
	}
	int dmg = (amount > static_cast<unsigned int>(_hitPoints)) ? _hitPoints : static_cast<int>(amount);
	_hitPoints -= dmg;
	std::cout << "ClapTrap " << _name << " takes " << dmg << " points of damage (HP=" << _hitPoints << ")\n";
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " can't repair (HP=0)\n";
		return;
	}
	if (_energyPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " has no energy\n";
		return;
	}
	--_energyPoints;
	_hitPoints += static_cast<int>(amount);  
	std::cout << "ClapTrap " << _name << " repairs " << amount
			  << " (HP=" << _hitPoints << ", EP=" << _energyPoints << ")\n";
}
