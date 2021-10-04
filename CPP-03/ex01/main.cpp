#include    "ClapTrap.hpp"


/*
    Poichè non possiamo avere abbastanza Clap Trap ne farai un'altro.
    La classe si chiamerà ScavTrap, e erediterà da ClapTrap, il Costruttore, Distruttore, e l'attacco 
    che avranno Messaggi differenti. DopoTutto un clapTrap deve avere una certa individualità.
    la  classe ScavTrap avra il suo costruttore e distruttore con i suoi messaggi. Inoltre, deve essere presente un 
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
    std::cout << "ScavTrap Attack: " << this->getName() << " attacks " << 
    target  << ", causing " << this->getAttackDamage() << " point of damage! "
    << std::endl;
}

void    ScavTrap::guardGate()
{
    if (this->GuardBool == false)
    {
        this->GuardBool = true;
        std::cout << this->getName() << " entered in Gate keeper Mode" << std::endl;
    }
}

void    ScavTrap::guardGateOff()
{
    if (this->GuardBool == true)
    {
        this->GuardBool = false;
        std::cout << this->getName() << " exited from Gate keeper Mode" << std::endl;
    }
}
    
int main()
{
    ClapTrap    a("Freezer");
    ClapTrap    b("MajinBuu");
    ScavTrap    c("Goku");

    a.Set_AttackDamage();
    b.Set_AttackDamage();
    bool    DragonBall = true;
    while (a.getEnergyPoint() >= 0 && b.getEnergyPoint() >= 0 && c.getEnergyPoint() >= 0)
    {
        // Freezer attacks goku
        a.attack(c.getName());
        c.takeDamage(a.getAttackDamage());
        std::cout << c.getName() << " have " << c.getEnergyPoint()
        << " EnergyPoint\n" << std::endl;
        if (c.checkDeath())
            break;

        // Majin Buu attacks goku
        b.attack(c.getName());
        c.takeDamage(b.getAttackDamage());
        std::cout << c.getName() << " have " << c.getEnergyPoint()
        << " EnergyPoint\n" << std::endl;
        if (c.checkDeath())
            break;

         // Freezer got Balzar Beans
         if (DragonBall == true)
         {
            std::cout << "freezer Got a balzar beans" << std::endl; 
            a.beRepaired(50);
            DragonBall = false;
         }

        // Goku attacks Freezer
        c.attack(a.getName());
        a.takeDamage(c.getAttackDamage());
        std::cout << a.getName() << " have " << a.getEnergyPoint()
        << " EnergyPoint\n" << std::endl;
        if (a.checkDeath())
            break;
            
        //Goku enter in GateKeeperMode
        c.guardGate();
    }
}