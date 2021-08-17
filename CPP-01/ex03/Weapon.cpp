#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	this->type = type;
}

const std::string   & Weapon::getType()
{
    std::string const &ref = type; 
    return ref;
}

void    Weapon::setType(std::string str)
{
    this->type = str;
}