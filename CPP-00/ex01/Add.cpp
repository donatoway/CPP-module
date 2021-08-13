#include "includes/phone.hpp"

void    contact::get_info(contact *cont,int n)
{
    std::string str;

    cont->id =   n;
    std::cout << "\ninsert Name: "; 
    std::getline(std::cin, str);
    cont->name = str;
    std::cout << "\ninsert Surname: ";
    std::getline(std::cin, str);
    cont->surname = str;
    std::cout << "\ninsert Nickname: "; 
    std::getline(std::cin, str);
    cont->nickname = str;
    std::cout << "\ninsert Phone: "; 
    std::getline(std::cin, str);
    cont->phone = str;
    std::cout << "\ninsert secret: "; 
    std::getline(std::cin, str);
    cont->secret = str;
}

void    contact::add_fun(contact *Cont, int n)
{
    std::cout << "insert contact n°" << n + 1 << " "
    << std::endl;
    get_info(Cont, n);
}