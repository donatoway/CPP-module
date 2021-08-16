#include "zombie.hpp"

zombie::zombie(std::string name1)
{
    this->name = name1;
}

zombie::~zombie()
{
    std::cout << this->name << " is died" << std::endl;
}

void    zombie::announce()
{
    std::cout << this->name << " BraiiiiiiinnnzzzZ..."
    << std::endl;
}