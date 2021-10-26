#ifndef ROBOTMYREQUESTFORM_HPP
#define ROBOTMYREQUESTFORM_HPP

#include "Bureaucrat.hpp"
#include "Form.hpp"

/*
RobotomyRequestForm (voti richiesti: sign 72, exec 45).
Azione: emette dei rumori di perforazione e ci dice che 
<target> è stato robotomizzato con successo il 50% delle volte. 
Altrimenti, dicci che è un fallimento.
*/

class   RobotMyRequestForm: public Form
{
    public:
            RobotMyRequestForm();
            RobotMyRequestForm(std::string str);
            RobotMyRequestForm(const RobotMyRequestForm& obj);
            RobotMyRequestForm & operator=(const RobotMyRequestForm & obj);
            virtual ~RobotMyRequestForm();
            std::string    geTarget()const;
            void    execute(Bureaucrat const & executor)const;
    private:
            std::string target;
};

#endif