#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <iterator>

template <typename T>
class MutantStack:public std::stack<T>
{
    public:
            //Definizione di Iterator nella classe
            typedef typename std::stack<T>::container_type::iterator iterator;
            MutantStack(){};
            virtual ~MutantStack(){};
            MutantStack(const MutantStack &obj):std::stack<T>(obj){};
            MutantStack & operator=(const MutantStack &obj){this->c = obj.c;return *this;};
            iterator begin()
            {
                return (this->c.begin());
            };
            iterator end()
            {
                return (this->c.end());
            }
};

#endif