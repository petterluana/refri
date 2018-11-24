#include <iostream>
#include "Interface.h"
#include "InterfaceRaspberry.cpp"
#include "InterfaceComputador.cpp"

using namespace std;

int main()
{
    //Verifica se o SO é Windows
    #ifdef WIN32
        Interface* tela; //Um ponteiro que assumo a forma de interface do sistema
        tela = new InterfaceComputador();
        tela->liberado = 1; //Para liberar as opcoes da maquina de refrigerante
        tela->opcoes_maquina();
        delete tela;
    //Caso não for Windows o SO, significa que está rodando no Raspbian na placa Raspberry
    #else
        Interface* tela; //Um ponteiro que assumo a forma de interface do sistema
        tela = new InterfaceRaspberry();
        tela->liberado = 1; //Para liberar as opcoes da maquina de refrigerante
        tela->opcoes_maquina();
        delete tela;
    #endif

    return 0;
}
