#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


/*
Ora che hai i moduli di base, creerai alcuni moduli che effettivamente fanno qualcosa.
Crea alcune forme concrete:

• ShrubberyCreationForm (voti richiesti: sign 145, exec 137). Azione: creare un file 
chiamato <target>_shrubbery e scrivere alberi ASCII al suo interno, nella directory corrente.

Modulo di richiesta robotomia (voti richiesti: sign 72, exec 45). Azione: emette dei
rumori di perforazione e ci dice che <target> è stato robotomizzato con successo il 50% 
delle volte. Altrimenti, dicci che è un fallimento.

PresidentialPardonForm (voti richiesti: sign 25, exec 5). Azione: ci dice che <target> è 
stato graziato da Zafod Beeblebrox.

Tutti questi dovranno prendere un solo parametro nel loro costruttore, che rappresenterà
l'obiettivo del modulo. Ad esempio, "casa" se vuoi piantare arbusti a casa. Ricordare
gli attributi del form devono rimanere privati e nella classe base.

Ora è necessario aggiungere un metodo execute(Bureaucrat const & executor)2 const al form
di base e implementare un metodo che esegua l'azione del form in tutte le forme concrete.
Devi controllare che il modulo sia firmato e che il burocrate che sta tentando di eseguire
il modulo abbia un voto abbastanza alto, altrimenti genererai un'eccezione appropriata.
Sia che tu voglia fare questi controlli in ogni classe concreta o fare il check-in il
classe base quindi chiamare un altro metodo per eseguire l'azione dipende da te, ma un 
modo è più carino dell'altro. In ogni caso, la forma base deve essere una classe astratta.
Termina questo aggiungendo una funzione executeForm(Form const & form) al burocrate.
Deve tentare di eseguire il modulo e, se ha successo, stampare qualcosa come <burocrate>
esegue <form>. In caso contrario, stampa un messaggio di errore esplicito.
Aggiungi tutto ciò di cui hai bisogno al tuo main per verificare che tutto funzioni.
*/

/*
class ShrubberyCreationForm: public Form
{
    public:
            ShrubberyCreationForm(std::string str);
    private:
            std::string target;
};

PresidentialPardonForm (Required grades: sign 25, exec 5). 
Action: Tells us <target> has been pardoned by Zafod Beeblebrox.
*/



int main()
{
    try
    {
        Bureaucrat A("mimmo",6);
        PresidentialPardonForm B("B");


        A.signForm(B);
        B.execute(A);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}