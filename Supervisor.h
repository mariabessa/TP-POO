#ifndef SUPERVISOR_H
#define SUPERVISOR_H
#include"Funcionario.h"
#include <vector>


class Supervisor : public Funcionario {
    friend class Chefe;
    private:
        //lista de vendedores que o supervisor tem
    public:
        Supervisor(string, double);
        //Cadastrar ponto.
// • Exibir salário, em função das horas trabalhadas + bonificações, de forma detalhada.
// • Cadastrar venda.
// • Listar vendas (se for supervisor devem listadas as vendas de todos os vendedores).
// • Retonar a tela inicial.
};
#endif