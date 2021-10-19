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
    this->name = obj.name;
    this->count = 0;
    for (size_t i = 0; i < 4; i++)
    {
        if (Materias[i])
            delete Materias[i];
        Materias[i] = NULL;
    }
    for (size_t i = 0; i < 4; i++)
    {
        this->Materias[i] = obj.Materias[i]->clone();
        delete obj.Materias[i];
    }
}

Character & Character::operator=(const Character &obj)
{
     this->name = obj.name;
     this->count = 0;
    for (size_t i = 0; i < 4; i++)
    {
        if (this->Materias[i])
            delete this->Materias[i];
        this->Materias[i] = NULL;
    }
    for (size_t i = 0; i < 4; i++)
    {
        this->Materias[i] = obj.Materias[i]->clone();
        delete obj.Materias[i];
    }
    return (*this);
}

Character::~Character()
{
    std::cout << "Character Destructor Called\n";
    for (size_t i = 0; i < 4; i++)
        delete this->Materias[i];
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