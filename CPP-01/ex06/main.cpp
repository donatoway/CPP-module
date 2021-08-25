#include "karen.hpp"

int main(int ac, char **av)
{
  Karen karen;
  if (ac != 2)
  {
    std::cout << "Error: Argument" << std::endl;
    return (0);
  }
  karen.complain(av[1]);
}