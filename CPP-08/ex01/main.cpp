#include "span.hpp"

/*
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
*/
/*
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
*/

int main()
{
    /*
	int n;
	std::cout << "How many numbers do you want in your array?\n";
	std::cin >> n;
    n = std::abs(n);
	Span sp(n);
	try
	{
		std::cout << "\nTEST 1 to "<<n<<"\n";
		for (size_t i = 1; i <= n; i++)
			sp.addNumber(i);
		std::cout << "longestSpan: "<< sp.longestSpan()<< "\n";
		std::cout << "shortestSpan: "<< sp.shortestSpan()<< "\n";
		std::cout << "TEST FULL SPAN + 1\n";
		sp.addNumber(1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}	

    //RANDOM TEST
    Span sp2(5);
    int random;
    srand(time(NULL));

    try
    {
        std::cout << "\nRANDOM TEST\n";
        for (size_t i = 0; i < 5; i++)
            sp2.addNumber(random = rand() % 100 + 1);
        sp2.PrintVect();
        std::cout << "longest span " << sp2.longestSpan()<< "\n";
        std::cout << "shortest span " << sp2.shortestSpan()<< "\n";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    */
   Span sp(3);

   sp.addNumber(1);
   sp.addNumber(2);
   sp.addNumber(3);

   Span sp2(sp);

   sp2.PrintVect(); 
}