#include "includes/phone.hpp"

int     contact::checkCMD()
{
    std::string str;
    std::getline(std::cin,str);
    if (str.compare("EXIT") == 0)
        return (EXIT);
    if (str.compare("ADD") == 0)
        return (ADD);
    if (str.compare("SEARCH") == 0)
        return (SEARCH);
    return(NOT_VALID);
}

void contact::PrintInit()
{
    std::cout << "insert Command Please" << std::endl;
}

int main()
{
    contact Cont[8];
    int ret;
    int n = 0;
    while (42)
    {
        Cont->PrintInit();
        ret = Cont->checkCMD();
        if (ret == Cont->ADD)
        {
            if (n > 7)
                n = 7;
            Cont->add_fun(&Cont[n], n);
            n++;
        }
        if (ret == Cont->SEARCH)
        {
            Cont->PrintInfo(Cont, n);
            Cont->ShowInfo(Cont);
        }
        if (ret == Cont->EXIT)
            break;    
    }
    std::cout << "bye bye" << std::endl;
    return (0);
}