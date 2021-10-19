#ifndef CURE_HPP
#define CURE_HPP
#include "AMateria.hpp"

class Cure:public AMateria
{
    public:
            Cure();
            Cure(const Cure& obj);
            virtual ~Cure();
            Cure &operator = (const Cure & obj);
            Cure *clone() const;
            virtual void use(ICharacter& target);
    private:
            std::string MateriaType;
};

#endif