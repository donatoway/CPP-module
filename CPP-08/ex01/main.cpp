#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include <algorithm>
#include <exception>

/*
Crea una classe in cui puoi memorizzare N int. N sarà un int senza 
segno e verrà passato al costruttore come unico parametro.

Questa classe avrà una funzione per memorizzare un singolo numero 
(addNumber), che verrà utilizzato per riempirlo. Il tentativo di 
aggiungere un nuovo numero se ne sono già presenti N memorizzati 
nell'oggetto è un errore e dovrebbe generare un'eccezione.

Ora creerai due funzioni, shortestSpan e longestSpan, che scopriranno 
rispettivamente l'intervallo più breve e più lungo tra tutti i numeri 
contenuti nell'oggetto e lo restituiranno. Se non ci sono numeri 
memorizzati, o solo uno, non c'è intervallo da trovare e verrà 
generata un'eccezione.

Di seguito è riportato un esempio (troppo breve) di un test principale 
e del relativo output associato. Naturalmente, il tuo principale sarà 
molto più approfondito di questo. Devi testare almeno con 10000 numeri.
Più sarebbe una buona cosa. Sarebbe anche molto buono se tu potessi
aggiungere numeri passando una serie di iteratori, che eviterebbe il 
fastidio di fare migliaia di chiamate per addNumber...
*/

class Span
{
    public:
            Span(unsigned int n);
            void    addNumber(int nb);
            void    PrintVect();
            int     longestSpan();
            int     shortestSpan();
            class   ToLess:public std::exception
            {
                const char *what() const throw()
                {
                    return ("Exception: Not Enough Number");
                }
            };
            class   Full:public std::exception
            {
                const char *what() const throw()
                {
                    return ("Exception: Full Numbers");
                }
            };
            
    private:
            std::vector<int>    vect;
            unsigned int total_integers;

};

Span::Span(unsigned int n)
{
    total_integers = n;
}

void    Span::addNumber(int nb)
{
    if (vect.size() < total_integers)
        this->vect.push_back(nb);
    else
        throw Full();
};

int    Span::longestSpan()
{
    if (this->total_integers < 2)
        throw ToLess();    
    int max = *std::max_element(vect.begin(),vect.end());
    int min = *std::min_element(vect.begin(),vect.end());
    return (max - min);
}

int    Span::shortestSpan()
{
    if (this->total_integers < 2)
        throw ToLess();
    unsigned int min = 2147483647;
    std::vector<int>    copy = this->vect;
    std::sort(copy.begin(),copy.end());
    for (int i = 0; i < this->total_integers - 1; i++)
    {
        if (copy[i + 1] - copy[i] < min)
            min = copy[i + 1] - copy[i];
    }
    return (min);
}

void    Span::PrintVect()
{
    for (size_t i = 0; i < vect.size(); i++)
        std::cout << vect[i] << " ";
    std::cout << "\n";
};

int main()
{
    Span sp(5);

try
{
    sp.addNumber(-4);
    sp.addNumber(-0);
    sp.addNumber(-2);
    sp.addNumber(99);
    sp.addNumber(-5);
   // sp.PrintVect();
    std::cout << sp.longestSpan() << "\n";
    std::cout << sp.shortestSpan()<< "\n";
}
catch(const std::exception& e)
{
    std::cerr << e.what() << '\n';
}

    //continuare a finalizzare le exception e creare i test
}