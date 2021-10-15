#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
    public:
            WrongAnimal();
            virtual ~WrongAnimal();

            WrongAnimal& operator= (WrongAnimal &obj);
            std::string    getType()const;
            void    makeSound()const;
    protected:
            std::string type;
};

#endif