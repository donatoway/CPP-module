#include "Fixed.hpp"

/*  ESERCIZIO
Aggiungi le seguenti public member function operator overload alla tua classe:
- 6 comparazioni operators: >,<,>=,<=,== e !=
- 4 arithmetic operator: +, -, *, and /
- il pre-incremento, dopo-incremento, predecremento, dopo-decremento, incrementeranno o decrementeranno 
    il fixed point value dalla più piccola unità rappresentbile  ε such as 1 + ε > 1 
- Aggiungi le seguenti public static member functions oveloads alla tua classe:
    -   la static member function min che prende referenze di 2 fixed point value e ritorna una referenza al valore piu piccolo,
        e un'overload che prende referenze di 2 costanti fixed point value e ritorna una referenza alla costante con il valore minore
    -   la static member function max che prende referenzedi 2 fixed point valuee ritorna una referenza al valore più grande,
        un overload che prende u    na referenza di 2 costanti fixed point values e ritorna una referenza alla costante con il valore maggiore


*/
        //Nel caso Delle comparazioni e delle operazioni aritmetiche + e -
        //possiamo svolgere le operazioni tra FixedValue in quanto sono sullo
        //stesso livello, per gli altri dobbiamo spostare i bit per avere 
        //un risultato corretto
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

//creare il pre-incremento
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

void    ComparisonTest(Fixed a, Fixed b)
{
    bool res;

            // ------- Minor Test -------------
    std::cout << "------- Minor Test -------------" << std::endl;
    res = a < b;                // if a less than b return 1 else 0
    if (res == 1)
        std::cout << "[res: " << res << " ]" << a << " less than " << b << std::endl;
            //------- Greater Test ------------
    std::cout << "------- Greater Test -------------" << std::endl;
    res = b > a;                // if b greater than a return 1 else 0
    if (res == 1)
        std::cout << "[res: " << res << " ]" << b <<  " greater than " << a << std::endl;
            //------- Greater-equal Test ------------
    std::cout << "------- Greater-equal Test -------------" << std::endl;
    res = b >= a;                // if b greater-equal than a return 1 else 0
    if (res == 1)
        std::cout << "[res: " << res << " ]" << b <<  " greater-equal than " << a << std::endl;
            //------- less-equal Test ------------
    std::cout << "------- less-equal Test -------------" << std::endl;
    res = a <= b;                // if b less-equal than a return 1 else 0
    if (res == 1)
        std::cout << "[res: " << res << " ]" << a <<  " less-equal than " << b << std::endl;
            //------- equal Test ------------
    std::cout << "------- equal Test -------------" << std::endl;
    a = b;
    res = a == b;               // if b equal a return 1 else 0
    if (res == 1)
        std::cout << "[res: " << res << " ]" << a <<  " equal " << b << std::endl;
            //------- not equal Test ------------
    std::cout << "------- not-equal Test -------------" << std::endl;
    a = 21;
    b = 42;
    std::cout << "a changed in a=21 and b=42 again" <<std::endl;
    res = a != b;               // if b not equal a return 1 else 0
    if (res == 1)
        std::cout << "[res: " << res << " ]" << a <<  " not equal " << b << std::endl;
}

void    aritmeticTest(Fixed a, Fixed b, Fixed c)
{
    Fixed res;

    res = a + b + c;
    //------- + Test -------------
    std::cout << "------- + Test -------------" << std::endl;
    std::cout << a << " + " << b << " + " << c << " = res" << res << std::endl;
    //------- - Test -------------
    std::cout << "------- - Test -------------" << std::endl;
    std::cout <<"res"<< res << " - " << a << " - " << c << " = res";
    res = res - a - c;
    std::cout << res << std::endl;
    //------- +- Combined-Test -------------
    std::cout << "------- +- Combined-Test -------------" << std::endl;
    std::cout << "res" << res << " + " << a << " + " \
    << b << " - " << c << " - " << a << " = ";;
    res = res + a + b - c - a;
    std::cout << res << std::endl;
     //------- * Test -------------
    std::cout << "------- * Test -------------" << std::endl;
    std::cout << "a = " << a << std::endl;
    a = a * 5;
    std::cout << "a * 5 = " << a << std::endl;
     //------- / Test -------------
    std::cout << "------- / Test -------------" << std::endl;
    std::cout << "a = " << a << std::endl;
    a = a / 5;
    std::cout << "a / 5 = " << a << std::endl; 

     //------- +- Float-Test -------------
    std::cout << "------- +- Float-Test -------------" << std::endl;
    a = 10.8977f,b = Fixed(20.4567f);
    std::cout << "a now is :" << a << ", b now is :"\
     << b <<std::endl;
    std::cout << "a + b = " <<  a + b << std::endl;
}

int    Tester()
{
    std::string cmd;
    std::cout << "Do you want Test whit My Test-Function? y/n" << std::endl;
    std::cin >> cmd;
    if (cmd.compare("y") == 0)
    {
        ComparisonTest(21, 42);
        aritmeticTest(10, 20, 30);
    }
    std::cout << "Do you want Test Subject? y/n" << std::endl;
    std::cin >> cmd;
    if (cmd.compare("n") == 0)
        return (1);
    return (0);
}

int main()
{
    if (Tester() == 1) return (0);
    Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
 	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl; 
	//std::cout << Fixed::max( a, b ) << std::endl;
	
	return 0; 

}