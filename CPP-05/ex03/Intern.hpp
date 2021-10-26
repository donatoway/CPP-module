#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
    public:
            Intern();
            ~Intern();
            Intern & operator=(const Intern & intern);
            Intern(const Intern &intern);
            Form *makeForm(std::string FormName, std::string target);
            void    PrintSuccess(std::string name);
            class InvalidFormName:public std::exception
            {
                const char *what()const throw();
            };
    private:
            std::string FormList[3];
};

#endif