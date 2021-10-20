#include "Character.hpp"

void Character::use(int idx, ICharacter& target)
{
    if (idx < 4 && idx >= 0 && this->Materias[idx] != NULL)
        this->Materias[idx]->use(target);
}

Character::Character(std::string str)
{
    for (size_t i = 0; i < 4; i++)
    {
        this->Materias[i] = 0;
    }  
    this->name = str;
    this->count = 0;
  //  std::cout << "Character Constructor Called\n";
}

Character::Character(Character &obj)
{
    this->name = obj.name;
    this->count = 0;

    for (size_t i = 0; i < 4; i++)
    {
        this->Materias[i] = obj.Materias[i]->clone();
        delete obj.Materias[i];
        obj.Materias[i] = NULL;
    }
}

Character & Character::operator=(Character &obj)
{
     this->name = obj.name;
     this->count = 0;
    for (size_t i = 0; i < 4; i++)
    {
        if (obj.Materias[i])
        {
            this->Materias[i] = obj.Materias[i]->clone();
            delete obj.Materias[i];
            obj.Materias[i] = NULL;
        }
    }
    return (*this);
}

Character::~Character()
{
    //std::cout << "Character Destructor Called\n";
    for (size_t i = 0; i < 4; i++)
    {
        if (this->Materias[i])
            delete this->Materias[i];
    }
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