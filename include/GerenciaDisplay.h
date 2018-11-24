#ifndef GERENCIADISPLAY_H
#define GERENCIADISPLAY_H
#include "Fila1.cpp"
#include "GerenciaTempo.cpp"
#include "Estado.cpp"
#include "Fila2.cpp"
#include "Log.cpp"
//#include "Refri.cpp"
#include <string>

class GerenciaDisplay
{
    private:
        GerenciaTempo dt_hr;
        Estado est;
        Log pedidos; //lista que armazenara os refris comprados.
        Fila2 novaMsg; //lista que armazenara novos anuncios que ainda não são mostrados no display.
        Fila1 incluiMsg; //passará as mensagens da FILA2 para a FILA1.
        Refri meet;//("Meet", 150);
        Refri etirps;//("Etirps", 150);
        char tecla = '0';
        string anuncio;
        int msg = 0;
        int totaltempo=0;
        int anunc = 1;
        int cont = 0;
        int aleatorio=0;
        int sorteio=1; //indica que precisa de um sorteio
        int conf;
    public:
        GerenciaDisplay();
        void exibirMsg();
};

#endif // GERENCIADISPLAY_H
