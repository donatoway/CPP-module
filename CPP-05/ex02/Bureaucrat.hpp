#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include "Form.hpp"

#define GREEN "\e[1;32m"
#define HRED "\e[0;91m"
#define YELLOW "\e[4;33m"
#define OFF "\e[0m"

class Form;
class Bureaucrat
{
  public:
          Bureaucrat();
          ~Bureaucrat();
          Bureaucrat(std::string str, int nb);
          Bureaucrat(const Bureaucrat &obj);
          Bureaucrat &  operator = (const Bureaucrat &obj);
          std::string   GetName()const ;
          int           GetGrade()const;
          void          increase();
          void          decrease();
          void          signForm(Form &obj);
          class GradeTooHighException :  public std::exception
          {
            public:
                  const char *what()const throw();
          };
          class GradeTooLowException :  public std::exception
          {
            public:
                  const char *what()const throw();
          };

  private:
          int grade;
          const std::string name;
};

std::ostream& operator <<(std::ostream &out,   Bureaucrat & obj);

#endif