#include "karen.hpp"

void  Karen::debug (void)
{
  std::cout << DEB << std::endl;
}

void  Karen::info (void)
{
  std::cout << INFO << std::endl;
}

void  Karen::warnig (void)
{
  std::cout << WARNING << std::endl;
}

void  Karen::error (void)
{
  std::cout << ERROR << std::endl;
}

void  Karen::initArray(void)
{
  this->arr[0] = &Karen::debug;
  this->arr[1] = &Karen::info;
  this->arr[2] = &Karen::warnig;
  this->arr[3] = &Karen::error;
}

void  Karen::init_level()
{
  levelArr[0] = "DEBUG";
  levelArr[1] = "INFO";
  levelArr[2] = "WARNING";
  levelArr[3] = "ERROR";
}

void Karen::complain(std::string level)
{
  int n;

  init_level();
  initArray();
  for (n = 0; n < 4; n++)
  {
    if (levelArr[n] == level)
      break;
  }
  if (n < 4)
    (this->*arr[n])();
    else
        std::cout << "[ Probably complaining about insignificant problems ]"
        << std::endl;
}