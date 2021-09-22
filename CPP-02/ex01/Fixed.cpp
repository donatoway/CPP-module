#include "Fixed.hpp"

void Fixed::setRawBits( int const raw )
{
        this->FixedValue = raw;
}
int Fixed::getRawBits( void ) const
{
        std::cout << "getRawBits member function called" << std::endl;
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
