#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound! 
    j->makeSound();
    meta->makeSound();

    //WrongAnimal Test
    const WrongAnimal* meta2 = new WrongAnimal();
    const WrongAnimal* i2 = new WrongCat();
    std::cout << "Type Animal i2 is " << i2->getType() << std::endl;
    std::cout << "Type Animal meta2 is " << meta2->getType() << std::endl;
    i2->makeSound();
    meta2->makeSound();
}



