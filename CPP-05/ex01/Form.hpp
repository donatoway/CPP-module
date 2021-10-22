#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
class Bureaucrat;
class Form
{
    public:
            Form();
            Form(const std::string str, int toSign, int toExec);
            Form(const Form &obj);
            ~Form();
            Form & operator=(const Form & obj);
            std::string getName()const;
            bool        getSignedForm();
            int         getGradeToSign()const;
            int         getGradeToExec()const;
            bool        beSigned(Bureaucrat &obj);
            class GradeTooHighException : public std::exception
            {
                const char *what() const throw();
            };
            class GradeTooLowException : public std::exception
            {
                const char *what() const throw();
            };
    private:
            const std::string   Name;
            bool                SignedForm;
            const int           GradeToSign;
            const int           GradeToExec;      
};

std::ostream    & operator<< (std::ostream &out, Form &obj);

#endif