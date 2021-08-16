#include "zombie.hpp"

int main()
{
    //----- ANNOUNCE ----------

    std::cout << "--------ANNOUNCE----------" << std::endl;
    zombie *monster;
    monster = NULL;
    monster = monster->newZombie("carlo");
    monster->announce();
    delete monster;
    std::cout << "--------NEWZOMBIE----------" << std::endl;

    //-------- NEWZOMBIE --------
    
    monster = monster->newZombie("peppe");
    monster->announce();
    delete monster;

    //-------- RANDOMCHUMP ------
    std::cout << "--------RANDOMCHUMP----------" << std::endl;
    monster->zombie_create();
}