#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <exception>

class Error:public std::exception
{
    const char *what() const throw()
    {
        return ("Number not Found");
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