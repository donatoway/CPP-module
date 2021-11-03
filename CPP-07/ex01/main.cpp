#include "iter.hpp"

template <typename T>
void    print(T &element)
{
    std::cout << element << " ";
}

int main()
{
    //int
    int num[5] = {1,2,3,4,5};
    ::iter(num,5,::print);
    std::cout << "\n";
    //float
    float f[6] = {1.3f,2.4f,3.5f,4.6f,5.7f,6.8f};
    ::iter(f,6,print);
    std::cout << "\n";
    //double
    double d[9] = {1.5,2.5,3.5,4.5,5.2,6.1,7.9,8.3,9.0};
    ::iter(d,9,print);
    std::cout << "\n";
    //char
    char c[5] = {'a','b','c','d','e'};
    ::iter(c,5,print);
    std::cout << "\n";
    //string
    std::string str[3] = {"aldo","giovanni","giacomo"};
    ::iter(str,3,print);
    std::cout << "\n";
}