#include "GerenciaDisplay.h"
#include <iostream>
using namespace std;
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <cstdlib>
#include <ctime>

GerenciaDisplay::GerenciaDisplay(){
    meet.setNome("MEET");
	meet.setValor(1.5);
	etirps.setNome("ETIRPS");
	etirps.setValor(1.5);
}

void GerenciaDisplay::exibirMsg(){

    while(1){
        do{
            if(tecla == '0'){
                //SORTEIA quantas mensagens exibir(de 3 a 6 serão exibidas) para apresentar a data/hora
                if(sorteio==1){
                    srand((unsigned)time(0)); //para gerar números aleatórios reais.
                    int maior = 6;
                    int menor = 3;
                    aleatorio = rand()%(maior-menor+1) + menor;
                    //cout <<"sorteado "<< aleatorio<<endl;
                    sorteio=0;
                    anunc=1;
                    Sleep(65);
                }

                //Se chegou na vez de exibir a hora
                if(cont==aleatorio){
                    totaltempo = 5*60;
                    cout << endl << "DISPLAY" <<endl;
                    cout <<"----------------------------------------------------"<<endl;
                    dt_hr.data_hora();
                    cout <<"----------------------------------------------------"<<endl;
                    //indica que deve ver quantas msg serão exibidas pra mostrar a hora depois
                    anunc=0;
                    sorteio=1;
                    cont=0;
                }

                //Apresenta as mensagens no display
                if((anunc==1)&&(msg!=0)){ //a variavel MSG Para saber que já foi transferida alguma msg da Fila2 para a Fila1
                    totaltempo = 10*60;
                    //Apresenta a msg durante 10 segundos e muda
                    cout << endl << "DISPLAY" <<endl;
                    cout <<"----------------------------------------------------"<<endl;
                    anuncio=incluiMsg.readFirst();
                    cout<< anuncio;
                    cout <<endl<<"----------------------------------------------------"<<endl;
                    //Sleep(360);
                    //Inclui a mensagem que esta no HEAD da Fila1 no fim da Fila1...
                    incluiMsg.insertAfterLast(anuncio);
                    //remove a mensagem do HEAD da Fila1 pois já foi inserida no fim da fila.
                    incluiMsg.removeNode(anuncio);
                    cont = cont+1;
                }

                //Se não tem msg pra exibir no display (FILA1 VAZIA) fica mostrando a data/hora
                if(incluiMsg.getVazia()==1){
                    totaltempo = 5*60;
                    cout << endl << "DISPLAY" <<endl;
                    cout <<"----------------------------------------------------"<<endl;
                    dt_hr.data_hora();
                    cout <<"----------------------------------------------------"<<endl;
                }

                cout << "O que voce deseja:" << endl;
                cout << "\t 1 - Inserir valor" << endl;
                cout << "\t 2 - MEET " << endl;
                cout << "\t 3 - ETIRPS " << endl;
                cout << "\t 4 - Tecla DEV" << endl;
                cout << "\t 5 - LOG dos pedidos" << endl;
                cout << "\t 6 - Nova mensagem de ANUNCIANTE" << endl;
                cout << "\t 7 - Colocar mensagens dos anunciantes no DISPLAY" << endl;
                cout << "\t 8 - Apagar ANUNCIO" << endl;
                Sleep(totaltempo);
                system("cls");
            }
            //Se alguma tecla for pressionada
            if(kbhit()){
                tecla = getch();
                switch(tecla){
                    case '1':{
                        est.next_state();
                        Sleep(3600);
                        tecla = '0'; //Para o Sistema saber que não foi pressionada nada
                        system("cls");
                        }break;
                    case '2':{
                        if(est.valor_total < meet.valor){
                            cout << endl << "DISPLAY" <<endl;
                            cout <<"----------------------------------------------------";
                            cout << endl << "Os refrigerantes custam R$ "<< meet.getValor() << endl;
                            cout << "Valor total inserido: " << est.valor_total <<endl;
                            cout << "Insira mais moedas para chegar ao valor" << endl;
                            cout <<"----------------------------------------------------"<<endl;
                        }else{
                            cout << endl << "DISPLAY" <<endl;
                            cout <<"----------------------------------------------------";
                            cout << endl << "Refrigerante "<< meet.getNome() <<" entregue!" << endl;
                            est.valor_total = 0;
                            //guardando a informacao do pedido na lista LOG
                            pedidos.insertAfterLast("MEET");
                            cout <<"----------------------------------------------------"<<endl;
                        }
                        Sleep(3600);
                        tecla = '0'; //Para o Sistema saber que não foi pressionada nada
                        system("cls");
                        }break;
                    case '3':{
                        if(est.valor_total < etirps.valor){
                            cout << endl << "DISPLAY" <<endl;
                            cout <<"----------------------------------------------------";
                            cout << endl << "Os refrigerantes custam R$ "<<etirps.getValor() << endl;
                            cout << "Valor total inserido: " << est.valor_total <<endl;
                            cout << "Insira mais moedas para chegar ao valor" << endl;
                            cout <<"----------------------------------------------------"<<endl;
                        }else{
                            cout << endl << "DISPLAY" <<endl;
                            cout <<"----------------------------------------------------";
                            cout << endl << "Refrigerante "<<etirps.getNome()<<" entregue!" << endl;
                            est.valor_total = 0;
                            //guardando a informacao do pedido na lista LOG
                            pedidos.insertAfterLast("ETIRPS");
                            cout <<"----------------------------------------------------"<<endl;
                        }
                        Sleep(3600);
                        tecla = '0'; //Para o Sistema saber que não foi pressionada nada
                        system("cls");
                        }break;
                    case '4':{
                        cout << endl << "DISPLAY" <<endl;
                        cout <<"----------------------------------------------------";
                        est.tecla_dev();
                        cout <<"----------------------------------------------------"<<endl;
                        Sleep(3600);
                        tecla = '0'; //Para o Sistema saber que não foi pressionada nada
                        system("cls");
                        }break;
                    case '5':{
                        cout << endl << "DISPLAY" <<endl;
                        cout <<"----------------------------------------------------";
                        cout << endl << "LOG dos refrigerantes solicitados... "<< endl;
                        pedidos.listAll(); // lista os pedidos conforme foram solicitados
                        cout <<endl << "----------------------------------------------------"<<endl;
                        cout << endl;
                        Sleep(3600);
                        tecla = '0'; //Para o Sistema saber que não foi pressionada nada
                        system("cls");
                        }break;
                    //Inclusão de novas propagandas no sistema  --> FILA2
                    case '6':{
                        cout << endl << "DISPLAY" <<endl;
                        cout <<"----------------------------------------------------";
                        cout << endl << "Sistema encontra-se em ESPERA por novas mensagens..."<< endl;
                        string mensagem;
                        cout <<"----------------------------------------------------"<<endl;
                        cout << endl;
                        cout << endl << "ANUNCIANTE: Insira uma nova mensagem!"<< endl;
                        cin >> mensagem;
                        novaMsg.insertAfterLast(mensagem);
                        //novaMsg.listAll();

                        Sleep(360);
                        tecla = '0'; //Para o Sistema saber que não foi pressionada nada
                        system("cls");
                        }break;
                    //Transferência de todas as propagandas da “FILA2″, para a “FILA1″
                    case '7':{
                        msg=1;
                        if(novaMsg.getVazia()==1){
                            msg=0;
                            cout << "SEM ANUNCIOS NA FILA2!" << endl;
                        }
                        else{
                            cout << endl << "DISPLAY" <<endl;
                            cout <<"----------------------------------------------------";
                            cout << endl << "Mensagens da FILA2 enviadas para a FILA1..."<< endl;
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
                            cout <<"----------------------------------------------------"<<endl;
                        }

                        //usleep(500*1000);
                        //Sleep(3600); //um minuto
                        //system ("cls");

                        Sleep(3600);
                        tecla = '0'; //Para o Sistema saber que não foi pressionada nada
                        system("cls");
                        }break;
                    case '8':{
                        if(incluiMsg.getVazia()==1){ //Sem msg pra apagar
                            cout << "SEM ANUNCIOS NA FILA1!" << endl;
                            Sleep(360);
                        }else{
                            cout<<"ANUNCIO: "<< anuncio << endl;
                            cout << "1 - Confirma a exclusao da mensagem!"<<endl;
                            cout << "2 - CANCELAR!"<<endl;
                            cin >> conf;
                            if(conf==1){
                                //Remove a msg da Fila1
                                incluiMsg.removeNode(anuncio);
                                cout<<endl << "Mensagem excluida!" << endl;
                                //verifica se ficou vazia a FILA1
                                if(incluiMsg.getVazia() == 1){
                                    msg =0; //Para o display saber que não tem nada pra exibir
                                }
                            }
                        }
                        Sleep(360);
                        tecla = '0'; //Para o Sistema saber que não foi pressionada nada
                        system("cls");
                        }break;
                }
            }
        //executo meu programa bazeado na tecla
        }while(tecla == '0');

    }

}
