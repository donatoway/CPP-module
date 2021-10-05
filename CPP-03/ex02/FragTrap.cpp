#include "FragTrap.hpp"

FragTrap::FragTrap(){};

FragTrap::~FragTrap()
{
    std::cout << "FragTrap Destructor Called" << std::endl;
}

FragTrap::FragTrap(std::string id):ClapTrap(id)
{
    std::cout << "FragTrap Constructor Called" << std::endl;
    this->SetName(id);
    this->SetAttackDamage2(30);
    this->SetEnergyPoint(100);
    this->SetHitPoint(100);
}

FragTrap & FragTrap::operator = (FragTrap &obj)
{
    this->SetName(obj.getName());
    this->SetAttackDamage2(obj.getAttackDamage());
    this->SetEnergyPoint(obj.getEnergyPoint());
    this->SetHitPoint(obj.getHitPoint());
    return (*this);
}

void    FragTrap::highFivesGuys()
{
    std::cout << "FragTrap: " << this->getName() << " says Give me Five " << std::endl;
}