#ifndef REFRI_H_INCLUDED
#define REFRI_H_INCLUDED
#include "Produtos.cpp"
#include <string.h>
#include <iostream>
using namespace std;

class Refri: public Produtos{
    public:
	Refri();
	Refri(string, float);
};



#endif // REFRI_H_INCLUDED
