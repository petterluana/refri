#ifndef NODE_H
#define NODE_H
#include <iostream>
using namespace std;

class Node
{
    string valor;
    Node* next; //referencia para o pr�ximo n�
    public:
        Node(string dat, Node* nxt); //Construtor
        string getVal(); //obtem valor
        Node* getNext();
        void setVal(string dat);
        void setNext(Node* nxt); //fun��o para setar o novo n�
};

#endif // NODE_H
