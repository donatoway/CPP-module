#include "ScalarType.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout<< RED << "Wrong Arguments\n";
        return (-1);
    }
    else
    {
      Conversion Conv(av[1]);           
      if (Conv.CheckType() == true)
          std::cout << Conv;
    }
    return (0);
}