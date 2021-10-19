#include <iostream>
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

/*
    -Completa la definizione della seguente Amateria class e implementa le necessarie member functions.
        class ......
    - Crea la concreta Materia Ice e Cure . Il loro type sarà il loro name in lowercase.
    Il loro clone() ritornerà una nuova istanza del reale tipo di  Materia.

    -Riguardo use(ICharacter&) method, mostrerà:
            - Ice: "*shoots an ice bolt at NAME*"
            - Cure: "heals NAME's wounds*"
            (certo, rimpiazza Name con il nome del Character)
    Crea la Character class, quale implementerà le seguenti interfacce:
    class ICharacter
    {
        public:
                virtual ~ICharacter(){}
                virtual std::string const & getName() const = 0;
                virtual void equip(AMateria* m) = 0;
                virtual void unequip(int idx) = 0;
                virtual void use(int idx, ICharacter &target) = 0;
    }

    -Il personaggio possiede al massimo 4 materie, vuote all'inizio. Equipaggerà
    la materia  negli slot da 0 a 3, in questo ordine.
    Nel Caso proviamo a equipaggiare una materia in un inventario pieno , o usa/disequipaggia una Materia
    inesistente, non fare nulla .
    Il unequip method non deve cancellare la Materia.
    L'use(int, ICharacter&) method dovrà usare la Materia al idx slot, e passare target come parametro a AMateria::use method.
    Il tuo Character dovrà avere un costruttore che prende il suo nome come parametro. Una Copia o un'assegnazione dovrà essere deep.
    La vecchia Materia di un Character dovrà essere cancellata. Stessa cosa per la distruzione di un personaggio

    Crea la MateriaSource class, quale dovrà implementare la seguente interfaccia:

    class IMateriaSource
    {
        public:
                virtual ~IMateriaSource(){}
                virtual void learnMateria(AMateria*) = 0;
                virtual AMateria* createMateria(std::string const & type) = 0;
    }

    LearnMateria dovrebbe copiare la Materia passata come parametro, e salvarla nella memoria
    per essere clonata dopo. Allo stesso modo del Character, la Sorgetnte può conoscere al massimo 4 Materia,
    che non sono necessariamente uniche.

    createMateria(std::string const &) ritornerà una nuova Materia, la quale sarà una copia della Materia
    (precedentemente imparata dalla Source ) quale type è uguale al parametro.
    Return 0 se il type è sconosciuto.

    In poche parole, la tua Source dovrà essere in grado di imparare "templates" di Materia e ricrearle su
    richiesta. Dovresti essere in grado di creare una materia senza sapere il suo reale tipo, solo una stringa che lo 
    identifica.

    Come il solito qui il test main che dovrai compilare!
*/


//controllare Se ci sono tutte le funzioni in Character , ricontrollare e andare avanti

int main()
{
    /*
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");
    AMateria* tmp;
    tmp = src->createMateria("cure");
    me->equipe(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharater* bob = new Character("bob");

    me->use(0, *bob);
    me->use(1,*bob);

    delete bob;
    delete me;
    delete src;

    return (0);

    */

    

    
    return (0);
}