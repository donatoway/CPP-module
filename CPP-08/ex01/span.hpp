#pragma once

#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include <algorithm>
#include <exception>
#include <random>
#include <cmath>

class Span
{
    public:
            Span();
            Span(unsigned int n);
            ~Span();
            Span(const Span &obj);
            Span    & operator = (const Span &obj);
            void    addNumber(int nb);
            void    PrintVect();
            int     longestSpan();
            int     shortestSpan();
            class   ToLess:public std::exception
            {
                const char *what() const throw();
            };
            class   Full:public std::exception
            {
                const char *what() const throw();
            };
            
    private:
            std::vector<int>    vect;
            unsigned int total_integers;
};