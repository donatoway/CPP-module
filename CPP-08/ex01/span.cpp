#include "span.hpp"

Span::Span(){};

Span::~Span(){};

Span::Span(const Span &obj)
{
    *this = obj;
}

Span    &   Span::operator=(const Span & obj)
{
    this->total_integers = obj.total_integers;
    this->vect = obj.vect;
    return (*this);
}

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

const char *   Span::Full::what() const throw()
{
    return ("Exception: Full Numbers");
}

const char *    Span::ToLess::what()const throw()
{
    return ("Exception: Not Enough Number");
}