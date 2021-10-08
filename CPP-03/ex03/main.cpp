#include "DiamondTrap.hpp"

int main()
{
    DiamondTrap a("Carl");
    DiamondTrap b("donny");
    DiamondTrap c("Brian");

    //Presentazioni
    a.whoAmI();
    b.whoAmI();
    c.whoAmI();
    while (a.getEnergyPoint() >= 0 && b.getEnergyPoint() >= 0)
    {
        //A attacks B
        a.attack(b.getName());
        b.takeDamage(a.getAttackDamage());
        std::cout << b.getName() << " have " << b.getEnergyPoint() 
        << " EnergyPoints" << std::endl<<std::endl;
        if (b.checkDeath() == true)
            break;

        //B attacks A
        b.attack(a.getName());
        a.takeDamage(b.getAttackDamage());
        std::cout << a.getName() << " have " << a.getEnergyPoint() 
        << " EnergyPoints" << std::endl<<std::endl;
        if (a.checkDeath() == true)
            break;

        //A get 20 Points
        a.beRepaired(20);

        //B active a special ScavTrap function
        b.guardGate();
        //B say active a special FragTrap function
        b.highFivesGuys();
        std::cout << std::endl;
    }
    //the winner will Fight with Brian
    if (a.getEnergyPoint() >= 0)
    {
        std::cout << "DiamondTrap: " << a.getDiamondName() << " is winner\n";
        std::cout << "now " << a.getDiamondName() << " will fight with DiamonTrap Brian\n\n";
        //A attacks C
        a.attack(c.getName());
        c.takeDamage(a.getAttackDamage());
        c.checkDeath();
        //C attacks A
        c.SetAttackDamage2(3000);
        c.attack(a.getName());
        a.takeDamage(c.getAttackDamage());
        a.checkDeath();
    }
    std::cout << "\n\nGAME OVER\n" << std::endl;
    return (0);
}