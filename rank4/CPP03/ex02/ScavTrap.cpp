#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap()
: ClapTrap() {
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap: Default constructor called\n";
}

ScavTrap::ScavTrap(const std::string& name)
: ClapTrap(name) {
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap: Parametrized constructor called\n";
}

ScavTrap::ScavTrap(const ScavTrap& other)
: ClapTrap(other) {
    std::cout << "ScavTrap: Copy constructor called\n";
    *this = other;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    std::cout << "ScavTrap: Copy assignment operator called\n";
    if (this != &other) {
        _name = other._name;
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
    }
    return *this;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap: Destructor called\n";
}

void ScavTrap::attack(const std::string& target) {
    if (_hitPoints <= 0) {
        std::cout << "ScavTrap " << _name << " can’t attack — it’s dead.\n";
        return;
    }
    if (_energyPoints <= 0) {
        std::cout << "ScavTrap " << _name << " has no energy to attack.\n";
        return;
    }
    --_energyPoints;
    std::cout << "ScavTrap " << _name << " lunges at " << target
              << ", dealing " << _attackDamage << " damage!\n";
}

void ScavTrap::guardGate() {
    if (_hitPoints <= 0) {
        std::cout << "ScavTrap " << _name << " can’t enter Gate keeper mode — it’s dead.\n";
        return;
    }
    std::cout << "ScavTrap " << _name << " is now in Gate keeper mode.\n";
}
