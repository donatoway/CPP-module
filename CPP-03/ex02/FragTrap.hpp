#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ScavTrap.hpp"

class  FragTrap: public ClapTrap
{
    public:
            FragTrap();
            FragTrap(std::string id);
            ~FragTrap();
            FragTrap & operator = (FragTrap &obj);
            void    highFivesGuys();
    private:

};

#endif