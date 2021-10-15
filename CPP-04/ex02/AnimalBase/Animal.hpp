#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
    public:
            Animal();
            virtual ~Animal();
            Animal(const Animal &obj);
            Animal & operator=(Animal &obj);
            virtual std::string    getType()const = 0;
            virtual void    makeSound()const = 0;
    protected:
            std::string Type;
};

#endif
