#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>
#include <random>
#include <time.h>
class zombie
{
    public:
        zombie(std::string name);
        ~zombie();
        void    announce();
        zombie* newZombie( std::string name );
        void    randomChump( std::string name );
        void    zombie_create();
        int     check_num(size_t num[], size_t i);
        zombie*    zombieHorde( int N, std::string name );
    private:
        std::string name;
        zombie **list;
        int n;
};

#endif