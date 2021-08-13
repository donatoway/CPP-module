#include "includes/phone.hpp"

void    contact::DisplayInfo(contact Cont[])
{
    std::cout << "ID: " << Cont->id + 1 << std::endl;
    std::cout << "NAME: " << Cont->name << std::endl;
    std::cout << "SURNAME: " << Cont->surname << std::endl;
    std::cout << "NICKNAME: " << Cont->nickname << std::endl;
    std::cout << "PHONE: " << Cont->phone << std::endl;
    std::cout << "SECRET: " << Cont->secret << std::endl;
}

int     contact::getid()
{
    std::string str;
    std::cout << std::endl;
    std::getline(std::cin, str);
    return (std::atoi(str.c_str()));
}

int     contact::SetNum(contact Cont[])
{
    std::cout << "insert the id :";
    int num = Cont->getid();
    num -= 1;
    if (num < n && num >= 0 && num <= 7)
    {
        DisplayInfo(&Cont[num]);
        return (0);
    }
    return (1);
}

void    contact::ShowInfo(contact Cont[])
{
    int flag = 0;
    int num;
    while (SetNum(Cont) != 0)
        std::cout << "Error: repeat please" << std::endl;
    while (flag == 0)
    {
        std::cout << "[If u want see another contact"
        " select (1) else if u want go back (2)]" << std::endl;
        num = getid();
        while (num != 1 && num != 2)
        {
            std::cout << "Error: repeat please" << std::endl;
            num = getid();
        }
        if (num == 1)
        {
            if (SetNum(Cont) != 0)
                std::cout << "Error: repeat please" << std::endl;
        }
        else
            flag = 1;
    }
    
}

void    contact::FormatStr(std::string str)
{
    unsigned long  i;
    if (str.length() > 9)
    {
        for (i = 0; i < 9; i++)
           std::cout << str[i];
        std::cout << '.';
    }
    if (str.length() < 9)
    {
        for (i = 0; i < str.length(); i++)
            std::cout << str[i];
        while (i++ < 10)
            std::cout << " ";  
    }
    if (str.length() == 9)
        std::cout << str;
    std::cout  << "|";
}

void    contact::PrintAllCont(contact Cont)
{
    std::string str_id = std::to_string(Cont.id + 1);
    std::cout << str_id ; std::cout <<  "        |";
    FormatStr(Cont.name);
    FormatStr(Cont.surname);
    FormatStr(Cont.nickname);
    std::cout << std::endl;
}

void    contact::PrintInfo(contact Cont[], int nb)
{
    n = nb;
    std::cout << "ID       |" << "NAME      |" << "SURNAME   |" << "NICKNAME  |" << std::endl;
    for (int i = 0; i < n; i++)
        PrintAllCont(Cont[i]);
}