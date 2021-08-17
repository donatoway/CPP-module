#include "Weapon.hpp"

class HumanB
{
     public:
            HumanB(std::string str);
            void    setWeapon(Weapon &weap);
            void    attacks();
    private:
            Weapon      *weapon;
            std::string name;
};