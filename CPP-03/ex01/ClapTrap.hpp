#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
    public:
            ClapTrap();
            ClapTrap(std::string id);
            ~ClapTrap();

            ClapTrap   & operator=(ClapTrap &obj);
            void        attack(std::string const & target);
            void        takeDamage(unsigned int amount);
            void        beRepaired(unsigned int amount);
            std::string getName();
            void        Set_AttackDamage();
            int         getAttackDamage();
            void        SetAttackDamage2(int n);
            void        SetEnergyPoint(int n);
            int         getEnergyPoint();
            void        SetHitPoint(int n);
            int         getHitPoint();
            void        check2Points();
    private:
            std::string Name;
            int         Hitpoint;
            int         EnergyPoint;
            int         AttackDamage;
            int         RechargeUsed;
};

#endif