#ifndef FILA2_H
#define FILA2_H
//#include "Node.cpp"

//Classe para armazenar novas propagandas fornecidas pelo usu�rio, mas que ainda n�o est�o sendo apresentadas no display.
class Fila2
{
    Node* head; //primeiro elemento da lista
    public:
        Fila2();
        ~Fila2();
        void insertAfterLast(string dat);
        string readFirst();
        string removeFirst();
        string removeNode(string dat);
        void listAll();  //Fun��o para mostrar os elementos da lista
        bool getVazia(); //Verificar se a lista esta vazia
};

#endif // FILA2_H





