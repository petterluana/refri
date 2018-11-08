#include <string.h>
#include <iostream>
using namespace std;

class Produtos{
    public:
	string nome;
	float valor;
	void setNome(string);
	void setValor(float);
	string getNome();
	float getValor();
};

