#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm():Form("ShrubberyCreationForm",145,137)
{
    this->target = "";
};

ShrubberyCreationForm::ShrubberyCreationForm(std::string str):Form("ShrubberyCreationForm",145,137)
{
    this->target = str;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj)
{
    *this = obj;
}

ShrubberyCreationForm   &ShrubberyCreationForm::operator= (const ShrubberyCreationForm &obj)
{
    this->target = obj.target;
    return (*this);
}
ShrubberyCreationForm::~ShrubberyCreationForm(){};
/*
Ora è necessario aggiungere un metodo execute(Bureaucrat const & executor)2 const al form
di base e implementare un metodo che esegua l'azione del form in tutte le forme concrete.
Devi controllare che il modulo sia firmato e che il burocrate che sta tentando di eseguire
il modulo abbia un voto abbastanza alto, altrimenti genererai un'eccezione appropriata.
Sia che tu voglia fare questi controlli in ogni classe concreta o fare il check-in il
classe base quindi chiamare un altro metodo per eseguire l'azione dipende da te, ma un 
modo è più carino dell'altro. In ogni caso, la forma base deve essere una classe astratta.
*/

void    ShrubberyCreationForm::execute(Bureaucrat const & executor)const
{
    std::string NameFile = this->target;
    
    if (this->getSignedForm() == false)
        throw Form::FormNotSigned();
    if (executor.GetGrade() > this->getGradeToExec())
    {
        std::cout << HRED << "Grade to execute ["<< target << "] is low" << OFF << "\n";
        throw Form::GradeTooLowException();
    }
    std::ofstream out;
    out.open(NameFile.append("_shrubbery"));
    int z = 30;
    int count = 0;
    char Asci = '*';
    for (int i = 0; i < 30; i++)
    {
        bool active = false;
        count+=2;
        z--;
        for (int y = 0; y < count; y++)
        {
            while (y < z && active == false)
            {
                out << " ";
                y++;
                if (y == z)
                    active = true,y = 0;
            }
            out << Asci; 
        }
        out << "\n\0";
    }
    out.close();
    std::cout << GREEN << "[Bureaucrat " << executor.GetName()
    << " Executed the Form ShrubberyCreationForm]" << std::endl;
}