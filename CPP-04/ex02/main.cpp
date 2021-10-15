#include "AnimalBase/Animal.hpp"
#include "Brain/Brain.hpp"
#include "All-Animal/Cat.hpp"
#include "All-Animal/Dog.hpp"

int main()
{
    //the Animal class became an Abstract Class now and i
    //can declare the derived Class but not the Base class
    Cat a;
    Dog b;

    // Cat and Dog Functions
    std::cout << "DERIVED CLASS TEST\n" << std::endl;
    a.makeSound();
    b.makeSound();
    std::cout << "\n";

    // TO TEST THE ABSTRACT CLASS LEAVE COMMENTS
  /*
    Animal Abstract;
    Abstract.makeSound();
    */

}
