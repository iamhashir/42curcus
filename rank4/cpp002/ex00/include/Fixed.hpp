#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>

class Fixed {
private:
    int _fp_value;
    static const int _fract_bits = 8;

public:
    Fixed();
    Fixed(const Fixed& other);
    Fixed& operator=(const Fixed& other);
    ~Fixed();

    int  getRawBits(void) const;
    void setRawBits(int const raw);
};

#endif
