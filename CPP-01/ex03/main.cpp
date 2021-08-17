#include <iostream>
#include <string>
#include "HumanA.hpp"
#include "Weapon.hpp"
#include "HumanB.hpp"

/*
1) - creare una classe Weapon, che ha una stringa type e un metodo getType che 
    ritorna una const reference
    a questa stringa. deve avere anche un setType
2) - Successivamente crea 2 classi HumanA e HumanB ed entrambi hanno un Weapon, un Nome
     e una funzione di attacco
    che mostra a dysplay:   NOME attacca con la sua WEAPON_TYPE
3) - HumanA e HumanB sono quasi uguali ci sono solo 2 piccole differenze
    -- Mentre HumanA prende la WEAPON nel costruttore, HumanB non puo farlo.
    -- HumanB avvolte non potra avere un Arma , ma HumanA sarà sempre armato
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
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attacks();
		club.setType("some other type of club");
		jim.attacks();
    
	}
}