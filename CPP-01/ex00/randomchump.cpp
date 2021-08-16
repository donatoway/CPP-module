#include "zombie.hpp"

void    zombie::randomChump( std::string name )
{
    newZombie(name);
    announce();
}

int    zombie::check_num(size_t num[], size_t i)
{
    i = 0;
    if (num[0] == num[1] || num[0] == num[2])
        return (1);
    if (num[1] == num[2])
        return (1);     
    return (0);
}

void    zombie::zombie_create()
{
    size_t num[3];
    std::string names[6] = {"gino", "alberto", "carlo", "manuele", "pino","mimmo"};
    srand(time(NULL));

    for (size_t i = 0; i < 3; i++)
    {
        num[i] = rand() % 6;
        while (check_num(num, i) == 1)
        {
            num[i] = rand() % 6;
            if (check_num(num, i) == 0)
                break;
        }
        randomChump(names[num[i]]);
        delete this;
    }
}