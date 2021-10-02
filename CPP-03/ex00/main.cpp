#include <string>
#include <iostream>
/*

    costruire una classe chiamata ClapTrap, e avra i seguenti attributi privati
    inizializzati ai valori specificati:

    - Name (parametro del costruttore)
    - hitpoint(10)
    - Energy point (10)
    - Attack damage (0)

    dovrai anche dargli qualche public function:

    - void attack(std::string const & target)
    - void takeDamage(unsigned int amount)
    - void beRepaired(unsigned int amount)

    in ognuna di queste funzioni dovrai mostrare qualcosa per descrivere cosa accade.
    Per esempio, the ATTACK function dovra mostrare qualcosa come :
   << ClapTrap <name> attack <target>, causing <damage> points of damage! >>
    il costruttore e il distruttore dovranno anche mostrare qualcosa per far vedere che sono 
    stati chiamati.

    dovrai provvedere a un main che dimostri attraverso i test che il tuo codice è funzionale!
*/

int     n = 0;

std::string ft_itoa(int a)
{
    std::string ss="";   //create empty string
    while(a)
    {
        int x=a%10;
        a/=10;
        char i='0';
        i=i+x;
        ss=i+ss;      //append new character at the front of the string!
    }
    return ss;
}

class ClapTrap
{
    public:
            ClapTrap();
            ClapTrap(std::string id);

            ~ClapTrap();
            void attack(std::string const & target);
            void takeDamage(unsigned int amount);
            void beRepaired(unsigned int amount);
            std::string getName();
    private:
            std::string Name;
            int         Hitpoint;
            int         EnergyPoint;
            int         AttackDamage;
};

ClapTrap::ClapTrap():Name("NoName"),Hitpoint(10),EnergyPoint(10), AttackDamage(0)
{
    n++;
    this->Name.append(ft_itoa(n));
    std::cout << Name << " is Born" << std::endl;
}

ClapTrap::ClapTrap(std::string id):Name(id), Hitpoint(10),EnergyPoint(10), AttackDamage(0)
{
    std::cout << Name << " is Born" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "destructor called" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    this->AttackDamage = amount;
}

void    ClapTrap::attack(std::string const & target)
{
    std::cout << this->Name << " attack " << target
    << ", causing " << this->AttackDamage << " point of damage! "
    << std::endl;
}

std::string    ClapTrap::getName()
{
    return (this->Name);
}



int main()
{
    ClapTrap a("Goku"),b("Vegeta");

    a.attack(b.getName());



}