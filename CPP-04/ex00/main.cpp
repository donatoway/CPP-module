#include <iostream>

/*
    Per ogni esercizio dovresti Testare tutto!
    Il Costruttore e Distruttore di ogni Classe dovrebbe avere specifici Outputs.
    Crea una Semplice e completa Base Class Animal.
    -L' Animal Class ha un Protected Attribute: std::string type

    - Crea una Classe Dog che eredita da Animal.
    - Crea una Classe Cat che eredita da Animal.
        (per l'animal class il tipo potrà essere vuoto o settato a qualsiasi valore)
    Ogni Classe dovrà mettere il suo Type field esempio:
   - La Classe Dog Type sarà inizializzato come "Dog".
    Ogni Animale dovrà poter utilizzare il metodo makesound().
    Questo metodo stamperà un appropriato messaggio sullo standard outputs basato sulla classe.

    int main()
    {
        const Animal* meta = new Animal(); const Animal* j = new Dog();
        const Animal* i = new Cat();
        std::cout << j->getType() << " " << std::endl; std::cout << i->getType() << " " << std::endl; i->makeSound(); //will output the cat sound! j->makeSound();
        meta->makeSound();
        ...
    }
    questo Dovrebbe stampare lo specifico MakeSound di Dog e Cat Class non del singolo animale.
    Per Essere Sicuri creerai una WrongCat class che erediterà da WrongAnimal Class che stamperà l'output di WrongAnimal makeSound()
    quando testato sotto le stesse condizioni
    P
*/

class Animal
{
    public:
            Animal();
            virtual ~Animal();
            virtual std::string    getType()const;
            virtual void    makeSound()const;
    protected:
            std::string Type;
};

class Dog: public Animal
{
    public:
            Dog();
            virtual ~Dog();

            std::string getType()const;
            void    makeSound()const;
    protected:
            std::string Type;
};

class Cat: public Animal
{
    public:
            Cat();
            virtual ~Cat();
            std::string getType()const;
            void    makeSound()const;
    protected:
            std::string Type;
};

Animal::Animal()
{
    std::cout << "Animal Constructor Called " << std::endl;
    this->Type = "Animal";
}

Animal::~Animal()
{
    std::cout << "Animal Destructor Called" << std::endl;
}

void    Animal::makeSound()const
{
    std::cout << "This Animal no have any sound" << std::endl;
}

std::string Animal::getType()const
{
    return (this->Type);
}

Dog::Dog()
{
    std::cout << "Dog Constructor Called" << std::endl;
    this->Type = "Dog";
}

std::string Dog::getType()const
{
    return (this->Type);
}

Dog::~Dog()
{
    std::cout << "Dog Destructor Called" << std::endl;
}

Cat::Cat()
{
    std::cout << "cat Constructor Called" << std::endl;
    this->Type = "Cat";
}

Cat::~Cat()
{
    std::cout << "Cat Destructor Called" << std::endl;

}

void    Cat::makeSound()const
{
    std::cout << "The " << this->Type << " Sound is " << " Miao!\n";
}

void    Dog::makeSound()const
{
    std::cout << "The " << this->Type << " Sound is " << " Bau Bau!\n";
}

std::string Cat::getType()const
{
    return (this->Type);
}


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

        //Ricominciare a vedere bene le funzioni Virtual
        // Rileggere il subject e farlo bene passo passo
        // arrivato fino alla creazioni delle 3 classi
        // e le funzioni interne ma non sono controllate
        // e testate . Reiniziare da 0.

}



