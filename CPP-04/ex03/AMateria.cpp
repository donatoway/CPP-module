#include "AMateria.hpp"

AMateria::AMateria(std::string const & type)
{
    std::cout << "AMateria Constructtor Called\n";
    this->MateriaType = type;
}

AMateria::AMateria(const AMateria &obj)
{
    std::cout << "CopyConstructor Called\n";
    this->MateriaType = obj.MateriaType;
}

AMateria & AMateria::operator=(const AMateria &materia)
{
    this->MateriaType = materia.MateriaType;
    return (*this);
}

std::string const & AMateria::getType() const
{
    return (this->MateriaType);
};

AMateria::AMateria()
{
    std::cout << "AMateria Constructor Called\n";
}

AMateria::~AMateria()
{
    std::cout << "AMateria Destructor Called\n";
}

void AMateria::use(ICharacter& target)
{
    (void)target;
}
