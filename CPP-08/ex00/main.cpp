#include "easyfind.hpp"

int main()
{
    std::cout << Cyan"Make your own array\nHow many element do you want ?\n";
    int num= 0;
    std::cout << OFF"Insert a number\n";
    std::cin >> num;
    int array[num];
    for (int i = 0; i < num; i++)
    {
        std::cout << "number n°" << i << "\n"; 
        std::cin >> array[i];
    }

    std::cout << "TEST VECTOR\n";
    //TEST VECTOR 
    try
    {
        int toFind;
        int n = sizeof(array)/sizeof(array[0]);
        std::vector<int>    vect(array, array + n);
        std::cout << "Choose a number and find it!\n";
        std::cin >> toFind;
        int find =  easyfind(vect,toFind);
        std::cout << Green"Number found : " << find <<OFF "\n";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "\nTEST ARRAY\n";
    try
    {
        int toFind;
        std::array<int, 4 >  arr = {1,2,3,4};
        std::cout << "std::array<int, 4 >  arr = {1,2,3,4};\n";
        std::cout << "Choose a number and find it!\n";
        std::cin >> toFind;
        int find = easyfind(arr,toFind);
        std::cout << Green"Number found : " << find << OFF"\n";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    std::cout << "\nTEST LIST\n";
    try
    {
        int toFind;
        std::cout << "List will be the same of first array\n";
        std::list<int>    lst;
        std::cout << "LIST = ";
        for (int i = 0; i < num; i++)
        {
           lst.push_back(array[i]);
           std::cout << array[i] <<" ";
        }
        std::cout << "\n";
        std::cout << "choose a number to find\n";
        std::cin >> toFind;
        int find = easyfind(lst, toFind); 
        std::cout << Green"Number found : " << find << OFF"\n";    
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    
    



    //continuare con test passando come parametro list e array e non
    //solo vettori ed aggiustare quello fatto prima

}