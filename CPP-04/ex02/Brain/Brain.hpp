#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include "../AnimalBase/Animal.hpp"

class Brain
{
    public:
            Brain();
            ~Brain();
            Brain(const Brain &obj);
            Brain & operator=(const Brain & obj);
            std::string getBrainIdea();
            void        setBrainIdea(const std::string &str);
    private:
            std::string ideas[100];
};

#endif

