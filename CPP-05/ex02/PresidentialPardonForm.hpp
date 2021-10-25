#ifndef  PRESIDENTIALPARDONFORM_HPP
#define  PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm:public Form
{
    public:
            PresidentialPardonForm();
            PresidentialPardonForm(std::string str);
            PresidentialPardonForm(const PresidentialPardonForm &obj);
            PresidentialPardonForm &operator=(const PresidentialPardonForm &obj);
            virtual ~PresidentialPardonForm();
            void    execute(Bureaucrat const & executor)const;
    private:
            std::string target;
            
};



#endif