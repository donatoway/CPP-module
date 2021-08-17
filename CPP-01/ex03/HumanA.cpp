#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA(std::string name, Weapon &wea) : name(name), weapon(wea) {};

void    HumanA::attacks()
{
    std::cout << name << " attacks with his " << weapon.getType()
    << std::endl;  
}