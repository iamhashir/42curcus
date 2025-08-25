#include <iostream>
#include "Fixed.hpp"

Fixed::Fixed() : _fp_value(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called" << std::endl;
    std::cout << "Copy assignment operator called" << std::endl;  // Add this line
    this->_fp_value = other.getRawBits();  // This will print getRawBits message
}

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->_fp_value = other.getRawBits();  // This will print getRawBits message
    }
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return _fp_value;
}

void Fixed::setRawBits(int const raw) {
    _fp_value = raw;
}
