#include "Bureaucrat.hpp"

int main()
{
  // 1 - Test with Increase and ToLHighException
  try
  {
    Bureaucrat mimmo("mimmo",1);

    std::cout << mimmo;
    mimmo.increase();
    std::cout << mimmo;
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
  }
  std::cout << "\n";
  // 2 - Test with Decrease and toLowExcetion
  try
  {
    Bureaucrat Berlusconi("Berlusconi",150);
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
    for (size_t i = 50; i > 1; i--)
      DiMaio.increase();
    std::cout << DiMaio;
    for (size_t i = 1; i < 150 ; i++)
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
    Bureaucrat Obama("Obama",3);
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