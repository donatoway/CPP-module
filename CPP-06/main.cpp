#include "ScalarType.hpp"

/*
Scrivere un programma che accetta una rappresentazione di stringa di 
un letterale C++
valore (nella sua forma più comune) come parametro. Questo letterale deve
appartengono a uno dei seguenti tipi scalari: char, int, float o
Doppio. Verrà utilizzata solo la notazione decimale.
Esempi di valori letterali char: 'c', 'a'... Per semplificare, si prega 
di notare
che: i caratteri non visualizzabili non possono essere passati come 
parametro 
al tuo programma, e se una conversione in caratteri non è visualizzabile, 
invia invece una notifica.
Esempi di valori letterali int: 0, -42, 42...
Esempi di valori letterali float: 0.0f, -4.2f, 4.2f... Potrai anche
accetta questi
anche pseudo letterali, sai, per la scienza: -inff, +inff e nanf.
Esempi di valori letterali doppi: 0.0, -4.2, 4.2... Potrai anche
accetta questi pseudo
anche letterali, sai, per divertimento: -inf, +inf e nan.
Il tuo programma deve rilevare il tipo di letterale, acquisire quel 
letterale
nel tipo giusto (quindi non è più una stringa), quindi convert
in modo esplicito a ciascuno degli altri tre tipi e visualizzare il
risultati utilizzando la stessa formattazione di seguito. Se una 
conversione lo fa
non ha senso o trabocca, mostra che la conversione è impossibile.
Puoi includere qualsiasi intestazione di cui hai bisogno per gestire 
i limiti numerici e
valori speciali.
*/

#include <limits>

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout<< RED << "Wrong Arguments\n";
        return (-1);
    }
    else
    {
      Conversion Conv(av[1]);
      if (Conv.CheckType() == true)
        std::cout << Conv;
    }

    // CONTINUARE A FARE IL CHERCK GENERALE E IMPLEMENTARE
    // CHECK SCIENCE
    return (0);
}