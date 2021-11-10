#include "span.hpp"

int main()
{
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
}