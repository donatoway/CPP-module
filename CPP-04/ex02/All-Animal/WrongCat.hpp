#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP
#include "WrongAnimal.hpp"

class WrongCat:public WrongAnimal
{
    public:
            WrongCat();
            virtual ~WrongCat();
            WrongCat& operator=(WrongCat &obj);
            void    makeSound()const;
    protected:
            std::string type;
};

#endif