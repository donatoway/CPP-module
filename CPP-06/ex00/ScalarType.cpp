#include "ScalarType.hpp"
#include <string.h>

Conversion::Conversion(char *av)
{
    this->str = str.append(av);
    this->i_tmp = atof(str.c_str());
}

 std::string     Conversion::GetStr()
 {
     return (this->str);
 }

bool    Conversion::FromScience()
{
    if (str == "nan" || str == "nanf")
    {
        this->array[0] << "Impossible";
        this->array[1] << "Impossible";
        this->array[2] << static_cast<float>(nanf("nanf")) << "f";
        this->array[3] << static_cast<double>(nan("nan"));
        return (true);
    }
    if (str == "+inf" || str == "+inff")
    {
        this->array[0] << "Impossible";
        this->array[1] << "Impossible";
        this->array[2] << "+inff";
        this->array[3] << "+inf";
        return (true);
    }
    if (str == "-inf" || str == "-inff")
    {
        this->array[0] << "Impossible";
        this->array[1] << "Impossible";
        this->array[2] << "-inff";
        this->array[3] << "-inf";
        return (true);
    }
    return false;
}
 
int    Conversion::TypeNumber(std::string nb)
{
    size_t i = 0;
    int points = 0;
    if (nb[i] == '-' || nb[i] == '+' || nb[i] == '.')
    {
        if (nb[i] == '.')points++;
        i++;
    }
    if (nb[i] == '\0')
        return (-1);
    while (nb[i])
    {
        if (std::isdigit(nb[i]))
            i++;
        else
        {
            if (nb[i] == '.')i++,points++;
            if (nb[i] == '.' && points > 1)
                return -1;
            if (nb[i] == 'f' && (i  == nb.length() - 1) && points == 1)
            {
                this->f = atof(nb.c_str());
                return (1);
            }
            if ((nb[i] != '.' && !std::isdigit(nb[i])) || ( points > 1))
                return (-1);
        }
    }

    if (points == 0)
    {
        this->i = atoi(nb.c_str());
        return (2);
    }
    else
    { 
        this->d = atof(nb.c_str());
        return (3);
    }
    return (-1);
}

void     Conversion::FromInt()
{
    if (i_tmp >= 0 && i_tmp <= 128)
    {
        if (i_tmp > 32 && i_tmp < 127)
            array[0] << static_cast<char>(i);
        else
            array[0] << "Not-Displayble";
    }
    else
        array[0] << "Impossible";

    if (i_tmp >= INT_MIN && i_tmp <= INT_MAX)
    {
        this->array[1] << i;
        if (abs(i_tmp) >= 1000000)
        {

            this->array[2] << static_cast<float>(i) << "f";
            this->array[3] << static_cast<double>(i);
        }
        else
        {
            this->array[2] << static_cast<float>(i) << ".0f";
            this->array[3] << static_cast<double>(i) << ".0";
        }
    }
    else
    {
        this->array[1] << "overflow";
        this->f = atof(str.c_str());
        this->array[2] << f << "f";
        this->array[3] << static_cast<double>(f);
    }
}

void       Conversion::FromFloat()
{
    int n;
    if (f >= 0 && f <= 128)
    {
        if (f > 32 && f < 127)
        {
            c = static_cast<char>(f);
            array[0] << c;
        }
        else
            array[0] << "Not-Displayble";
    }
    else
        array[0] << "Impossible";
    if (f > INT_MAX || f < INT_MIN)
        array[1] << "overflow";
    else
        array[1] << static_cast<int>(f);
    n = str.find(".");
    if ((str[n + 1] == '0' && str[n + 2] == 'f' ) || str[n + 1] == 'f')
    {
        array[2] << f << ".0f";
        array[3] << static_cast<double>(f) << ".0";
    }
    else
    {
        array[2] << f << "f";
        array[3] << static_cast<double>(f);
    }
}

void      Conversion::FromDouble()
{
    int n;
    if (i_tmp >= 0 && i_tmp <= 127)
    {
        if (i_tmp > 32 && i_tmp < 127)
            array[0] << static_cast<char>(d);
        else
            array[0] << "Not-Displayble";
    }
    else
        array[0] << "Impossible";

    if (i_tmp > INT_MAX || i_tmp < INT_MIN)
        array[1] << "overflow";
    else
        array[1] << static_cast<int>(d);
    n = str.find(".");
    if (str[n + 1] == '0' && str[n + 2] == '\0')
    {
        array[2] << static_cast<float>(d) << ".0f";
        array[3] << d << ".0";
    }
    else
    {
        array[2] << static_cast<float>(d) << "f";
        array[3] << d;
    }
}

void    Conversion::FromChar()
{
    c = str[0];
    if (c >= 0 && c <= 127)
    {
        if (c > 32 && c < 127)
            array[0] << c;
        else
            array[0] << "Not-Displayble";
    }
    else
        array[0] << "Impossible";
    array[1] << static_cast<int>(c);
    array[2] << static_cast<float>(c) << ".0f";
    array[3] << static_cast<double>(c) << ".0";
}

std::string Conversion::GetArrayStr(int i)
{
    std::string s;

    array[i] >> s;
    return (s);
}

std::ostream    & operator<<(std::ostream &out, Conversion & obj)
{
    std::string s;
    std::string color = GREEN;
    for (size_t i = 0; i < 4; i++)
    {
        color = GREEN;
        switch (i)
        {
            case 0: s = obj.GetArrayStr(0);
            if (s == ("Not-Displayble") || s == ("Impossible") )
                color = RED;
            std::cout  << "Char : " << color << s << OFF<<"\n";
            break;
            case 1: s = obj.GetArrayStr(1);
            if (s == ("Impossible") || s == "overflow")
                color = RED;
            std::cout << "Int  : " <<color << s << OFF<<"\n";
            break;
            case 2:s = obj.GetArrayStr(2);
            if (s == ("Impossible"))
                color = RED;
            std::cout << "Float : " << color << s<<  OFF"\n";
            break;
            case 3 :s = obj.GetArrayStr(3);
            if (s == ("Impossible"))
                color = RED;
            std::cout << "Double : "<< color << s << OFF"\n";
            break;
        default:
            break;
        }
    }
    return (out);
}

 bool           Conversion::CheckType()
 {
    switch (TypeNumber(str))    // Find the type of the input
    {
        //Convert to Other type from type input
        case 1 : FromFloat();
        break;
        case 2 : FromInt();
        break;
        case 3 : FromDouble();
        break;
        case -1 : //If type is not a number can be a char, infinity num or NAN
        if (str.length() == 1 && str[0] >= 33 && str[0] <= 126)
            FromChar();
        else if (FromScience() == true)
            break;
        else    // If not a valid arg BYE BYE
        {
            std::cout << "Not A valid Argument\n";
            return (false);
        }
        break;
        default:
        break;
    }
    return (true);
 }