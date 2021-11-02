#include "class.hpp"

Base *generate(void)
{
    int random;
    srand(time(NULL));
    random = rand() %3 + 1;

    switch (random)
    {
        case 1 : return new A;
        break;
        case 2 : return new B;
        break;
        case 3 : return new C;
        default:
        break;
    }
    return (NULL);
}

void identify(Base* p)
{
    std::cout << "********IDENTIFY WITH POINTERS********\n";
    if (dynamic_cast<A*>(p))
        std::cout << "A" << "\n";
    if (dynamic_cast<B*>(p))
        std::cout << "B" << "\n";
    if (dynamic_cast<C*>(p))
        std::cout << "C" << "\n";
}

void identify(Base& p)
{
    std::cout << "*******IDENTYFY WITH REFERENCE******\n";
    Base base;
    try
    {
        try{ base = dynamic_cast<A&>(p),std::cout << "A\n"; }
        catch(const std::exception& e){}
        try{ base = dynamic_cast<B&>(p),std::cout << "B\n"; }
        catch(const std::exception& e){}
        try{ base = dynamic_cast<C&>(p),std::cout << "C\n"; }
        catch(const std::exception& e){}
    }
    catch(const std::exception& e){}
}

int main()
{
    Base *base = generate();
    identify(base);
    identify(*base);
    delete base;
}
