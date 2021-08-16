#include <iostream>

/*
** POINTER VS REFERENCE
**
** reference has same address as string and cannot be reassigned, cannot be null
** pointer has different address because they are variable that store adresses
** and can be reassigned anytime, can be null
*/

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;

    std::cout << "POINTER: address " << stringPTR << " ->";
    std::cout << *stringPTR << std::endl;
    std::cout << "REFERENCE: address " << &stringREF << " ->";
    std::cout << stringREF << std::endl;
}