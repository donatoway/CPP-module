#include "zombie.hpp"

zombie* zombie::newZombie( std::string name1 )
{
    return new zombie(name1);
}