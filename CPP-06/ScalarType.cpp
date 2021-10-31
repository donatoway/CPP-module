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

    if (i_tmp < INT_MIN || i_tmp > INT_MAX)
    {
        this->array[1] << "overflow";
        if (i_tmp <= 999999)
            this->array[2] << static_cast<float>(i_tmp) << ".0f";
        else
            this->array[2] << static_cast<float>(i_tmp) << "f";
        if (i_tmp <= 9999999)
            this->array[3] << static_cast<double>(i_tmp) << ".0";
        else
            this->array[3] << static_cast<double>(i_tmp);
    }
    else
    {
        this->array[1] << i;
        if (i_tmp <= 999999)
            this->array[2] << static_cast<float>(i) << ".0f";
        else
            this->array[2] << static_cast<float>(i) << "f";
        if (i_tmp <=  999999)
            this->array[3] << static_cast<double>(i) << ".0";
        else
            this->array[3] << static_cast<double>(i);
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
    if (str[n + 1] == '0' && str[n + 2] == 'f' )
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
    switch (TypeNumber(str))
    {
        case 1 : FromFloat();
        break;
        case 2 : FromInt();
        break;
        case 3 : FromDouble();
        break;
        //case 5 : If Science
        case -1 :
        if (str.length() == 1 && str[0] >= 0 && str[0] <= 127)
            FromChar();
        else
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