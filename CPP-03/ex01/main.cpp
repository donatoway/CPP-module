#include    "ScavTrap.hpp"

int main()
{
    ClapTrap    a("Freezer");
    ClapTrap    b("MajinBuu");
    ScavTrap    c("Goku");

    a.Set_AttackDamage();
    b.Set_AttackDamage();
    bool    DragonBall = true;
    while (a.getEnergyPoint() >= 0 && b.getEnergyPoint() >= 0 && c.getEnergyPoint() >= 0)
    {
        // Freezer attacks goku
        a.attack(c.getName());
        c.takeDamage(a.getAttackDamage());
        std::cout << c.getName() << " have " << c.getEnergyPoint()
        << " EnergyPoint\n" << std::endl;
        if (c.checkDeath())
            break;

        // Majin Buu attacks goku
        b.attack(c.getName());
        c.takeDamage(b.getAttackDamage());
        std::cout << c.getName() << " have " << c.getEnergyPoint()
        << " EnergyPoint\n" << std::endl;
        if (c.checkDeath())
            break;

         // Freezer got Balzar Beans
         
         if (DragonBall == true)
         {
            std::cout << "freezer Got a balzar beans" << std::endl; 
            a.beRepaired(50);
            DragonBall = false;
         }

        // Goku attacks Freezer
        c.attack(a.getName());
        a.takeDamage(c.getAttackDamage());
        std::cout << a.getName() << " have " << a.getEnergyPoint()
        << " EnergyPoint\n" << std::endl;
        if (a.checkDeath())
            break;
            
        //Goku enter in GateKeeperMode
        c.guardGate();
    }
    return (0);
}