#include "Fixed.hpp"



/*
    Prendi la classe precedente ed aggiungi le seguenti public function e public constructor
    alla tua classe
    - un costruttore che prende una costante intera come parametro e la converte nel corrispondente 
        fixed(8) point value. I bit frazionari sono inizializzati come in ex00
    - una costruttore che prende una costante floating point come parametro e che lo converte nel corrispondente
        fixed(8) point value . I bit frazionari sono inizializzati come nell'ex00
    - una member function < float toFloat(void) const > che converte il fixed point value in floating point value.
    - una member function < int toInt (void) const che converte il fixed point value in un intero.
    - dovrai anche aggiungere le seguenti funzioni overload al tuo header (declaration) e source (definition) files
        - un overload all'operatore << che inserisce una rappresentazione del floating point di fixed point value nel parametro output stream
    
*/

    // continuare a studiare lo shift operator https://docs.microsoft.com/en-us/cpp/standard-library/overloading-the-output-operator-for-your-own-classes?view=msvc-160
//-------------- Shift Left ------------------------------------

/*l'operatore << lavora in binario, prende 2 numeri e sposta a sinistra i bit del primo operando, il secondo 
     operando invece decide di quanti bit spostarsi, Le posizioni dei bit che sono state lasciate libere 
     dall'operazione di spostamento vengono riempite con zero
Esempio:
{
    int a = 1, b = 3;
        // a ora è 00000001;
    a = a << 3;
         // applicando lo shift-left spostera
         // i bit di 3 posizioni 00001000, risultato = 8;
    Cio equivale all'operazione a = 1 * (2 * 2 * 2)
}
- non è possibile spostare un numero maggiore della dimensione dell'intero 32.
- il numero di posizione dei bit da spostare deve essere positivo 
*/


    //sposto di n°BitFractional i bit in integer, quindi (integer * (2^8))
Fixed::Fixed(const int integer)
{
    std::cout << "Int Constructor Called" << std::endl;
    this->FixedValue = integer << this->BitFractional;
}

    //sposto di n°BitFractional i bit in number ed arrotondo il risultato
Fixed::Fixed(const float number)
{
    std::cout << "Float Constructor Called" << std::endl;
    this->FixedValue = roundf(number * (1 << this->BitFractional));
}

    //per riottenere l'intero usiamo l'operazione inversa, quindi
    //dividiamo il FixedValue per (2^8)
int Fixed::toInt( void ) const
{
    return  (this->FixedValue / (1 << this->BitFractional));
}

    //per riottenere il float number divido il Float(FixedValue) per
    //(2^8)
float Fixed::toFloat(void)const
{
    return (float(FixedValue) / (1 << this->BitFractional));
}

std::ostream&   operator << (std::ostream& stream, const Fixed& obj)
{
        return (stream << obj.toFloat());
}

int main()
{
    Fixed a;

    a = Fixed( 1234.4321f );
    std::cout << "a is " << a << std::endl;

}