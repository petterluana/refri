#include "InterfaceComputador.h"

InterfaceComputador::InterfaceComputador()
{
    liberado=0;
}

void InterfaceComputador::opcoes_maquina(){
    while (liberado == 1){
        display.exibirMsg();
    }
}
