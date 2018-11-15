#ifndef INTERFACE_H
#define INTERFACE_H

#include "Refri.h"

class Interface
{
    public:
        Refri meet;//("Meet", 150);
        Refri etirps;//("Etirps", 150);
        int opcao; //controla as opções da máquina
        int liberado;
        //Interface(); // construtor
        virtual void opcoes_maquina() = 0;
};

#endif // INTERFACE_H
