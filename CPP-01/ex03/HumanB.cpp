#include "Weapon.hpp"
#include "HumanB.hpp"

HumanB::HumanB(std::string str)
{
    weapon = NULL;
    this->name = str;
}

void    HumanB::setWeapon(Weapon &weap)
{
    weapon = &weap;
}

void    HumanB::attacks()
{
    std::cout << name << " attacks with his " << weapon->getType()
    << std::endl;  
}