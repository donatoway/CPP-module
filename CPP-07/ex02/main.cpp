#include "Array.hpp"

int main()
{
    Array<int> array1(4);
    Array<char> array2(5);
    Array<double> array3(2);
    //TEST INT
    try
    {
        std::cout << "TEST INT : ";
        for (size_t i = 0; i < array1.size(); i++)
        {
            array1[i] = i;
            std::cout << array1[i] << " ";
        }
        std::cout << "size -> " << array1.size() << "\n";
        std::cout << "TEST CHAR : ";
        char c = 'a';
        for (size_t i = 0; i < array2.size(); i++)
        {
            array2[i] = c++;
            std::cout << array2[i] << " ";
        }
        std::cout << "size -> " << array2.size() << "\nTEST DOUBLE : ";
        array3[0] = 10.5;
        array3[1] = 88.88;
        std::cout << array3[0] << " ";
        std::cout << array3[1] << " "; 
        std::cout << "size -> " << array3.size() << "\n";

        // array int [] UP whit exception
        std::cout << "TEST INT ARRAY TO HIGH : ";
        array2[10] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    // TEST COPYCONSTRUCTOR
    Array<int> copy(array1);
    std::cout << "TEST COPYCONSTRUCTOR : ";
    for (size_t i = 0; i < copy.size(); i++)
         std::cout << copy[i] << " ";
    std::cout << "\n";
    // TEST ASSIGNATION
    Array<char> assign = array2;
    std::cout << "TEST ASSIGNATION : ";
    for (size_t i = 0; i < assign.size(); i++)
         std::cout << assign[i] << " ";
    std::cout << "\n";

    // TEST NO VALUE CHANGE AFTER COPY
    copy[0] = 777;
    assign[0] ='z';
    std::cout << "TEST NO VALUE CHANGE AFTER BE COPIED : copy =";
    std::cout << copy[0] << ", array1 = ";
    std::cout << array1[0] << ", assign = "<< assign[0] << ", array2 = "
    << array2[0] << "\n";
}