#ifndef INTERFACERASPBERRY_H
#define INTERFACERASPBERRY_H

#include "Interface.h"

class InterfaceRaspberry: virtual public Interface
{
    public:
        InterfaceRaspberry();    //Construtor
        void opcoes_maquina();
};

#endif // INTERFACERASPBERRY_H
