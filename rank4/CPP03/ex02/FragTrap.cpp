#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap()
: ClapTrap() {
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap: Default constructor called\n";
}

FragTrap::FragTrap(const std::string& name)
: ClapTrap(name) {
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap: Parametrized constructor called\n";
}

FragTrap::FragTrap(const FragTrap& other)
: ClapTrap(other) {
    std::cout << "FragTrap: Copy constructor called\n";
    *this = other;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
    std::cout << "FragTrap: Copy assignment operator called\n";
    if (this != &other) {
        _name = other._name;
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
    }
    return *this;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap: Destructor called\n";
}

void FragTrap::highFivesGuys() {
    if (_hitPoints <= 0) {
        std::cout << "FragTrap " << _name << " can’t request high fives — it’s dead.\n";
        return;
    }
    std::cout << "FragTrap " << _name << " requests positive high fives!\n";
}

void FragTrap::attack(const std::string& target) {
    if (_hitPoints <= 0) {
        std::cout << "FragTrap " << _name << " can’t attack — it’s dead.\n";
        return;
    }
    if (_energyPoints <= 0) {
        std::cout << "FragTrap " << _name << " has no energy to attack.\n";
        return;
    }
    --_energyPoints;
    std::cout << "FragTrap " << _name << " blasts " << target
              << ", dealing " << _attackDamage << " damage!\n";
}
