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
        //Interface(); // construtor
        virtual void opcoes_maquina() = 0;
};

#endif // INTERFACE_H
