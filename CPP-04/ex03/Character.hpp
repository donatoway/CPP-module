#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character:public ICharacter
{
    public:
            Character(std::string str);
            Character(Character &obj);
            ~Character();
            std::string const & getName() const;
            Character & operator=(Character &obj);
            void use(int idx, ICharacter& target);
            void unequip(int idx);
            void equip(AMateria* m);

    private:
            AMateria    *Materias[4];
            std::string name;
            int         count;
};

#endif