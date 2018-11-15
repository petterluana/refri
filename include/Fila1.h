#ifndef FILA1_H
#define FILA1_H
#include "Node.h"

//Classe para armazenar as propagandas a serem apresentadas no display
class Fila1
{
    Node* head; //primeiro elemento da lista
    public:
        Fila1();
        ~Fila1();
        void insertAfterLast(string dat);
        string readFirst();
        string removeFirst();
        string removeNode(string dat);
        void listAll();  //Função para mostrar os elementos da lista
        bool getVazia(); //Verificar se a lista esta vazia
};

#endif // FILA1_H
