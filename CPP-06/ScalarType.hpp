#ifndef SCALARTYPE_HPP
#define SCALARTYPE_HPP
#include <iostream>
#include <sstream>
#include <cmath>
#include <limits>
#include <ctype.h>

#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define OFF "\033[0m"

class Conversion
{
    public:
            std::string     GetStr();
            Conversion(char *av);
            int         TypeNumber(std::string nb);
            bool        CheckType();
            void        FromInt();
            void        FromFloat();
            void        FromChar();
            void        FromDouble();
            bool        FromScience();
            std::string GetArrayStr(int i);
    private:
            float       f;
            double      d;
            char        c;
            int         i;
            long long   i_tmp;
            std::string str;
            std::stringstream array[4];
};

std::ostream    & operator<<(std::ostream &out,Conversion & obj);

#endif