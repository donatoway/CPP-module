#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (size_t i = 0; i < 4; i++)
    {
        list[i] = NULL;
    } 
   // std::cout << "MateriaSource Constructor Called\n";
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
   // std::cout << "MateriaSource destructor called\n";
    for (size_t i = 0; i < 4; i++)
    {
        if (this->list[i])
        {
            delete list[i];
            list[i] = NULL;
        }
    }
}

MateriaSource& MateriaSource::operator=(MateriaSource &obj)
{
    for (size_t i = 0; i < 4; i++)
    {
        if (list[i] != NULL)
        {
            delete list[i];
            list[i] = NULL;
        }
    }
    
    for (size_t i = 0; i < 4; i++)
    {
            this->list[i] = obj.list[i]->clone();
    }
    return (*this);
}

MateriaSource::MateriaSource(MateriaSource &obj)
{
    MateriaSource::operator=(obj);
}