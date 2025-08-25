#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
#include <cmath>

class Fixed {
private:
    int                 _value;
    static const int    _fractBits = 8;

public:
    Fixed();
    Fixed(const Fixed &other);
    Fixed &operator=(const Fixed &other);
    ~Fixed();

    Fixed(const int n);
    Fixed(const float f);

    int     getRawBits(void) const;
    void    setRawBits(int const raw);
    float   toFloat(void) const;
    int     toInt(void) const;
};

std::ostream &operator<<(std::ostream &os, const Fixed &f);

#endif

 