// Disciplina: Programação de Sistemas Embarcados - UFSC 2018/02.
// Projeto Final: Vending Machine.
// Alunos: Luana Cristina Petter,  Rodrigo Wrege.
// Professor: Eduardo Augusto Bezerra.

#include "Interface.cpp"

int main()
{
    Interface tela;
    tela.liberado = 1; //Para liberar as opcoes da maquina de refrigerante
    tela.opcoes_maquina();
    return 0;
}
