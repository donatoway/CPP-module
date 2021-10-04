#include "ClapTrap.hpp"

ClapTrap::ClapTrap(){};

ClapTrap::ClapTrap(std::string id):Name(id), Hitpoint(10),EnergyPoint(10), AttackDamage(0)
{
    RechargeUsed = 0;
    std::cout << Name << " is Born" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "destructor called" << std::endl;
}

ClapTrap   & ClapTrap::operator=(ClapTrap &obj)
{
    this->Name = obj.Name;
    this->Hitpoint = obj.Hitpoint;
    this->AttackDamage = obj.AttackDamage;
    this->EnergyPoint = obj.EnergyPoint;
    
    return (*this);
}

void ClapTrap::takeDamage(unsigned int amount)
{
    this->EnergyPoint -= amount;
    std::cout << this->Name << " was awarded " << amount << " points"
    << std::endl;
    this->Hitpoint  -= amount;
    if (EnergyPoint <= 0)
        std::cout << this->Name << " is dead\n"  << std::endl;
}

void    ClapTrap::attack(std::string const & target)
{
    std::cout << this->Name << " attack " << target
    << ", causing " << this->AttackDamage << " point of damage! "
    << std::endl;
}

void    ClapTrap::Set_AttackDamage()
{
    int a;
    std::cout << "Set Attack Damage of : " << this->Name
    << std::endl;
    std::cin >> a;
    this->AttackDamage = a;
}

int    ClapTrap::getAttackDamage()
{
    return (this->AttackDamage);   
}

std::string    ClapTrap::getName()
{
    return (this->Name);
}

int     ClapTrap::getEnergyPoint()
{
    return (this->EnergyPoint);
}

int     ClapTrap::getHitPoint()
{
    return (this->Hitpoint);
}

void        ClapTrap::beRepaired(unsigned int amount)
{
    EnergyPoint += amount;
    std::cout << this->Name << " have " << amount <<
    " Energy Point more now, Total EnergyPoint = " <<
    this->EnergyPoint << std::endl << std::endl;
}

void    ClapTrap::check2Points()
{
    if (Hitpoint == 2 && this->RechargeUsed == 0)
    {
        std::cout << "[***BONUS ACTIVED****]" << std::endl;
        std::cout << Name << " Reached 2 EnergyPoints and unlocked the bonus points:\n";
        this->beRepaired(5);
        RechargeUsed = 1;
    }
}