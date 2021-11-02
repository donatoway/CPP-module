#include "whatever.hpp"
/*
Scrivi i seguenti modelli di funzione:

• swap: scambia i valori di due argomenti. Non restituisce nulla.

• min: confronta i due argomenti e restituisce il più piccolo. Se i 
due argomenti sono uguali, restituisce il secondo.

• max: confronta i due argomenti e restituisce il più grande. Se i
 due argomenti sono uguali, restituisce il secondo.

I modelli devono essere definiti nei file di intestazione. Devi 
consegnare un main.cpp contenente i test per il tuo programma. 
Questo file può e verrà modificato durante la valutazione. 
Queste funzioni possono essere chiamate con qualsiasi tipo di 
argomento, a condizione che i due argomenti abbiano lo stesso tipo 
e supportino tutti gli operatori di confronto. Fornire codice 
sufficiente per compilare un eseguibile che dimostri che tutto 
funziona come previsto.
*/

int main()
{
    int a = 90;
    int b = 50;
    //TEST INT
    std::cout << "A = " << a << "\n";
    std::cout << "B = " << b << "\n";
    std::cout << "***** SWAP ******\n";
    ::swap(a,b);
    std::cout << "A = " << a << "\n";
    std::cout << "B = " << b << "\n";
    std::cout << "***** MIN ******\n";
    std::cout << "MIN = " << ::min(a,b) << "\n";
    std::cout << "***** MAX ******\n";
    std::cout << "MAX = " << ::max(a,b) << "\n\n";

    //TEST CHAR
    char c = 'a';
    char z = 'z';
    std::cout << "C = " << c << "\n";
    std::cout << "Z = " << z << "\n";
    std::cout << "***** SWAP ******\n";
    ::swap(c,z);
    std::cout << "C = " << c << "\n";
    std::cout << "Z = " << z << "\n";
    std::cout << "***** MIN ******\n";
    std::cout << "MIN = " << ::min(c,z) << "\n";
    std::cout << "***** MAX ******\n";
    std::cout << "MAX = " << ::max(c,z) << "\n\n";

    //STD::STRING

    std::string mimmo = "mimmo";
    std::string carlo = "carlo";

    std::cout << "mimmo = " << mimmo << "\n";
    std::cout << "carlo = " << carlo << "\n";
    std::cout << "***** SWAP ******\n";
    ::swap(mimmo,carlo);
    std::cout << "mimmo = " << mimmo << "\n";
    std::cout << "carlo = " << carlo << "\n";
    std::cout << "***** MIN ******\n";
    std::cout << ::min(mimmo,carlo) << "\n";
    std::cout << "***** MAX ******\n";
    std::cout << ::max(mimmo,carlo) << "\n";

}