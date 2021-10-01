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

//-------> New Functions of the exercises <---------------

bool    Fixed::operator <  (const Fixed &Obj)const
{
    return (this->FixedValue < Obj.FixedValue);
}

bool    Fixed::operator > (const Fixed &obj)const
{
    return (this->FixedValue > obj.FixedValue);
}

bool    Fixed::operator >= (const Fixed &obj)const
{
    return (this->FixedValue >= obj.FixedValue);
}

bool    Fixed::operator <= (const Fixed &obj)const
{
    return (this->FixedValue <= obj.FixedValue);
}

bool    Fixed::operator == (const Fixed &obj)const
{
    return (this->FixedValue == obj.FixedValue);
}

bool    Fixed::operator != (const Fixed &obj)const
{
    return (this->FixedValue != obj.FixedValue);
}

Fixed   Fixed::operator + (const Fixed &obj)const
{
    Fixed res;

    res.FixedValue = this->FixedValue + obj.getRawBits();
    return (res);
}

Fixed  Fixed::operator - (const Fixed &obj)const
{
    Fixed res;
    res.FixedValue = this->FixedValue - obj.getRawBits();  
    return (res);
}

Fixed  Fixed::operator * (const Fixed &obj)const
{
    Fixed res;
    res.FixedValue = this->FixedValue * obj.toFloat();
    return (res);
}

Fixed  Fixed::operator / (const Fixed &obj)const
{
    Fixed res;
    res.FixedValue = this->FixedValue / obj.toFloat();
    return (res);
}

Fixed&   Fixed::operator++()
{
   this->FixedValue++;
   return (*this);
}

Fixed   Fixed::operator ++ (int)
{
    Fixed tmp;

    tmp = *this;
    ++*this;
    return tmp;
}

Fixed&   Fixed::operator -- ()
{
    this->FixedValue--;
    return (*this);
}

Fixed   Fixed::operator -- (int)
{
    Fixed tmp;

    tmp = *this;
    --*this;
    return tmp;
}

const  Fixed& Fixed::min(const Fixed &value1, const Fixed &value2)
{
    if (value1.getRawBits() < value2.getRawBits())
        return (value1);
    else
        return (value2);
}

Fixed& Fixed::min(Fixed &value1, Fixed &value2)
{
    if (value1.getRawBits() < value2.getRawBits())
        return (value1);
    else
        return (value2);
}

const Fixed& Fixed::max(const Fixed &value1, const Fixed &value2)
{
    if (value1 > value2)
        return (value1);
    else
        return (value2);
}

Fixed& Fixed::max(Fixed &value1, Fixed &value2)
{
    if (value1 > value2)
        return (value1);
    else
        return (value2);
}