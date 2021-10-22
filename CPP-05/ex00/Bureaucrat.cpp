#include "Bureaucrat.hpp"

std::ostream& operator <<(std::ostream &out,  Bureaucrat & obj)
{
  std::cout << obj.GetName() << " have " << obj.GetGrade() << " grade" << std::endl;
  return (out);
}

Bureaucrat::Bureaucrat(){};

Bureaucrat::~Bureaucrat(){};

Bureaucrat::Bureaucrat(const std::string str, int nb):name(str)
{
  if (nb < 1)
    throw Bureaucrat::GradeTooHighException();
  if (nb > 150)
    throw Bureaucrat::GradeTooLowException();
    this->grade = nb;  
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj)
{
  this->grade = obj.grade;
  *this = obj;
};

Bureaucrat & Bureaucrat::operator = (const Bureaucrat &obj)
{
  this->grade = obj.grade;
  return (*this);
}

std::string   Bureaucrat::GetName()const
{
  return (this->name);
}

int         Bureaucrat::GetGrade()
{
  return (this->grade);
}

const char *  Bureaucrat::GradeTooHighException::what()const throw()
{
  return ("(EXCEPTIONS) The Grade is Too High");
};

const char * Bureaucrat::GradeTooLowException::what()const throw()
{
  return ("(EXCEPTIONS) The Grade is Too Low");
}

void    Bureaucrat::increase()
{
  if (this->grade + 1  > 150)
    throw Bureaucrat::GradeTooLowException();
  if (this->grade + 1 < 1)
    throw Bureaucrat::GradeTooHighException();
  this->grade++;
}

void  Bureaucrat::decrease()
{
  if (this->grade - 1  > 150)
    throw Bureaucrat::GradeTooLowException();
  if (this->grade - 1 < 1)
    throw Bureaucrat::GradeTooHighException();
  this->grade--;
}