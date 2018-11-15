#ifndef ESTADO_H
#define ESTADO_H


class Estado
{
    public:
        int estado_atual;
        float inseriu_valor;
        float valor_total; //valor total inserido na máquina
        void next_state();
        void tecla_dev();
    private:
        void devolucao_automatica();
        void opcao();
};

#endif // ESTADO_H
