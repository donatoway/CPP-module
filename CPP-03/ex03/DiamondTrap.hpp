#ifndef DIAMOND_TRAP_HPP
#define DIAMOND_TRAP_HPP

#include "FragTrap.hpp"

class DiamondTrap:public FragTrap, public ScavTrap
{
    public:
            DiamondTrap(std::string id);
            DiamondTrap();
            virtual ~DiamondTrap();

            DiamondTrap& operator=(DiamondTrap &obj);
            std::string    getDiamondName();
            void    attack(std::string const & target);
            void    whoAmI();
    private:
            std::string name;
};

#endif