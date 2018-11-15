#include "Fila2.h"

Fila2::Fila2()
{
    head = 0;
}
Fila2::~Fila2(){
    Node* cursor = head;
    while(head) {
        cursor = cursor->getNext();
        delete head;
        head = cursor;
    }
    head = 0; // Officially empty
}


void Fila2::insertAfterLast(string dat) {
    Node* p = head;
    Node* q = head;
    if(head == 0)
        head = new Node(dat, head);
    else {
        while (q != 0) {
            p = q;
            q = p->getNext();
        }
        p->setNext(new Node(dat,0));
  }
}

void Fila2::listAll() {
    Node* aux = head;
    if(getVazia()){
        cout << "Sem registros...";
    }else{
        while(aux){
            cout << aux->getVal() << endl;
            aux = aux->getNext(); //obtem a referencia do proximo nó
                                 // assim imprime todos os elementos da lista
        }
    }
}


bool Fila2::getVazia(){
    return(head == NULL);
}

string Fila2::readFirst() {
   return head->getVal();
}

string Fila2::removeFirst() {
    string retval = "0";
    if (head != 0){
        //cout << "Removendo: " << head << endl;
        //cout << "e fica:" << head->getVal() << endl;
        retval = head->getVal();
        Node* oldHead = head;
        head = head->getNext();
        delete oldHead;
    }
    return retval;
}


string Fila2::removeNode(string dat) {
    Node* p = head;
    Node* q = head;
    string result;

    if (head == 0)
        result = "0";
    else {
        while ((q != 0) && (q->getVal() != dat)){  // Error!! the addresses will always be different!
            p = q;
            q = p->getNext();
        }
        if (q != 0) {
            if (q == head){	// it is the first node
                result = q->getVal();
                head = q->getNext();
                delete q;
            }
            else{				// the node is in the middle
                result = q->getVal();
                p->setNext(q->getNext());
                delete q;
            }
        }
        else
            result = "0";		// node not found!
    }
    return result;
}
