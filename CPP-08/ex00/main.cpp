#include "easyfind.hpp"

int main()
{
    int array[] = {50,44,33,88,99};
    int num;
    int n = sizeof(array)/sizeof(array[0]);
    std::vector<int> vect(array,array + n);

    std::cout << "Insert a number\n";
    std::cin >> num;
    try
    {
       int find =  easyfind(vect,num);
       std::cout << "Number found : " << find << "\n";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}