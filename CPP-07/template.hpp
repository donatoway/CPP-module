#ifndef TEMPLATES_HPP
#define TEMPLATES_HPP

#include <iostream>

template <typename T>

void    swap(T a, T b)
{
    T tmp;
    tmp = a;
    *a = *b;
    *b = tmp;
}

#endif