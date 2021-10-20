#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
    public:
            MateriaSource();
            MateriaSource(MateriaSource &obj);
            MateriaSource    &  operator= (MateriaSource &obj);
            ~MateriaSource();
            void        learnMateria(AMateria*);
            AMateria*   createMateria(std::string const & type);
    private:
            AMateria *list[4];
};

#endif