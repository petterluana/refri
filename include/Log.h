#ifndef LOG_H
#define LOG_H
#include "Node.h"

class Log
{
    Node* head; //primeiro elemento da lista
    public:
        Log();
        ~Log();
        void insertAfterLast(string dat);
        void listAll();  //Fun��o para mostrar os elementos da lista
        bool getVazia(); //Verificar se a lista esta vazia
};

#endif // LOG_H
