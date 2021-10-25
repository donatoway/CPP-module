#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    //TEST SUCCESFULL ShrubberyCreationForm
    try
    {
        Bureaucrat mimmo("mimmo",5);
        ShrubberyCreationForm B("B");
        mimmo.signForm(B);
        mimmo.executeForm(B);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "\n";
    // UNSUCCESFULL GRADE_EXECUTE TO LOW ShrubberyCreationForm
    try
    {
        Bureaucrat Vincent("Vincent",138);
        ShrubberyCreationForm B("B");

        Vincent.signForm(B);
        Vincent.executeForm(B);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "\n";
    //UNSUCCESFULL GRADE_SIGN TO LOW ShrubberyCreationForm
    try
    {
        Bureaucrat Pippo("Pippo",150);
        ShrubberyCreationForm Home("Home");

        Pippo.signForm(Home);
        Pippo.executeForm(Home);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "\n";
    //TEST SUCCESFULL RobotMyRequestForm
    try
    {
        Bureaucrat mimmo("mimmo",5);
        RobotMyRequestForm B("B");
        mimmo.signForm(B);
        mimmo.executeForm(B);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "\n";
    // UNSUCCESFULL GRADE_EXECUTE TO LOW RobotMyRequestForm
    try
    {
        Bureaucrat Vincent("Vincent",50);
        RobotMyRequestForm B("B");

        Vincent.signForm(B);
        Vincent.executeForm(B);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "\n";
    //UNSUCCESFULL GRADE_SIGN TO LOW RobotMyRequestForm
    try
    {
        Bureaucrat Pippo("Pippo",80);
        RobotMyRequestForm Home("Home");

        Pippo.signForm(Home);
        Pippo.executeForm(Home);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "\n";
    //TEST SUCCESFULL PresidentialPardonForm
    try
    {
        Bureaucrat mimmo("mimmo",4);
        PresidentialPardonForm B("B");
        mimmo.signForm(B);
        mimmo.executeForm(B);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "\n";
    // UNSUCCESFULL GRADE_EXECUTE TO LOW PresidentialPardonForm
    try
    {
        Bureaucrat Vincent("Vincent",15);
        PresidentialPardonForm B("B");

        Vincent.signForm(B);
        Vincent.executeForm(B);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "\n";
    //UNSUCCESFULL GRADE_SIGN TO LOW PresidentialPardonForm
    try
    {
        Bureaucrat Pippo("Pippo",77);
        PresidentialPardonForm Home("Home");

        Pippo.signForm(Home);
        Pippo.executeForm(Home);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "\n";
    //TEST WIthOUT SIGN
    try
    {
        Bureaucrat Carl("Carl",4);
        PresidentialPardonForm Pres("Pres");

        Carl.executeForm(Pres);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "\n";
    //TEST FORM::execute FUNCTION 
    try
    {
        Bureaucrat jay("jay",7);
        RobotMyRequestForm A("A");

        A.beSigned(jay);
        A.execute(jay);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

}