#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <exception>
#include <array>
#include <list>

#define Green            "\e[0;32m"
#define Cyan             "\e[0;36m"
#define Red              "\e[0;31m#"
#define OFF "\033[0m"

class Error:public std::exception
{
    const char *what() const throw()
    {
        return (Red"Number not Found"OFF);
    }
};

template <typename T>
int    easyfind(T v, int n)
{
   typename T::iterator it = std::find(v.begin(),v.end(),n);
   if (it == v.end() && *it != n)
        throw Error();
   return (*it);
}

#endif