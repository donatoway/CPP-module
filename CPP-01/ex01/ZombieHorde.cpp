#include "zombie.hpp"

zombie* zombie::newZombie( std::string name1 )
{
    return new zombie(name1);
}

zombie*    zombie::zombieHorde( int N, std::string name )
{
    this->list = new zombie *[N];
    this->n = N;
    for (int i = 0; i < N; i++)
    {
        list[i] = newZombie(name);
    }
    
    return (*list);
}