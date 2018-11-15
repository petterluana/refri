#include "Log.h"


Log::Log()
{
    head = 0;
}
Log::~Log(){
    Node* cursor = head;
    while(head) {
        cursor = cursor->getNext();
        delete head;
        head = cursor;
    }
    head = 0; // Officially empty
}


void Log::insertAfterLast(string dat) {
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

void Log::listAll() {
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


bool Log::getVazia(){
    return(head == NULL);
}
