#include "Dog.hpp"

Dog::Dog()
{
    this->DogBrain = new Brain;
    std::cout << "Dog Constructor Called" << std::endl;
    this->Type = "Dog";
}

std::string Dog::getType()const
{
    return (this->Type);
}

Dog::~Dog()
{
    delete this->DogBrain;
    std::cout << "Dog Destructor Called" << std::endl;
}

void    Dog::makeSound()const
{
    std::cout << "The " << this->Type << " Sound is " << " Bau Bau!\n";
}

 Dog & Dog::operator=(Dog &obj)
 {
     this->Type = obj.Type;
     *this->DogBrain = *obj.DogBrain;
     return (*this);
 }

 Dog::Dog(const Dog &obj)
 {
     std::cout << "Dog Copy Constructor Called" << std::endl;
     this->Type = obj.Type;
     this->DogBrain = new Brain;
     *DogBrain = *obj.DogBrain;
 }

std::string Dog::getDogIdea()
{
    return (this->DogBrain->getBrainIdea());
}

void        Dog::setDogIdea(const std::string &str)
{
    this->DogBrain->setBrainIdea(str);
}