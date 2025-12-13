#include "Animal.hpp"

Animal::Animal() : _type("") {
    std::cout << "Animal: Default constructor called" << std::endl;
}

Animal::Animal(std::string const &type) : _type(type) {
    std::cout << "Animal: Parameterized constructor called" << std::endl;
}

Animal::Animal(const Animal &other) : _type(other._type) {
    std::cout << "Animal: Copy constructor called" << std::endl;
}

Animal::~Animal() {
    std::cout << "Animal: Destructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &other) {
    std::cout << "Animal: Assignment operator called" << std::endl;
    if (this != &other)
        _type = other._type;
    return *this;
}

void Animal::makeSound() const {
    std::cout << "Unknown sound" << std::endl;
}

std::string Animal::getType() const {
    return _type;
}
