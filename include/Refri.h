#ifndef REFRI_H
#define REFRI_H

#include <string.h>
#include <iostream>
using namespace std;

#include "Produtos.cpp"


class Refri: public Produtos
{
    public:
        Refri();
        Refri(string, float);
};

#endif // REFRI_H
