#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

class  FragTrap: virtual public ClapTrap
{
    public:
            FragTrap();
            FragTrap(std::string id);
            virtual ~FragTrap();
            FragTrap & operator = (FragTrap &obj);
            void    highFivesGuys();
    private:

};

#endif