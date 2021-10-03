#include "ClapTrap.hpp"

std::string SetBattle(std::string str[])
{
    std::cout << "This is a battle between 2 warriors \n" <<
    "Choose the name of first Warrior\n";
    std::cin >> str[0];
    std::cout << "Choose the name of second Warrior\n";
    std::cin >> str[1];
    return (str[0]);
}

int main()
{   
    std::string     str[2];
    SetBattle(str);
    ClapTrap        a(str[0]),b(str[1]);
    int             round = 1;

    a.Set_AttackDamage(),b.Set_AttackDamage();
    std::cout << "\nGame Started    <---> \n" << std::endl;
    while (a.getEnergyPoint() > 0 && b.getEnergyPoint() > 0)
    {
        // A attacks B
        std::cout << "[ROUND " << round++ << "]" << std::endl;
        a.attack(b.getName());
        b.takeDamage(a.getAttackDamage());
        if (b.getEnergyPoint() <= 0)
            break;
        std::cout << b.getName() << " have " << b.getEnergyPoint() << " EnergyPoint\n\n";
        b.check2Points();      // get bonus point if reach 2 EnergyPoint
        
        // B attacks A
        std::cout << "[ROUND " << round++ << "]" << std::endl;
        b.attack(a.getName());
        a.takeDamage(b.getAttackDamage());
        if (a.getEnergyPoint() <= 0)
            break;
        std::cout << a.getName() << " have " << a.getEnergyPoint() << " EnergyPoints\n\n";
        a.check2Points();    // get bonus point if reach 2 EnergyPoint
    }

    std::cout << "GAME OVER" << std::endl;

    return (0);
}