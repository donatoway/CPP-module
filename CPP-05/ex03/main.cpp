#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
    //SUBJECT TEST
    Intern  someRandomIntern;
    Form*   rrf;
    rrf = someRandomIntern.makeForm("RobotMyRequestForm", "Bender");
    std::cout << "\n";
    // TEST INTERN WRONG FORM_NAME
    try
    {
        Form *A;
        A = someRandomIntern.makeForm("ABCDE","PARDON");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "\n";
    //TEST INTERN SUCCESFULL PRESIDENTIAL
    try
    {
        Bureaucrat mimmo("mimmo",5);
        Form *C;
        C = someRandomIntern.makeForm("PresidentialPardonForm","presidential");
        mimmo.signForm(*C);
        mimmo.executeForm(*C);
        std::cout << *C;

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "\n";
    //TEST  SHRUBBERY
    try
    {
        Bureaucrat Carl("Carl",1);
        Form *Z;

        Z = someRandomIntern.makeForm("ShrubberyCreationForm","SH");
        Carl.executeForm(*Z);    
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}