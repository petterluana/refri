#include <iostream>
#include "Interface.h"
#include "InterfaceRaspberry.cpp"
#include "InterfaceComputador.cpp"

using namespace std;

int main()
{
    //Verifica se o SO � Windows
    #ifdef WIN32
        Interface* tela; //Um ponteiro que assumo a forma de interface do sistema
        tela = new InterfaceComputador();
        tela->liberado = 1; //Para liberar as opcoes da maquina de refrigerante
        tela->opcoes_maquina();
        delete tela;
    //Caso n�o for Windows o SO, significa que est� rodando no Raspbian na placa Raspberry
    #else
        Interface* tela; //Um ponteiro que assumo a forma de interface do sistema
        tela = new InterfaceRaspberry();
        tela->liberado = 1; //Para liberar as opcoes da maquina de refrigerante
        tela->opcoes_maquina();
        delete tela;
    #endif

    return 0;
}
