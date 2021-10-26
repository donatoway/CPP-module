#include "Intern.hpp"

/*
Poiché compilare moduli è già abbastanza fastidioso, sarebbe crudele chiedere 
ai nostri burocrati di scriverli interamente da soli. No, lo faremo fare a uno stagista.
Stai per creare la classe Intern. Il tirocinante non ha nome, grado, caratteristiche 
che lo definiscano di sorta, ci interessa solo che faccia il suo lavoro.
Lo stagista ha una cosa importante, la funzione makeForm. Richiede due stringhe,
la prima che rappresenta il nome di un modulo e la seconda che rappresenta la
destinazione del modulo. Restituirà, come puntatore a Form, un puntatore a
qualsiasi classe di forma concreta è rappresentata dal primo parametro,
inizializzato con il secondo parametro. Stamperà qualcosa come
"Il tirocinante crea <form>" sull'output standard. Se sta usando un metodo peggiore,
come ramificazioni if/elseif/elseif/else, o qualche altra cosa brutta come questa,
non sarà accettato durante la valutazione. Se il modulo richiesto non è noto,
stampare un messaggio di errore esplicito.
*/


Intern::Intern()
{
    FormList[0] = "ShrubberyCreationForm";
    FormList[1] = "RobotMyRequestForm";
    FormList[2] = "PresidentialPardonForm";
};

Intern::Intern(const Intern &intern)
{
    *this = intern;
};

Intern::~Intern(){};

void    Intern::PrintSuccess(std::string name)
{
    std::cout << GREEN << "Intern creates Form " << name << OFF
    << "\n";
}

Form *Intern::makeForm(std::string FormName, std::string target)
{
    int i;
    for (i = 0; i < 3; i++)
    {
        if (FormName.compare(FormList[i]) == 0)
            break;
    }
    switch (i)
    {
        case 0:PrintSuccess(FormName); return new ShrubberyCreationForm(target);
        break;
        case 1:PrintSuccess(FormName); return new RobotMyRequestForm(target);
        break;
        case 2:PrintSuccess(FormName); return new PresidentialPardonForm(target);
        default:
        break;
    }
    throw Intern::InvalidFormName();
};

const char *Intern::InvalidFormName::what()const throw()
{
    return ("\e[0;91mError: Invalid Form Name");
}

Intern & Intern::operator=(const Intern & intern)
{
    for (size_t i = 0; i < 3; i++)
        this->FormList[i] = intern.FormList[i];
    return (*this);
}

