#include "Bureaucrat.hpp"

int main()
{
  // 1 - Test with Increase and ToLowException
  try
  {
    Bureaucrat mimmo("mimmo",150);

    std::cout << mimmo;
    mimmo.increase();
    std::cout << mimmo;
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
  }
  std::cout << "\n";
  // 2 - Test with Decrease and toHighExcetion
  try
  {
    Bureaucrat Berlusconi("Berlusconi",1);
    std::cout << Berlusconi;
    Berlusconi.decrease();
    std::cout << Berlusconi;
    
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
  }
  // 3 - Test with Invalid Constructor less than 1
  std::cout << "\n";
  try
  {
    Bureaucrat Salvini("Salvini",0);
    std::cout << "RUSPAGETOR\n";
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
  }
  std::cout << "\n";
  // 4 - Test with Invalid Constructor greater than 150
  try
  {
    Bureaucrat Meloni("Meloni",151);
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
  }
  std::cout << "\n";
  // 5 - Test Normal increase/decrease
  try
  {
    Bureaucrat DiMaio("DiMaio",50);
    for (size_t i = 0; i < 50; i++)
      DiMaio.increase();
    std::cout << DiMaio;
    for (size_t i = 100; i > 80; i--)
      DiMaio.decrease();
    std::cout << DiMaio;
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
  }
  std::cout << "\n";
  // 6 - Test Increasing in For cicle
  try
  {
    Bureaucrat Obama("Obama",148);
    for (int i = 0; i < 10; i++)
    {
      std::cout << Obama;
       Obama.increase();
    }
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
  }
  std::cout << "\n";
  return (0);
}