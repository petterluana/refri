#ifndef INTERFACERASPBERRY_H
#define INTERFACERASPBERRY_H

#include "Interface.cpp"
#include "GerenciaDisplay.cpp"

class InterfaceRaspberry: virtual public Interface
{
    private:
        GerenciaDisplay display;
    public:
        InterfaceRaspberry();    //Construtor
        void opcoes_maquina();
};

#endif // INTERFACERASPBERRY_H
