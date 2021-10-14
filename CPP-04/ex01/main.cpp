#include <iostream>
#include "Brain.hpp"
#include "./ClassEx00/Animal.hpp"
#include "./ClassEx00/Cat.hpp"
#include "./ClassEx00/Dog.hpp"

int main()
{
    // SUBJECT TEST
    std::cout << "TEST SUBJECT" << std::endl;
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete i;
    delete j;

    // LOOP TEST
    const Animal *AnimalArray[4];
    size_t count = 0;
    std::cout << "\n\nTEST LOOP" << std::endl;
    while (count < 2)
    {
        std::cout << "Animal n°" << count + 1 << std::endl;
        AnimalArray[count++] = new Cat;
    }
    while (count < 4)
    {
        std::cout << "Animal n°" << count + 1 << std::endl;
        AnimalArray[count++] = new Dog;
    }
    std::cout << "\nDESTRUCTOR LOOP" << std::endl;
    while (count > 0)
    {
        std::cout << "Animal n°" << count << std::endl;
        delete AnimalArray[--count];
    }
    std::cout << "\n\n";
    
    // DEEP COPYCONSTRUCTOR TEST
    std::cout << "COPYCONSTRUCTOR TEST"<< std::endl;
    std::cout << "[micio] Original Class" <<std::endl;
    Cat micio;
    std::cout << "[micio] Class Orginal Idea = Paella" <<std::endl;
    micio.setCatIdea("Paella");
    
    //to show that i will access to an attribute dinamic allocated and make a copy of micio,
    //And after i will change the attribute of micio. So copia never change!
    std::cout << "[copia] Making a copy... " << std::endl;
    Cat copia(micio);
    std::cout << "Idea of the copy :" << copia.getCatIdea() << std::endl;
    std::string str;

    std::cout << "Insert a new idea for the Original Class micio!\n";
    std::cin >> str;
    micio.setCatIdea(str);
    std::cout << "micio idea is " << micio.getCatIdea() << std::endl;
    std::cout << "copia idea is " << copia.getCatIdea() << std::endl; 
    std::cout << std::endl;
    return (0);
}