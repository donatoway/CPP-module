#include    "ScavTrap.hpp"

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

ScavTrap&   ScavTrap::operator=(ScavTrap &obj)
{
    this->SetName(obj.getName());
    this->SetHitPoint(obj.getHitPoint());
    this->SetAttackDamage2(obj.getAttackDamage());
    this->SetEnergyPoint(obj.getEnergyPoint());
    return (*this);
}