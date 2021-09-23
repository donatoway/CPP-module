#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
#include <math.h>

class Fixed
{
        public:
                Fixed();
                Fixed(const Fixed &OldObj);
                Fixed(const int integer);
                Fixed(const float number);
                ~Fixed();
                int     getRawBits( void ) const;
                void    setRawBits( int const raw );
                float   toFloat(void) const;
                int     toInt( void ) const;
                Fixed&  operator = (const Fixed &OldObj);
                bool    operator < (const Fixed &Obj)const;
                bool    operator > (const Fixed &Obj)const;
                bool    operator >= (const Fixed &obj)const;
                bool    operator <= (const Fixed &obj)const;
                bool    operator == (const Fixed &obj)const;
                bool    operator != (const Fixed &obj)const;
                Fixed  operator + (const Fixed &obj)const;
                Fixed  operator - (const Fixed &obj)const;
                Fixed  operator * (const Fixed &obj)const;
                Fixed  operator / (const Fixed &obj)const;
                Fixed& operator ++ ();
                Fixed operator ++ (int);
                Fixed& operator -- ();
                Fixed operator -- (int);

        private:
                int FixedValue;
                static const int BitFractional = 8;

};

std::ostream&   operator << (std::ostream& stream, const Fixed& obj);

#endif