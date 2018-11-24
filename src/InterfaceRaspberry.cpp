#include "InterfaceRaspberry.h"

using namespace std;

InterfaceRaspberry::InterfaceRaspberry()
{
    liberado=0;
}


void InterfaceRaspberry::opcoes_maquina(){
    while (liberado == 1){
        display.exibirMsg();
    }
}
