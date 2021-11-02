#ifndef CLASS_HPP
#define CLASS_HPP
#include <iostream>
#include <cmath>

class Base
{
    public:
            virtual ~Base(){};
};

class A:public Base{};
class B:public Base{};
class C:public Base{};

#endif