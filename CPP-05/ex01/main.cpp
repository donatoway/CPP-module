#include <iostream>
#include "Bureaucrat.hpp"

#define GREEN "\e[1;32m"
#define HRED "\e[0;91m"
#define YELLOW "\e[4;33m"
#define OFF "\e[0m"

int main()
{
    Form Module7("Module7",70,70);
    // TEST VALID CONSTRUCTOR FORM WHIT PRINT STATUS
    try
    {
        Form Module1("Module1",10,50);
        std::cout << Module1;

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    // TEST INVALID FORM CONSTRUCTOR LOW
    std::cout << "\n";
    try
    {
        Form Module2("module2",151,10);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "\n";
    // TEST INVALID FORM CONSTRUCTOR HIGH
    try
    {
        Form Module3("Module3",66,0);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "\n";
    // TEST SIGN SUCCESFUL
    try
    {
        Bureaucrat Luiss("Luiss",50);
        Form Module4("Module4",100,100);
        std::cout << YELLOW << "Module before Luiss Sign it:\n";
        std::cout << Module4;
        std::cout << "\n";
        Luiss.signForm(Module4);
        std::cout << YELLOW << "Module After Luiss Signed it\n";
        std::cout << Module4;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "\n";
    // TEST SIGN INSUCCESFUL
    try
    {
        Bureaucrat George("George",140);
        Form Module5("Module5",100,100);
        std::cout << Module5;
        George.signForm(Module5);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "\n";
    //TEST MULTIPLE SIGN ON MODULE 7
    try
    {
        Bureaucrat A("A",50);
        Bureaucrat B("B",11);
        Bureaucrat C("C",99);
        A.signForm(Module7);
        B.signForm(Module7);
        C.signForm(Module7);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout  << Module7;
}