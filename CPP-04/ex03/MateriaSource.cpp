#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    std::cout << "MateriaSource Constructor Called\n";
}

void MateriaSource::learnMateria(AMateria* materia)
{
    for (size_t i = 0; i < 4; i++)
    {
        if (list[i] == NULL)
        {
            this->list[i] = materia->clone();
            break;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (size_t i = 0; i < 4; i++)
    {
        if (this->list[i]->getType().compare(type) == 0)
            return (this->list[i]->clone());
    }
    return (0);
}

MateriaSource::~MateriaSource()
{
    std::cout << "MateriaSource destructor called\n";
    for (size_t i = 0; i < 4; i++)
    {
        if (this->list[i])
            delete list[i];
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource &obj)
{
    for (size_t i = 0; i < 4; i++)
    {
        if (obj.list[i])
            this->list[i] = obj.list[i]->clone();
    }
    return (*this);
}

MateriaSource::MateriaSource(const MateriaSource &obj)
{
    MateriaSource::operator=(obj);
}