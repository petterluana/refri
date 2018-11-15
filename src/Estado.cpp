#include "Estado.h"

#include <iostream>
using namespace std;

void Estado::next_state(){
    switch(estado_atual){
        //Estado Atual S000
        case 0:
            cout << endl << "Insira um valor: ";
            cin >> inseriu_valor;
            if(inseriu_valor == 0.00){
                //Fica neste estado
            }else if(inseriu_valor == 0.25){
                estado_atual = 25;
                valor_total = valor_total + 0.25;
            }else if(inseriu_valor == 0.50){
                estado_atual = 50;
                valor_total = valor_total + 0.50;
            }else if(inseriu_valor == 1.00){
                estado_atual = 100;
                valor_total = valor_total + 1.00;
            }else{ //qualquer outro valor devolve
                cout << endl<< "Nao aceito pela maquina!" << endl;
                cout << "Devolucao de " << inseriu_valor <<endl <<endl;
            }
            cout << "Valor total: " << valor_total << endl;
            break;
        //Estado Atual S025
        case 25:
            cout << endl << "Insira um valor: ";
            cin >> inseriu_valor;
            if(inseriu_valor == 0.00){
                //Fica neste estado
            }else if(inseriu_valor == 0.25){
                estado_atual = 50;
                valor_total = valor_total + 0.25;
            }else if(inseriu_valor == 0.50){
                estado_atual = 75;
                valor_total = valor_total + 0.50;
            }else if(inseriu_valor == 1.00){
                estado_atual = 125;
                valor_total = valor_total + 1.00;
            }else{ //qualquer outro valor devolve
                cout << endl<< "Nao aceito pela maquina!" << endl;
                cout << "Devolucao de " << inseriu_valor <<endl <<endl;
            }
            cout << "Valor total: " << valor_total << endl;
            break;
         //Estado Atual S050
         case 50:
            cout << endl << "Insira um valor: ";
            cin >> inseriu_valor;
            if(inseriu_valor == 0.00){
                //Fica neste estado
            }else if(inseriu_valor == 0.25){
                estado_atual = 75;
                valor_total = valor_total + 0.25;
            }else if(inseriu_valor == 0.50){
                estado_atual = 100;
                valor_total = valor_total + 0.50;
            }else if(inseriu_valor == 1.00){
                estado_atual = 150;
                valor_total = valor_total + 1.00;
            }else{ //qualquer outro valor devolve
                cout << endl<< "Nao aceito pela maquina!" << endl;
                cout << "Devolucao de " << inseriu_valor <<endl <<endl;
            }
            cout << "Valor total: " << valor_total << endl;
            break;
        //Estado Atual S075
        case 75:
            cout << endl << "Insira um valor: ";
            cin >> inseriu_valor;
            if(inseriu_valor == 0.00){
                //Fica neste estado
            }else if(inseriu_valor == 0.25){
                estado_atual = 100;
                valor_total = valor_total + 0.25;
            }else if(inseriu_valor == 0.50){
                estado_atual = 125;
                valor_total = valor_total + 0.50;
            }else if(inseriu_valor == 1.00){
                estado_atual = 150;
                valor_total = valor_total + 1.00;
                devolucao_automatica(); //devolve 25 centavos
            }else{ //qualquer outro valor devolve
                cout << endl<< "Nao aceito pela maquina!" << endl;
                cout << "Devolucao de " << inseriu_valor <<endl <<endl;
            }
            cout << "Valor total: " << valor_total << endl;
            break;
        //Estado Atual S100
        case 100:
            cout << endl << "Insira um valor: ";
            cin >> inseriu_valor;
            if(inseriu_valor == 0.00){
                //Fica neste estado
            }else if(inseriu_valor == 0.25){
                estado_atual = 125;
                valor_total = valor_total + 0.25;
            }else if(inseriu_valor == 0.50){
                estado_atual = 150;
                valor_total = valor_total + 0.50;
            }else if(inseriu_valor == 1.00){
                estado_atual = 150;
                valor_total = valor_total + 1.00;
                devolucao_automatica(); //devolve 50 centavos
            }else{ //qualquer outro valor devolve
                cout << endl<< "Nao aceito pela maquina!" << endl;
                cout << "Devolucao de " << inseriu_valor <<endl <<endl;
            }
            cout << "Valor total: " << valor_total << endl;
            break;
        //Estado Atual S125
        case 125:
            cout << endl << "Insira um valor: ";
            cin >> inseriu_valor;
            if(inseriu_valor == 0.00){
                //Fica neste estado
            }else if(inseriu_valor == 0.25){
                estado_atual = 150;
                valor_total = valor_total + 0.25;
            }else if(inseriu_valor == 0.50){
                estado_atual = 150;
                valor_total = valor_total + 0.50;
                devolucao_automatica(); //devolve 25 centavos
            }else if(inseriu_valor == 1.00){
                estado_atual = 150;
                valor_total = valor_total + 1.00;
                devolucao_automatica(); //devolve 75 centavos
            }else{ //qualquer outro valor devolve
                cout << endl<< "Nao aceito pela maquina!" << endl;
                cout << "Devolucao de " << inseriu_valor <<endl <<endl;
            }
            cout << "Valor total: " << valor_total << endl;
            break;
        //Estado Atual S150
        case 150:
            cout << endl << "Insira um valor: ";
            cin >> inseriu_valor;
            if(inseriu_valor == 0.00){
                //Fica neste estado
            }else if(inseriu_valor == 0.25){
                estado_atual = 150;
                valor_total = valor_total + 0.25;
                devolucao_automatica(); //devolve 25 centavos
            }else if(inseriu_valor == 0.50){
                estado_atual = 150;
                valor_total = valor_total + 0.50;
                devolucao_automatica(); //devolve 50 centavos
            }else if(inseriu_valor == 1.00){
                estado_atual = 150;
                valor_total = valor_total + 1.00;
                devolucao_automatica(); //devolve 100 centavos
            }else{ //qualquer outro valor devolve
                cout << endl<< "Nao aceito pela maquina!" << endl;
                cout << "Devolucao de " << inseriu_valor <<endl <<endl;
            }
            cout << "Valor total: " << valor_total << endl;
            break;
    }
}

void Estado::devolucao_automatica(){
    if(valor_total > 1.50){
        cout << endl<< "Devolucao do excesso de moedas: " << (valor_total-1.50) << endl;
        valor_total = 1.50;
    }
}

void Estado::tecla_dev(){
    if(estado_atual == 0){
        cout << endl << "Nada a devolver!" << endl;
    }else{
        cout << endl << "Valor devolvido: " << valor_total << endl;
        valor_total = 0;
    }
}

