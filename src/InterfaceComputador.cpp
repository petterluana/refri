#include "InterfaceComputador.h"
#include "Estado.h"
#include "Log.h"
#include "Fila1.h"
#include "Fila2.h"
#include <cstdlib>
#include <iostream>
using namespace std;

InterfaceComputador::InterfaceComputador()
{
    opcao=0;
    liberado=0;
    meet.setNome("MEET");
	meet.setValor(1.5);
	etirps.setNome("ETIRPS");
	etirps.setValor(1.5);
}

void InterfaceComputador::opcoes_maquina(){
    cout << endl;
    cout << "Refrigerantes custam R$"<<meet.getValor()<< endl;
    Estado est;
    est.valor_total = 0;
    est.estado_atual = 0; //Inicia a maquina de estados
    Log pedidos; //lista que armazenara os refris comprados.
    Fila2 novaMsg; //lista que armazenara novos anuncios que ainda não são mostrados no display.
    Fila1 incluiMsg; //passará as mensagens da FILA2 para a FILA1.
    while (liberado == 1){
        cout << endl;
        cout << "O que voce deseja:" << endl;
        cout << "\t 1 - Inserir valor" << endl;
        cout << "\t 2 - MEET " << endl;
        cout << "\t 3 - ETIRPS " << endl;
        cout << "\t 4 - Tecla DEV" << endl;
        cout << "\t 5 - LOG dos pedidos" << endl;
        cout << "\t 6 - Nova mensagem de ANUNCIANTE" << endl;
        cout << "\t 7 - Colocar mensagens dos anunciantes no DISPLAY" << endl;
        cin >> opcao;
        system ("cls");
        switch(opcao){
        case 1:{
            est.next_state();
            }break;
        case 2:{
            if(est.valor_total < meet.valor){
                cout << endl << "Os refrigerantes custam R$ "<< meet.getValor() << endl;
                cout << "Valor total inserido: " << est.valor_total <<endl;
                cout << "Insira mais moedas para chegar ao valor" << endl;
            }else{
                cout << endl << "Refrigerante "<< meet.getNome() <<" entregue!" << endl;
                est.valor_total = 0;
                //guardando a informacao do pedido na lista LOG
                pedidos.insertAfterLast("MEET");
            }
            }break;
        case 3:{
            if(est.valor_total < etirps.valor){
                cout << endl << "Os refrigerantes custam R$ "<<etirps.getValor() << endl;
                cout << "Valor total inserido: " << est.valor_total <<endl;
                cout << "Insira mais moedas para chegar ao valor" << endl;
            }else{
                cout << endl << "Refrigerante "<<etirps.getNome()<<" entregue!" << endl;
                est.valor_total = 0;
                //guardando a informacao do pedido na lista LOG
                pedidos.insertAfterLast("ETIRPS");
            }
            }break;
        case 4:{
            est.tecla_dev();
            }break;
        case 5:{
            cout << endl << "LOG dos refrigerantes solicitados... "<< endl;
            pedidos.listAll(); // lista os pedidos conforme foram solicitados
            cout << endl;
            }break;
        //Inclusão de novas propagandas no sistema  --> FILA2
        case 6:{
            cout << endl << "Sistema encontra-se em ESPERA por novas mensagens..."<< endl;
            string mensagem;
            cout << endl;
            cout << endl << "ANUNCIANTE: Insira uma nova mensagem!"<< endl;
            cin >> mensagem;
            novaMsg.insertAfterLast(mensagem);
            //novaMsg.listAll();
            }break;
        //Transferência de todas as propagandas da “FILA2″, para a “FILA1″
        case 7:{
            cout << endl << "Mensagens da FILA2 enviadas para a FILA1..."<< endl;

            //PARA TESTE
            /*
            cout << endl << "Mensagens da FILA2"<< endl;
            novaMsg.listAll();
            cout << endl << "Mensagens da FILA1"<< endl;
            incluiMsg.listAll();
            cout << endl;
            int c=0;

            //Executa o laçõ até que todas as mensagens da FILA2 sejam transferidas para a FILA1
            //Removendo no Cabeçalho da Fila2 e incluindo no Fim da Fila1
            while(novaMsg.getVazia()!= true){

                //Inclui a mensagem que esta no HEAD da Fila2 no fim da Fila1...
                cout << endl;
                cout << "lendo o primeiro elemento da FILA2...";
                cout << endl << novaMsg.readFirst() <<endl;

                cout << "Inserindo no fim da FILA1...";
                incluiMsg.insertAfterLast(novaMsg.readFirst());
                cout << endl;

                //remove a mensagem do HEAD da Fila2.
                novaMsg.removeFirst();

                c=c+1;
            }
            cout << "contador " << c <<endl;

            cout << endl << "Mensagens da FILA2"<< endl;
            novaMsg.listAll();
            cout << endl << "Mensagens da FILA1"<< endl;
            incluiMsg.listAll();*/


            cout << endl << "Mensagens da FILA2"<< endl;
            novaMsg.listAll();
            cout << endl << "Mensagens da FILA1"<< endl;
            incluiMsg.listAll();
            cout << endl;
            cout << endl << "EXECUTANDO A TRANSFERENCIA"<< endl;
            cout << endl;
            //Executa o laçõ até que todas as mensagens da FILA2 sejam transferidas para a FILA1
            //Removendo no Cabeçalho da Fila2 e incluindo no Fim da Fila1
            while(novaMsg.getVazia()!= true){
                //Inclui a mensagem que esta no HEAD da Fila2 no fim da Fila1...
                incluiMsg.insertAfterLast(novaMsg.readFirst());
                //remove a mensagem do HEAD da Fila2.
                novaMsg.removeFirst();
            }

            cout << endl << "Mensagens da FILA2"<< endl;
            novaMsg.listAll();
            cout << endl << "Mensagens da FILA1"<< endl;
            incluiMsg.listAll();


            }break;
        }
    }

}
