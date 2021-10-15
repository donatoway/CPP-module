#include "Cat.hpp"

Cat::Cat()
{
    this->CatBrain = new Brain;
    std::cout << "cat Constructor Called" << std::endl;
    this->Type = "Cat";
}

Cat::~Cat()
{
    delete this->CatBrain;
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
     *this->CatBrain = *obj.CatBrain;
     return (*this);
 }

 Cat::Cat(const Cat &obj)
 {
    std::cout << "Cat CopyConstructor Called" << std::endl;
    this->Type = obj.Type;
    this->CatBrain = new Brain;
    *CatBrain = *obj.CatBrain;
 }

 std::string Cat::getCatIdea()
 {
     return (this->CatBrain->getBrainIdea());
 }

 void        Cat::setCatIdea(const std::string &str)
 {
    this->CatBrain->setBrainIdea(str);
 }
 