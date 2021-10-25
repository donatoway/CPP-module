#include "Bureaucrat.hpp"
/*
Aggiungi anche una funzione signForm al Burocrate. Se la firma va a buon 
fine, stamperà qualcosa come "<burocrate> firma <modulo>", altrimenti stamperà
qualcosa come "<burocrate> non può firmare <modulo> perché <motivo>".
*/

void          Bureaucrat::signForm(Form &obj)
{
  obj.beSigned(*this);
}

std::ostream& operator <<(std::ostream &out,  Bureaucrat & obj)
{
  std::cout << obj.GetName() << " have " << obj.GetGrade() << " grade" << std::endl;
  return (out);
}

Bureaucrat::Bureaucrat(){};

Bureaucrat::~Bureaucrat(){};

Bureaucrat::Bureaucrat(std::string str, int nb):name(str)
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

int         Bureaucrat::GetGrade()const
{
  return (this->grade);
}

const char *  Bureaucrat::GradeTooHighException::what()const throw()
{
  return ("(EXCEPTIONS) [BUREAUCRAT] The Grade is Too High");
};

const char * Bureaucrat::GradeTooLowException::what()const throw()
{
  return ("(EXCEPTIONS) [BUREAUCRAT] The Grade is Too Low");
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