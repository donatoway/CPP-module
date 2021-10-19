#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character:public ICharacter
{
    public:
            Character(std::string str);
            Character(const Character &obj);
            virtual std::string const & getName() const;
            Character & operator=(const Character &obj);
            virtual void use(int idx, ICharacter& target);
            virtual void unequip(int idx);
            virtual void equip(AMateria* m);

    private:
            AMateria    *Materias[4];
            std::string name;
            int         count;
};

#endif