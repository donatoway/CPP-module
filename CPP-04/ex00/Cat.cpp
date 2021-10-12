#include "Cat.hpp"

Cat::Cat()
{
    std::cout << "cat Constructor Called" << std::endl;
    this->Type = "Cat";
}

Cat::~Cat()
{
    std::cout << "Cat Destructor Called" << std::endl;

}

void    Cat::makeSound()const
{
    std::cout << "The " << this->Type << " Sound is " << " Miao!\n";
}

std::string Cat::getType()const
{
    return (this->Type);
}

 Cat&    Cat::operator=(Cat &obj)
 {
     this->Type = obj.Type;
     return (*this);
 }