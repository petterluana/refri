#include "Interface.h"
#include "Estado.cpp"
#include <iostream>
using namespace std;

Interface::Interface(){
    opcao=0;
    liberado=0;
    meet.setNome("MEET");
	meet.setValor(1.5);
	etirps.setNome("ETIRPS");
	etirps.setValor(1.5);
};

void Interface::opcoes_maquina(){
    cout << endl;
    cout << "Refrigerantes custam R$"<<meet.getValor()<< endl;
    Estado est;
    est.valor_total = 0;
    est.estado_atual = 0; //Inicia a maquina de estados
    while (liberado == 1){
        cout << endl;
        cout << "O que voce deseja:" << endl;
        cout << "\t 1 - Inserir valor" << endl;
        cout << "\t 2 - MEET " << endl;
        cout << "\t 3 - ETIRPS " << endl;
        cout << "\t 4 - Tecla DEV" << endl;
        cin >> opcao;
        switch(opcao){
        case 1:
            est.next_state();
            break;
        case 2:
            if(est.valor_total < meet.valor){
                cout << endl << "Os refrigerantes custam R$ "<< meet.getValor() << endl;
                cout << "Valor total inserido: " << est.valor_total <<endl;
                cout << "Insira mais moedas para chegar ao valor" << endl;
            }else{
                cout << endl << "Refrigerante "<< meet.getNome() <<" entregue!" << endl;
                est.valor_total = 0;
            }
            break;
        case 3:
            if(est.valor_total < etirps.valor){
                cout << endl << "Os refrigerantes custam R$ "<<etirps.getValor() << endl;
                cout << "Valor total inserido: " << est.valor_total <<endl;
                cout << "Insira mais moedas para chegar ao valor" << endl;
            }else{
                cout << endl << "Refrigerante "<<etirps.getNome()<<" entregue!" << endl;
                est.valor_total = 0;
            }
            break;
        case 4:
            est.tecla_dev();
            break;
        }
    }
}
