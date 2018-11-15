#include "Node.h"

//Construtor
Node::Node(string dat, Node* nxt){
       valor = dat;
       next = nxt;
}

string Node::getVal(){
     return valor;
}

Node* Node::getNext(){
     return next;
}


void Node::setVal(string dat){
     valor = dat;
}


void Node::setNext(Node* nxt){
       next = nxt;
}
