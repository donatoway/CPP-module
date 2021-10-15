#ifndef DOG_HPP
#define DOG_HPP

#include "../AnimalBase/Animal.hpp"
#include "../Brain/Brain.hpp"

class Dog: public Animal
{
    public:
            Dog();
            virtual ~Dog();
            Dog(const Dog &obj);
            Dog & operator= (Dog &obj);
            std::string getType()const;
            void    makeSound()const;
            std::string getDogIdea();
            void        setDogIdea(const std::string &str);
    protected:
            std::string Type;
    private:
                Brain *DogBrain;
};

#endif