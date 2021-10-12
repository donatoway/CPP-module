#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat: public Animal
{
    public:
            Cat();
            virtual ~Cat();
            Cat&    operator=(Cat &obj);
            std::string getType()const;
            void    makeSound()const;
    protected:
            std::string Type;
};

#endif
