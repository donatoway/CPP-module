#include "Character.hpp"

void Character::use(int idx, ICharacter& target)
{
    if (idx < 4 && idx >= 0 && this->Materias[idx] != NULL)
        this->Materias[idx]->use(target);
}

Character::Character(std::string str)
{
    for (size_t i = 0; i < 3; i++)
    {
        this->Materias[i] = NULL;
    }
    
    this->name = str;
    this->count = 0;
    std::cout << "Character Constructor Called\n";
}

Character::Character(const Character &obj)
{
     for (size_t i = 0; i < 3; i++)
    {
        this->Materias[i] = obj.Materias[i];
    }
    this->name = obj.name;
}

Character & Character::operator=(const Character &obj)
{
     for (size_t i = 0; i < 3; i++)
    {
        this->Materias[i] = obj.Materias[i];
    }

    this->name = obj.name;
    return (*this);
}

std::string const & Character::getName()const
{
    return (this->name);
}

void Character::equip(AMateria* m)
{
    if (m != NULL && count < 4 && count >= 0 )
    {
        this->Materias[count] = m;
        count++;
    }
}

void Character::unequip(int idx)
{
    if (idx < 4 && idx >= 0)
        this->Materias[idx] = NULL;
}