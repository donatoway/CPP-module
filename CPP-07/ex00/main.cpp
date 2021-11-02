#include "whatever.hpp"

int main()
{
    int a = 90;
    int b = 50;
    //TEST INT
    std::cout << "A = " << a << "\n";
    std::cout << "B = " << b << "\n";
    std::cout << "***** SWAP ******\n";
    ::swap(a,b);
    std::cout << "A = " << a << "\n";
    std::cout << "B = " << b << "\n";
    std::cout << "***** MIN ******\n";
    std::cout << "MIN = " << ::min(a,b) << "\n";
    std::cout << "***** MAX ******\n";
    std::cout << "MAX = " << ::max(a,b) << "\n\n";

    //TEST CHAR
    char c = 'a';
    char z = 'z';
    std::cout << "C = " << c << "\n";
    std::cout << "Z = " << z << "\n";
    std::cout << "***** SWAP ******\n";
    ::swap(c,z);
    std::cout << "C = " << c << "\n";
    std::cout << "Z = " << z << "\n";
    std::cout << "***** MIN ******\n";
    std::cout << "MIN = " << ::min(c,z) << "\n";
    std::cout << "***** MAX ******\n";
    std::cout << "MAX = " << ::max(c,z) << "\n\n";

    //STD::STRING

    std::string mimmo = "mimmo";
    std::string carlo = "carlo";

    std::cout << "mimmo = " << mimmo << "\n";
    std::cout << "carlo = " << carlo << "\n";
    std::cout << "***** SWAP ******\n";
    ::swap(mimmo,carlo);
    std::cout << "mimmo = " << mimmo << "\n";
    std::cout << "carlo = " << carlo << "\n";
    std::cout << "***** MIN ******\n";
    std::cout << ::min(mimmo,carlo) << "\n";
    std::cout << "***** MAX ******\n";
    std::cout << ::max(mimmo,carlo) << "\n";

}