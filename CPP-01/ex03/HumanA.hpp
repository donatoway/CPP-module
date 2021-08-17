#ifndef HUMANA_HPP
#define HUMANA_HPP
#include "Weapon.hpp"

class HumanA
{
    public:
            void    attacks();
            HumanA(std::string str, Weapon &wea);
    private:
            std::string name;
            Weapon &weapon;
};
#endif