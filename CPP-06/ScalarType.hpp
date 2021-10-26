#ifndef SCALARTYPE_HPP
#define SCALARTYPE_HPP
#include <iostream>
#include <math.h>

#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define OFF "\033[0m"

class ScalarType
{
    public:
            ScalarType(std::string string);
            int    CheckScience();
            int    CheckChar();
            std::string GetInt();
            std::string GetDouble();
            std::string GetFloat();
            std::string GetChar();
    private:
            std::string str;
            std::string interger;
            std::string floater;
            std::string dou;
            std::string character;
};

std::ostream & operator<< (std::ostream &out, ScalarType &s);

#endif