#include "Cure.hpp"

Cure::Cure():AMateria("cure")
{
    this->MateriaType = "cure";
    std::cout << "Cure Construction Called\n";
}

Cure::Cure(const Cure& obj)
{
    this->MateriaType = obj.MateriaType;
}

Cure &Cure::operator = (const Cure & obj)
{
    this->MateriaType = obj.MateriaType;
    return (*this);
}

Cure *Cure::clone() const
{
    Cure *newCure = new Cure;
    *newCure = *this;
    return (newCure);
}

Cure::~Cure()
{
    std::cout << "Destructor Called\n";
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals "<<target.getName()<< "’s wounds *" << std::endl;
}