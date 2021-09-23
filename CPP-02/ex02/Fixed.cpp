#include "Fixed.hpp"

void Fixed::setRawBits( int const raw )
{
        this->FixedValue = raw;
}

int Fixed::getRawBits( void ) const
{
        return this->FixedValue;
}

Fixed&   Fixed::operator = (const Fixed &OldObj)
{
        this->FixedValue = OldObj.getRawBits();
        return (*this);
}

Fixed::Fixed()
{
        FixedValue = 0;
}

Fixed::~Fixed()
{
}

Fixed::Fixed(const Fixed& OldObj)
{
        *this = OldObj;
}

Fixed::Fixed(const int integer)
{
    this->FixedValue = integer << this->BitFractional;
}

Fixed::Fixed(const float number)
{
    this->FixedValue = roundf(number * (1 << this->BitFractional));
}

int Fixed::toInt( void ) const
{
    return  (this->FixedValue / (1 << this->BitFractional));
}

float Fixed::toFloat(void)const
{
    return (float(FixedValue) / (1 << this->BitFractional));
}

std::ostream&   operator << (std::ostream& stream, const Fixed& obj)
{
        return (stream << obj.toFloat());
}