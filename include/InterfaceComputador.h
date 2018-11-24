#ifndef INTERFACECOMPUTADOR_H
#define INTERFACECOMPUTADOR_H
#include "Interface.h"
//#include "GerenciaTempo.h"
//#include "GerenciaDisplay.cpp"

class InterfaceComputador: virtual public Interface
{
    private:
        GerenciaDisplay display;
    public:
        InterfaceComputador();
        void opcoes_maquina();
};

#endif // INTERFACECOMPUTADOR_H
