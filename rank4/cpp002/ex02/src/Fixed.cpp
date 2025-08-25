#include "Fixed.hpp"
#include <cmath>
#include <iostream>

Fixed::Fixed() : _value(0)
{
}

Fixed::Fixed(const Fixed &other)
{
    *this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    if (this != &other)
    {
        _value = other._value;
    }
    return *this;
}

Fixed::~Fixed()
{
}

Fixed::Fixed(const int n)
{
    _value = n << _fractBits;
}

Fixed::Fixed(const float f)
{
    _value = static_cast<int>(roundf(f * (1 << _fractBits)));
}

int Fixed::getRawBits(void) const
{
    return _value;
}

void Fixed::setRawBits(int const raw)
{
    _value = raw;
}

float Fixed::toFloat(void) const
{
    return static_cast<float>(_value) / (1 << _fractBits);
}

int Fixed::toInt(void) const
{
    return _value >> _fractBits;
}

bool Fixed::operator>(const Fixed &rhs) const
{
    return _value > rhs._value;
}

bool Fixed::operator<(const Fixed &rhs) const
{
    return _value < rhs._value;
}

bool Fixed::operator>=(const Fixed &rhs) const
{
    return _value >= rhs._value;
}

bool Fixed::operator<=(const Fixed &rhs) const
{
    return _value <= rhs._value;
}

bool Fixed::operator==(const Fixed &rhs) const
{
    return _value == rhs._value;
}

bool Fixed::operator!=(const Fixed &rhs) const
{
    return _value != rhs._value;
}

Fixed Fixed::operator+(const Fixed &rhs) const
{
    Fixed r;
    r._value = _value + rhs._value;
    return r;
}

Fixed Fixed::operator-(const Fixed &rhs) const
{
    Fixed r;
    r._value = _value - rhs._value;
    return r;
}

Fixed Fixed::operator*(const Fixed &rhs) const
{
    Fixed r;
    long long p = static_cast<long long>(_value) * static_cast<long long>(rhs._value);
    r._value = static_cast<int>(p >> _fractBits);
    return r;
}

Fixed Fixed::operator/(const Fixed &rhs) const
{
    Fixed r;

    if (rhs._value == 0)
    {
        std::cerr << "Division by zero!" << std::endl;
        r._value = 0;
    }
    else
    {
        long long n = static_cast<long long>(_value) << _fractBits;
        r._value = static_cast<int>(n / rhs._value);
    }
    return r;
}

Fixed &Fixed::operator++()
{
    ++_value;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed t(*this);
    ++(*this);
    return t;
}

Fixed &Fixed::operator--()
{
    --_value;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed t(*this);
    --(*this);
    return t;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    return (a < b ? a : b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    return (a < b ? a : b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    return (a > b ? a : b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    return (a > b ? a : b);
}

std::ostream &operator<<(std::ostream &os, const Fixed &f)
{
    os << f.toFloat();
    return os;
}
