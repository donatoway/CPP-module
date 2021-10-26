#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm():Form("PresidentialPardonForm",25,5)
{
    this->target = "";
}

PresidentialPardonForm::~PresidentialPardonForm(){};

PresidentialPardonForm::PresidentialPardonForm(std::string str):Form("PresidentialPardonForm",25,5)
{
    this->target = str;
};

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &obj)
{
    this->target = obj.target;
    *this = obj;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &obj)
{
    this->target = obj.target;
    return (*this);
}

/*
PresidentialPardonForm (Required grades: sign 25, exec 5). 
Action: Tells us <target> has been pardoned by Zafod Beeblebrox.
*/

void    PresidentialPardonForm::execute(Bureaucrat const & executor)const
{
    if (this->getSignedForm() == false)
        throw Form::FormNotSigned();
    if (executor.GetGrade() > this->getGradeToExec())
    {
        std::cout << HRED << "Cannot execute the Form: ";
        throw Form::GradeTooLowException();
    }
    std::cout << GREEN << "["<< target << " has been pardoned by Zafod Beeblebrox.]"
    << OFF << std::endl; 
}

std::string    PresidentialPardonForm::geTarget()const
{
    return (this->target);
}