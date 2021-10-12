#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog: public Animal
{
    public:
            Dog();
            virtual ~Dog();
            Dog & operator= (Dog &obj);
            std::string getType()const;
            void    makeSound()const;
    protected:
            std::string Type;
};

#endif