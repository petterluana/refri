#ifndef LOG_H
#define LOG_H
//#include "Node.cpp"

class Log
{
    Node* head; //primeiro elemento da lista
    public:
        Log();
        ~Log();
        void insertAfterLast(string dat);
        void listAll();  //Função para mostrar os elementos da lista
        bool getVazia(); //Verificar se a lista esta vazia
};

#endif // LOG_H
