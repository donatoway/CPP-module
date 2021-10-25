#include "RobotomyRequestForm.hpp"

RobotMyRequestForm::RobotMyRequestForm():Form("",72,45),target(""){};

RobotMyRequestForm::RobotMyRequestForm(std::string str):Form("RobotMyRequestForm",72,45),target(str){};

RobotMyRequestForm::RobotMyRequestForm(const RobotMyRequestForm& obj)
{
    this->target = obj.target;
    *this = obj;
}

RobotMyRequestForm & RobotMyRequestForm::operator=(const RobotMyRequestForm & obj)
{
    this->target = obj.target;
    return (*this);
}

RobotMyRequestForm::~RobotMyRequestForm(){};

void    RobotMyRequestForm::execute(Bureaucrat const & executor)const
{
    if (this->getSignedForm() == false)
        throw Form::FormNotSigned();
    if (executor.GetGrade() > this->getGradeToExec())
    {
        std::cout << HRED << "Cannot execute the Form: ";
        throw Form::GradeTooLowException();
    }
   std::cout << GREEN<< "TRRRR TRRRR TRRR : " << this->target << " has been roboto"<<
   "mized successfully " << std::endl;
}