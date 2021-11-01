#include <iostream>

#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define OFF "\033[0m"
#define Yellow "\e[1;33m"
#define Purple  "\e[0;35m"

struct Data
{
    int i;
    char c;
    bool b;
    void Print(std::string s);
};

void    Data::Print(std::string s)
{
    std::string color = Yellow;
    if (s.compare("Data") == 1)
        color = Purple ;
    std::cout << GREEN"PRINTED CLASS : " << s << "\n";
    std::cout << color << s <<": i = " << i << "\n";
    std::cout << s << ": c = " << c << "\n";
    std::cout << s << ": b = " << b << "\n";
}

Data* deserialize(uintptr_t raw)
{
    return (reinterpret_cast<Data*>(raw));
}

uintptr_t serialize(Data*ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
};

int main()
{
    Data *data(new Data);
    data->i = 10;
    data->c = 'c';
    data->b = true; // 1

    uintptr_t ptr_int = serialize(data); //convert *Data to int
    Data *data2 = deserialize(ptr_int); //convert ptr_int to Data

    // the address memory of data2 will be the same of data
    std::cout << GREEN"ptr_int       : " << ptr_int << "\n";
    std::cout << "Address data  : " << data << "\n";
    std::cout << "Address data2 : " << data2 << "\n\n";

    // same value in the class
    data->Print("Data");
    std::cout << "\n";
    data2->Print("Data2");
}