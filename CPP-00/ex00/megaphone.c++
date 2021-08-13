#include <iostream>

int main(int ac, char **av)
{
    int i;
    int j;

    i = 1;
    if (ac > 1)
    {
        while (av[i])
        {
            j = 0;
            while (av[i][j])
            {
                std::cout << (char)toupper(av[i][j]);
                j++;
            }
            i++;
            if (av[i])
                std::cout << ' ';
        }
    }
    else
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    std::cout << "\n";
    return (0);
}