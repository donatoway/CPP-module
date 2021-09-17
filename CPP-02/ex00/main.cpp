#include "Fixed.hpp"

/*--------------  POLIMORFISMO -----------------
La parola polimorfismo significa avere molte forme. In parole semplici, possiamo definire il
polimorfismo come la capacità di un messaggio di essere visualizzato in più di una forma.
Un esempio reale di polimorfismo :  una persona allo stesso tempo può avere caratteristiche
diverse. Come un uomo allo stesso tempo è un padre, un marito, un impiegato. Quindi la stessa
persona ha un comportamento diverso in situazioni diverse. Questo si chiama polimorfismo.
Il polimorfismo è considerato una delle caratteristiche importanti della programmazione 
orientata agli oggetti.

---------------- FUNCTION OVERLOADING ----------------------
quando ci sono più funzioni con lo stesso nome ma parametri diversi, si 
dice che queste funzioni sono sovraccaricate(overloading) . Le funzioni possono essere 
sovraccaricate modificando il numero di argomenti o/e modificando il tipo di argomenti .

----------------- OPERATOR OVERLOADING ---------------------
Sovraccarico degli operatori : C++ fornisce anche l'opzione per sovraccaricare gli operatori.
Ad esempio, possiamo fare in modo che l'operatore ('+') per la classe stringa concateni due
stringhe.Sappiamo che questo è l'operatore di addizione il cui compito è aggiungere due 
operandi. Quindi un singolo operatore '+' quando posizionato tra operandi interi,
li aggiunge e quando viene posizionato tra operandi stringa, li concatena.

----------------- CopyCostructor ----------------------------
Un copyCostructor è una member function che inizializza un oggetto utilzzando
un'altro oggetto della stessa classe, il copyCostructor ha generalmente il seguente prototipo:

        -- NameClass (const NameClass &oldObj);

----------------- Assignation Overloading -------------------
Puoi sovraccaricare l'operatore di assegnazione (=) proprio come puoi fare con altri operatori
e può essere usato per creare un oggetto proprio come il costruttore di copie.
        Fixed& operator = (const Fixed &OldObj);
la diffrenza con il costruttore di copie è che il costruttore di copie crea una copia identica
mentre l'assignation Overloading può modificare il contenuto.
*/

int main()
{
    Fixed a;
    Fixed b(a);
    Fixed c;

    c = b;
    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;
}
   