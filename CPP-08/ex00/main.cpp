#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

int main()
{
    //dichiarazione vettore
    int array[] = {1,2,3,4};
    int n = sizeof(array)/sizeof(array[0]);
    std::vector<int> vect(array,array + n);

    //dichiarazione Iteratore
    std::vector<int>::iterator iter;

    for (iter = vect.begin(); iter < vect.end(); iter++)
        std::cout << *iter << "\n";
}