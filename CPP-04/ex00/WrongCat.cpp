#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    this->type = "Cat";
    std::cout << "Constructor WrongCat Called" << std::endl;
}

void    WrongCat::makeSound()const
{
    std::cout << "the " << this->getType() << " sound is MIAMIAO"<< std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << "Destructor WrongCat Called" << std::endl;
}

std::string    WrongAnimal::getType()const
{
    return this->type;
}

WrongCat& WrongCat::operator=(WrongCat &obj)
{
    this->type = obj.type;
    return (*this);
}