#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
    public:
            Animal();
            virtual ~Animal();
            Animal & operator=(Animal &obj);
            virtual std::string    getType()const;
            virtual void    makeSound()const;
    protected:
            std::string Type;
};

#endif
