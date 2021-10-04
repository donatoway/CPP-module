#include    "ClapTrap.hpp"


/*
    Poichè non possiamo avere abbastanza Clap Trap ne farai un'altro.
    La classe si chiamerà ScavTrap, e erediterà da ClapTrap, il Costruttore, Distruttore, e l'attacco 
    che avranno Messaggi differenti. DopoTutto un clapTrap deve avere una certa individualità.
    la  classe ScavTrap avra il suo costruttore e distruttore con i suoi messaggi .Inoltre, deve essere presente un 
    corretto  ordinamento di Costruzione/distruzione (quando costruisci un ScavTrap, dovresti iniziare costruendo ClapTrap...
    la distruzione è in ordine inverso), il test deve dimostrare questo.

    ScavTrap userà gli attributi di ClapTrap (avrai bisogno di modificare claptrap di conseguenza)! E dovrai inizializzarli a:

    - Name (parametro del costruttore)
    - HitPoint (100)
    - EnergyPoint (50)
    - attack damage (20)

    ScavTrap avrà una nuova funzione: void guardGate(); questa funzione mostrerà il messaggio
    per annunciare che ScavTrap è entrato in Gate keeper Mode.
    Estendi il main per testare tutto.


*/

class ScavTrap: public ClapTrap
{
    public:
            ScavTrap();
            ScavTrap(std::string id);
            ~ScavTrap();
            void    attack(std::string const & target);
            void    guardGate();
            void    guardGateOff();
    private:
            bool GuardBool;
};

ScavTrap::ScavTrap(){};

ScavTrap::ScavTrap(std::string id):ClapTrap(id) //inizializzare ClapTrap
{
    this->SetHitPoint(100);
    this->SetEnergyPoint(50);
    this->SetAttackDamage2(20);
    this->GuardBool = false;
    std::cout << "Constructor ScavTrap called" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap Destructor Called" << std::endl;
}

void    ScavTrap::attack(std::string const & target)
{
    std::cout << "ScavTrap:" << this->getName() << " attacks " << 
    target  << ", causing " << this->getAttackDamage() << " point of damage! "
    << std::endl;
}

void    ScavTrap::guardGate()
{
    if (this->GuardBool == false)
        this->GuardBool = true;
    std::cout << this->getName() << " entered in Gate keeper Mode" << std::endl;
}

void    ScavTrap::guardGateOff()
{
    if (this->GuardBool == true)
        this->GuardBool = false;
    std::cout << this->getName() << " exited from Gate keeper Mode" << std::endl;
}
    
int main()
{
    ScavTrap    a("alberto");
    ClapTrap    b("mirko");

    std::cout << "name: " << b.getName() << "\nHitpoint: " << b.getHitPoint();
    std::cout << "\nattackDamage: " << b.getAttackDamage() << "\nEnergyPoint: "
    << b.getEnergyPoint() << "\n\n\n" << std::endl; 
    std::cout << "name: " << a.getName() << "\nHitpoint: " << a.getHitPoint();
    std::cout << "\nattackDamage: " << a.getAttackDamage() << "\nEnergyPoint: "
    << a.getEnergyPoint() << std::endl; 


    a.guardGate();
    a.guardGateOff();

}