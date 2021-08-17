#include <iostream>
#include <string>
#include "HumanA.hpp"
#include "Weapon.hpp"

/*
1) - creare una classe Weapon, che ha una stringa type e un metodo getType che ritorna una const reference
    a questa stringa. deve avere anche un setType
2) - Successivamente crea 2 classi HumanA e HumanB ed entrambi hanno un Weapon, un Nome e una funzione di attacco
    che mostra a dysplay:   NOME attacca con la sua WEAPON_TYPE
3) - HumanA e HumanB sono quasi uguali ci sono solo 2 piccole differenze
    -- Mentre HumanA prende la WEAPON nel costruttore, HumanB non puo farlo.
    -- HumanB avvolte non potra avere un Arma , ma HumanA sarà sempre armato
*/
/*
class Weapon
{
    public:
            Weapon(std::string type);
            const std::string   &getType();
            void    setType(std::string str);
    private:
            std::string type;
};
*/
/*
class HumanA
{
    public:
            void    attacks();
            HumanA(std::string str, Weapon &wea);
    private:
            std::string name;
            Weapon &weapon;
};
*/
class HumanB
{
     public:

            void    attacks();
    private:
            std::string name;
            Weapon weapon;
};
/*
Weapon::Weapon(std::string type)
{
	this->type = type;
}
*/
/*
const std::string   & Weapon::getType()
{
    std::string const &ref = type; 
    return ref;
}
*/
/*
HumanA::HumanA(std::string name, Weapon &wea) : name(name), weapon(wea) {};

void    HumanA::attacks()
{
    std::cout << name << " attacks with his " << weapon.getType()
    << std::endl;  
}
*/
void    HumanB::attacks()
{
    std::cout << name << " attacks with his " << weapon.getType()
    << std::endl;  
}
/*
void    Weapon::setType(std::string str)
{
    this->type = str;
   // std::cout << "setType" << type << std::endl;
}
*/
int main(void)
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attacks();
		club.setType("some other type of club");
		bob.attacks();
	}
/*	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
    
	}
*/
}