#ifndef PHONE_HPP
# define PHONE_HPP
#include  <iostream>
#include <string>


class   contact
{
    public:
            int      checkCMD();
            void     PrintInit();
            int      getid();
            void     add_fun(contact *Cont, int n);
            void     get_info(contact *Cont, int n);
            void     PrintAllCont(contact Cont);
            void     PrintInfo(contact Cont[], int nb);
            void     FormatStr(std::string str);
            void     ShowInfo(contact Cont[]);
           // int      getCMD2();
            void     DisplayInfo(contact Cont[]);
            int      SetNum(contact Cont[]);
    enum
    {
        EXIT,
        ADD,
        SEARCH,
        NOT_VALID
    }       ;
    private:
            int id;
            int n;
            std::string name;
            std::string surname;
            std::string nickname;
            std::string phone;
            std::string secret;
};



#endif


