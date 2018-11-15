#include "Produtos.h"

void Produtos::setNome(string name){
	nome=name;
}

void Produtos::setValor(float value){
	valor=value;
}

string Produtos::getNome(){
	return nome;
};

float Produtos::getValor(){
	return valor;
}
