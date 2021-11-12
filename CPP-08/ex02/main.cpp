#include "mutantstack.hpp"

int main()
{
    //TEST SUBJECT

    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << "TOP :" << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "SIZE AFTER POP : "<< mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    std::cout << "ITERATOR : ";
    while (it != ite)
    {
        std::cout <<  *it << " ";
        ++it;
    }
    std::cout << "\n\n";

    //MAIN TEST
    std::stack<int> s(mstack);
    MutantStack<int> copyMutant(mstack);
    
    std::cout << "Copy Of Normal Stack : TOP = "<< s.top() << "\n";
    std::cout << "Copy Of Mutant Stack : TOP = "<< copyMutant.top() << "\n";

    //TEST STRING
    MutantStack<std::string> mstr;

    std::cout << "TEST WHIT STRING\n";
    mstr.push("LUISS");
    mstr.push("GUIDO");
    mstr.push("CARLI");
    MutantStack<std::string>::iterator iterator;

    for (iterator = mstr.begin(); iterator < mstr.end(); iterator++)
        std::cout << *iterator << " ";
    std::cout << "\n";

    while (!mstr.empty())
        mstr.pop();
    std::cout << "decrease using pop : size =  ";
    std::cout << mstr.size() << "\n";
}