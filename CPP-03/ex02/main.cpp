#include "FragTrap.hpp"

int main()
{
    FragTrap a("Raul"),b("KenShiro");

    while (a.getEnergyPoint() >= 0 && b.getEnergyPoint() >= 0)
    {
        //RAUL attacks KenShiro
        a.attack(b.getName());
        b.takeDamage(a.getAttackDamage());
        std::cout << b.getName() << " have " << b.getEnergyPoint() << " EnergyPoint\n\n";
        if (b.checkDeath())
            break;

        //KenShiro attacks RAUL
        b.attack(a.getName());
        a.takeDamage(b.getAttackDamage());
        std::cout << a.getName() << " have " << a.getEnergyPoint() << " EnergyPoint\n\n";
        if (a.checkDeath())
            break;
        // Raul Bara
        std::cout << a.getName() << " got 30 LifePoints" << std::endl;
        a.beRepaired(30);
        a.highFivesGuys();
    }
    return (0);
}