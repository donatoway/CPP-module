#include "Dog.hpp"

Dog::Dog()
{
    std::cout << "Dog Constructor Called" << std::endl;
    this->Type = "Dog";
}

std::string Dog::getType()const
{
    return (this->Type);
}

Dog::~Dog()
{
    std::cout << "Dog Destructor Called" << std::endl;
}

void    Dog::makeSound()const
{
    std::cout << "The " << this->Type << " Sound is " << " Bau Bau!\n";
}

 Dog & Dog::operator=(Dog &obj)
 {
     this->Type = obj.Type;
     return (*this);
 }