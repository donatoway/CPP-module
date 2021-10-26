#include "ScalarType.hpp"
#include <string.h>
#include <sstream>

std::ostream & operator<< (std::ostream &out, ScalarType &s)
{
    std::string color;
    if (s.GetChar() == "Impossible") color = RED;else color = GREEN;
    std::cout << "Char   : " << color <<  s.GetChar() << OFF <<  std::endl;
    if (s.GetInt() == "Impossible") color = RED;else color = GREEN;
    std::cout << "Int    : " << color <<  s.GetInt() << OFF <<  std::endl;
    if (s.GetFloat() == "Impossible") color = RED;else color = GREEN;
    std::cout << "Float  : " << color <<  s.GetFloat() << OFF << std::endl;
    if (s.GetDouble() == "Impossible") color = RED;else color = GREEN;
    std::cout << "Double : " << color <<  s.GetDouble() << OFF << std::endl;
    return (out);
}

ScalarType::ScalarType(std::string string):str(string){};

int    ScalarType::CheckScience()
{
    if (!str.compare("-inff") || !str.compare("-inf")\
        || !str.compare("nanf") || !str.compare("+inff")\
        || !str.compare("nan") || !str.compare("+inf"))
    {
        this->character = "Impossible";
        this->interger = "Impossible";
        if (!str.compare("-inff") || !str.compare("-inf"))
            this->floater = "-inff",this->dou = "-inf";
        if (!str.compare("+inf") || !str.compare("+inff"))
            this->floater = "+inff",this->dou = "+inf";
        if (!str.compare("nanf") || !str.compare("nan"))
            this->floater = "nanf",this->dou = "nan";
    }
    return (1);
}

int    ScalarType::CheckChar()
{
    char c;
    if (this->str.length() == 1)
    {
        c = str[0];
        if (c > 28 && (c < '0' || c > '9'))
        {
           

                std::ostringstream temp;
                int n = c;
                temp << n;


           // std::cout <<  << "\n";
            this->interger = temp.str();
            this->character = str;
            this->floater = str;
            this->dou = str;
        }
    }
    return (2);
}

std::string ScalarType::GetInt()
{
    return (this->interger);
}

std::string ScalarType:: GetDouble()
{
    return (this->dou);
}

std::string ScalarType::GetFloat()
{
    return (this->floater);
};

std::string ScalarType::GetChar()
{
    return (this->character);
}