#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    this->type = "Unknow";
    std::cout << "Constructor Wrong Animal called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "Destructor Wrong Animal called" << std::endl;
}

WrongAnimal& WrongAnimal::operator= (WrongAnimal &obj)
{
    this->type = obj.type;
    return (*this);
}

void    WrongAnimal::makeSound()const
{
    std::cout << "the " << this->getType() << " sound is NO-SOUND"<< std::endl;
}