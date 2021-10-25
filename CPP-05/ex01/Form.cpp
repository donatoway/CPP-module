#include "Bureaucrat.hpp"
#include "Form.hpp"

std::ostream    & operator<< (std::ostream &out,  Form &obj)
{
    std::string FormStatus;

    std::cout << YELLOW << "[Form " << obj.getName() << " Status]" << OFF << "\n" ;
    std::cout << "Form Name: " << obj.getName() << std::endl;
    std::cout << "Grade To Sign: " << obj.getGradeToSign() << std::endl;
    std::cout << "Grade To Execute: " << obj.getGradeToExec() << std::endl;
    if (obj.getSignedForm() == false)
        FormStatus.append("false");
    else
        FormStatus.append("true");
    if (obj.getSignedForm() == true)
        std::cout << "Status Sign : " << GREEN << FormStatus << OFF << std::endl;
    else
         std::cout << "Status Sign: "<< HRED  << FormStatus << OFF << std::endl;
    return (out);
}

Form::Form():Name(""),GradeToSign(0),GradeToExec(0){};

Form::Form(const std::string str, int toSign, int toExec):Name(str),GradeToSign(toSign),GradeToExec(toExec)
{
    if (toSign > 150 || toExec > 150)
        throw Form::GradeTooLowException();
    if (toSign < 1 || toExec < 1)
        throw Form::GradeTooHighException();
    this->SignedForm = false;
}

Form::~Form(){};

Form &  Form::operator=(const Form &obj)
{
    this->SignedForm = obj.SignedForm;
    return (*this);
}

Form::Form(const Form &obj):Name(obj.Name), GradeToSign(obj.GradeToSign),GradeToExec(obj.GradeToExec)
{
    *this = obj;
}

const char *Form::GradeTooHighException::what()const throw()
{
    return ("\e[0;91m(EXCEPTION) [FORM] the grade is to High");
}

const char *Form::GradeTooLowException::what()const throw()
{
    return ("\e[0;91m(EXCEPTION) [FORM] the grade is to low");
}

bool        Form::getSignedForm()
{
    return this->SignedForm;
}

int         Form::getGradeToSign()const
{
    return this->GradeToSign;
}

int           Form::getGradeToExec()const
{
    return this->GradeToExec;
}

std::string Form::getName()const
{
    return this->Name;
}

bool        Form::beSigned(Bureaucrat &obj)
{
    if (obj.GetGrade() > getGradeToSign() || obj.GetGrade() > 150)
    {
        std::cout  << HRED << obj.GetName() << " can't sign the Form ["
        << Name <<  "] because: Grade To Sign is Low\n";
        throw Form::GradeTooLowException();
    }
    if (obj.GetGrade() < 1)
        throw Bureaucrat::GradeTooHighException();
    this->SignedForm = true;
    std::cout << GREEN << "[Bureaucrat " << obj.GetName()
    << " signed the Form " << this->getName() << " ]"<< OFF <<std::endl;
    return (true);
}