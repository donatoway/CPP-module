#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "../Brain.hpp"

class Cat: public Animal
{
    public:
            Cat();
            virtual ~Cat();
            Cat(const Cat &obj);
            Cat&    operator=(Cat &obj);
            std::string getType()const;
            void    makeSound()const;
            std::string getCatIdea();
            void        setCatIdea(const std::string &str);
    protected:
            std::string Type;
    private:
            Brain *CatBrain;

};

#endif
