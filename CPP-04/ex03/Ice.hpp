#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
#include <iostream>

class Ice: public AMateria
{
    public:
            Ice();
            Ice(const Ice& obj);
            virtual ~Ice();
            Ice &operator = (const Ice & obj);
            Ice *clone() const;
            virtual void use(ICharacter& target);
    private:
            std::string MateriaType;
};

#endif