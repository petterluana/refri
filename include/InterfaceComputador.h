#ifndef INTERFACECOMPUTADOR_H
#define INTERFACECOMPUTADOR_H
#include "Interface.h"

class InterfaceComputador: virtual public Interface
{
    public:
        InterfaceComputador();
        void opcoes_maquina();
};

#endif // INTERFACECOMPUTADOR_H
