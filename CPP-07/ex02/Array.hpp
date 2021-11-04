#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <class T>
class Array
{
    public:
            Array();
            Array(unsigned int n);
            Array(const Array &obj);
            Array & operator=(const Array &obj);
            class TOHIGH: public std::exception
            {
                const char *what() const throw();
            };          
            T   &  operator[](unsigned int i)
            {
                if (i > nb)
                    throw TOHIGH();
                return this->array[i];
            }
            unsigned int    size();
    private:
            T             *array;
            unsigned int  nb;
};

template <class T>
const char *Array<T>::TOHIGH::what()const throw()
{
    return ("Array to HIGH");
}

template <typename T>
Array<T>::Array()
{
    this->nb = 0;
    this->array = NULL;
}

template<typename T>
Array<T>::Array(unsigned int n)
{
    this->nb = n;
    this->array = new T[n];
    for (unsigned int i = 0; i < nb; i++)
        this->array[i] = i;
}

template<class T>
Array<T>::Array(const Array &obj)
{
    this->nb = obj.nb;
    this->array = new T[nb];
    for (unsigned int i = 0; i < obj.nb; i++)
        this->array[i] = obj.array[i];
}

template <typename T>
Array<T> & Array<T>::operator=(const Array<T> &obj)
{
    delete []  this->array;
    array = NULL;
    this->nb = obj.nb;
    this->array = new T[nb];
    for (size_t i = 0; i < nb; i++)
        array[i] = obj.array[i];
    return (*this);
}

template <typename T>
unsigned int    Array<T>::size()
{
    return (this->nb);
}

#endif