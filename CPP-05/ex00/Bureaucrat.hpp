#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class Bureaucrat
{
  public:
          Bureaucrat();
          ~Bureaucrat();
          Bureaucrat(const std::string str, int nb);
          Bureaucrat(const Bureaucrat &obj);
          Bureaucrat &  operator = (const Bureaucrat &obj);
          std::string   GetName()const ;
          int           GetGrade();
          void          increase();
          void          decrease();

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