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
        std::cout << "Assignation Operator Called" << std::endl;
        this->FixedValue = OldObj.getRawBits();
        return (*this);
}

Fixed::Fixed()
{
        FixedValue = 0;
        std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
        std::cout << "Destructor Called " << std::endl;
}

Fixed::Fixed(const Fixed& OldObj)
{
        std::cout << "Copy constructor Called" << std::endl;
        *this = OldObj;
}

//-----------------------New Functions-------------------------

Fixed::Fixed(const int integer)
{
    std::cout << "Int Constructor Called" << std::endl;
    this->FixedValue = integer << this->BitFractional;
}

Fixed::Fixed(const float number)
{
    std::cout << "Float Constructor Called" << std::endl;
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