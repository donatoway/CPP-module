#include <iostream>
#include <fstream>
#include <string>

/*
1)  Crea un programma chiamato replace che prende in input un filename e 2 stringhe chiamali
    s1 ed s2 che non siano vuote
2)  il programma apre il filename e ci scriverà il filename.replace rimpiazzando
    ogni occorrenza di s1 con s2
*/

void    checkError(int ac)
{
   if (ac != 4)
    {
        std::cout << "Wrong number of Argument" <<std::endl;
        exit(1);
    } 
}

int     str_compare(std::string s1, char *str)
{
    int i = 0;
    while (str[i])
    {
        if (str[i] != s1[i])
            return (1);
        i++;
    }
    return (0);
}

void    checkError2(std::string s1, std::string s2)
{
    if (s1.length() < 1 || s2.length() < 1)
    {
        std::cout << "Error: string lenght " << std::endl;
        exit (1);
    } 
}


int main(int ac, char **av)
{
    std::string s1;
    std::string s2;
    std::string filename;
    std::string text;
    std::string buff;
    std::ifstream fileIN;
    std::ofstream fileOUT;

    char str[100000];

    checkError(ac);
    filename = av[1];
    s1 = av[2];
    s2 = av[3];
    checkError2(s1,s2);
    fileIN.open(filename);

    while (getline(fileIN, buff))
        text.append(buff + '\n');
    fileIN.close();

    for (size_t i = 0; i < text.length(); i++)
    {
        int j = 0;
        while (text[i] != ' ' && text[i] != '\n')
            str[j++] = text[i++];
        str[j] = '\0';
        if (j > 0)
        {
            i--;
            if (str_compare(s1, str) == 0)
                text.replace(i + 1 - j, s1.length(), s2);
        }
    }
    filename = filename.append(".replace");
    fileOUT.open(filename);
    fileOUT << text;
    fileOUT.close();
}