#include "DiamondTrap.hpp"


DiamondTrap::DiamondTrap():ClapTrap("_clap_name"),FragTrap("_clap_name"),ScavTrap("_clap_name")
{
    std::cout << "DiamondTrap constructor called"<< std::endl;
}

DiamondTrap::DiamondTrap(std::string id):ClapTrap(id + "_clap_name"),FragTrap(id),ScavTrap(id)
{
    this->name = id;
    this->SetHitPoint(FragTrap::getHitPoint());
    this->SetEnergyPoint(ScavTrap::getEnergyPoint());
    this->SetAttackDamage2(FragTrap::getAttackDamage());
    std::cout << "DiamondTrap [" << this->name << "] " << "has been Created"
    << std::endl;
}

DiamondTrap& DiamondTrap::operator=(DiamondTrap &obj)
{
    this->name = obj.name;
    this->SetHitPoint(FragTrap::getHitPoint());
    this->SetEnergyPoint(ScavTrap::getEnergyPoint());
    this->SetAttackDamage2(FragTrap::getAttackDamage());
    return (*this);
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap  [" << this->getDiamondName() << "] has been destroyed"
    << std::endl; 
}

std::string DiamondTrap::getDiamondName()
{
    return (this->name);
}
void    DiamondTrap::attack(std::string const & target)
{
    ScavTrap::attack(target);
}

void    DiamondTrap::whoAmI()
{
    std::cout << "[WhoAmI] : " << "DiamondTrap name = " << name
    << ", ClapTrap Name = " << this->getName() << std::endl;
}