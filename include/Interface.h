#ifndef INTERFACE_H
#define INTERFACE_H
#include "Refri.cpp"

class Interface
{
    public:
        Refri meet;//("Meet", 150);
        Refri etirps;//("Etirps", 150);
        int opcao; //controla as op��es da m�quina
        int liberado;
        Interface(); // construtor
        void opcoes_maquina();
};

#endif // INTERFACE_H
