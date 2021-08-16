#include "zombie.hpp"

zombie::zombie(std::string name1)
{
    this->name = name1;
}

zombie::~zombie()
{

    for (int i = 0; i < this->n; i++)
    {
        std::cout << list[i]->name << " destroyed "  << std::endl;
        delete list[i];
    }
    delete list;
}

void    zombie::announce()
{
    for (int i = 0; i < this->n; i++)
    {
       std::cout << list[i]->name << " BraiiiiiiinnnzzzZ..."  << std::endl;
    }
}