#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
#include <cmath>

class Fixed
{
        public:
                Fixed();
                Fixed(const Fixed &OldObj);
                ~Fixed();
                Fixed& operator = (const Fixed &OldObj);
                int getRawBits( void ) const;
                void setRawBits( int const raw );
        private:
                int FixedValue;
                static const int BitFractional = 8;

};

#endif