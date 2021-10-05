#ifndef     SCAVTRAP_HPP
#define     SCAVTRAP_HPP

#include    "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
    public:
            ScavTrap();
            ScavTrap(std::string id);
            ~ScavTrap();
            ScavTrap&   operator=(ScavTrap &obj);
            void    attack(std::string const & target);
            void    guardGate();
            void    guardGateOff();
    private:
            bool GuardBool;
};

#endif
