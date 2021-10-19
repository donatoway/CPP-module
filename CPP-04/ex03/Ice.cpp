#include "AMateria.hpp"
#include "Ice.hpp"

Ice::Ice():AMateria("ice")
{
    this->MateriaType = "ice";
    std::cout << "Ice Constructor Called\n";
}

Ice::Ice(const Ice & obj)
{
    this->MateriaType = obj.MateriaType;
}


Ice::~Ice()
{
    std::cout << "Ice Destructor Called\n";
}

Ice& Ice::operator=(const Ice & obj)
{
    this->MateriaType = obj.MateriaType;
    return (*this);
}

Ice* Ice::clone() const
{
    Ice *newIce = new Ice;
    *newIce = *this;
    return (newIce);
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}