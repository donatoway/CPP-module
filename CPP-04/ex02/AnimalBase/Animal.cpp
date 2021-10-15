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

Animal & Animal::operator=(Animal &obj)
{
    this->Type = obj.Type;
    return (*this); 
}

Animal::Animal(const Animal &obj)
{
    std::cout << "CopyConstructor Animal called" << std::endl;
    this->Type = obj.Type;
}