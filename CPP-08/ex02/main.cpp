#include <iostream>
#include <stack>
#include <iterator>


/*

L' std::stack container è veramente cool, ma è l'unico di STL containers
che non è iterabile. Male. Ma perchè star bene con esso, quando
possiamo semplicemente giocarci e modellarlo ed aggiungerlo a qulache stuff 
che ci piace?

Dividerai questa abilità in std::stack container, per riparare
questa grave ingiustizia.

Crea un MutantStack class, che sarà inmpementata in termini di std::stack
e offre tutti i suoi metodi, solo questa offrirà inoòtre un iteratore.

Di seguito un esempio di codice, l'output della quale dovrebbe essere lo stesso
come se rimpiazziamo il MutantSTack con, per esempio, std::list. 

*/

template <typename T>
class MutantStack:public std::stack<T>
{
    public:
            typedef typename std::stack<T>::container_type::iterator iterator;
            iterator begin()
            {
                return (this->c.begin());
            };
            iterator end()
            {
                return (this->c.end());
            }
            //funzione iterator
};

int main()
{
   // MutantStack<int> M;

    MutantStack<std::string> stack;
    stack.push("anna");
    stack.push("carlo");
    stack.push("adriano");


    MutantStack<std::string>::iterator it;

    it = stack.begin();

    it++;
    std::cout << *it << "\n";

    //iterator fatto, continuare ad implementare la classe costruttori/copy/assign ecc
    //costruire il mainTest
}