#include <iostream>
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

/*
    class AMateria   :  is the Abstract Class interface
    Ice and Cure     :  are implement class of Amateria Interface,they have
                        clone() that allocate memory for a new Ice or new Cure Obj ,
                        use() print his type of materia and the name
                        of the Character passed.
    class ICharacter :  is the Interface.
    class Character  :  is the class that implement the ICharacter Interface. The functions are
                        use() that print wich slot of his type we have to print, equip() that
                        fill a list[4] whit the Materia Ice or Cure, unequipe() remove the materia
                        in a particular slot but not delete the memory!
    class IMateriaSource: Is the Interface Class
    class MateriaSource: This class implement IMateriaSource, the functions are  LearnMateria()
                         that store in an AMateria array[4] each slot whit one Materia (Ice or Cure)
                         and Max Store Memory is 4 Materias, CreateMateria() return a New Materia (ice or cure)
                         and u need just to pass which Materia you want create by string as parameter. 
    
*/
int main()
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter* me = new Character("me");
    AMateria* tmp;

    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    delete bob;
    delete me;
    delete src;
    
    std::cout << "\n\nMINE TEST\n";
    //********************************
    std::cout << "Copy Assignation deep Character\n";
    ICharacter *a = new Character("JHON");
    a->equip(new Ice);

    ICharacter *b = a;

    std::cout << "A NAME = " << a->getName() << std::endl
    << "Materia's message is :";
    a->use(0, *a);
    std::cout << "B NAME = "<<  b->getName() << std::endl
    << "Materia's message is :";
    b->use(0, *b);

    delete b;
    //******************************
    std::cout << "\n\nCopy Constructor deep Character\n";
    ICharacter *c = new Character("MIMMO");
    a->equip(new Cure);

    ICharacter *d(c);

    std::cout << "C NAME = " << c->getName() << std::endl
    << "Materia's message is :";
    c->use(0, *a);
    std::cout << "D NAME = "<<  d->getName() << std::endl
    << "Materia's message is :";
    d->use(0, *d);

    delete d;

    //**********************************
    std::cout << "\n\nADD MORE THAN 4 MATERIA WILL STORE ANYWAY\
    MAX 4 MATERIA \n";
    ICharacter *paul = new Character("paul");
    IMateriaSource *mat = new MateriaSource();
    
    for (size_t i = 0; i < 10; i++)
    {
      if (i % 2 == 0)
        mat->learnMateria(new Ice());
      else
        mat->learnMateria(new Cure());
    }
    for (size_t i = 0; i < 10; i++)
    {
        if (i % 2 == 0)
          paul->equip(mat->createMateria("ice"));
        else
          paul->equip(mat->createMateria("cure"));
        paul->use(i, *paul);
    }
    delete paul;
    delete mat;
    return 0;
}