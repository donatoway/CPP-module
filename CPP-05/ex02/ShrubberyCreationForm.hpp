#ifndef SHRUBBERYCREATEFORM_HPP
#define SHRUBBERYCREATEFORM_HPP

#include "Form.hpp"
#include "Bureaucrat.hpp"

class Form;
class ShrubberyCreationForm: public Form
{
    public:
                ShrubberyCreationForm();
                ShrubberyCreationForm(std::string str);
                ShrubberyCreationForm(const ShrubberyCreationForm &obj);
                ShrubberyCreationForm   &operator= (const ShrubberyCreationForm &obj);
                virtual ~ShrubberyCreationForm();
                std::string    geTarget()const;
                void    execute(Bureaucrat const & executor)const;
    private:
            std::string target;
};


#endif