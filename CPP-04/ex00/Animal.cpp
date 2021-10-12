#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "Animal Constructor Called " << std::endl;
    this->Type = "Animal";
}

Animal::~Animal()
{
    std::cout << "Animal Destructor Called" << std::endl;
}

void    Animal::makeSound()const
{
    std::cout << "This Animal no have any sound" << std::endl;
}

std::string Animal::getType()const
{
    return (this->Type);
}

Animal & Animal::operator=(Animal &obj)
{
    this->Type = obj.Type;
    return (*this); 
}