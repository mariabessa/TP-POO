#ifndef SUPERVISOR_H
#define SUPERVISOR_H

#include <iostream>
#include <string>
#include <vector>

#include "Funcionario.h"
#include "Vendedor.h"
#include "Venda.h"

class Supervisor : public Funcionario {
    // friend class Chefe;
    private:
        vector<Vendedor*> vendedores;
        
        float bonificacao();
    public:
        Supervisor(
            const string = "", const string = "", const string = "",
            const float = 0.0, const Hora& = Hora(), const Hora& = Hora(),
            const string = "", const TipoFuncionario = TipoFuncionario::Vendedor,
            const vector<Vendedor*> = vector<Vendedor*>()
        );
        // virtual ~Supervisor();
        
        bool cadastrarPonto(Hora, Hora);
        float calcularSalario();

        // void adicionarVendedor(Vendedor);
        // void listarVendedores();

// • Exibir salário, em função das horas trabalhadas + bonificações, de forma detalhada.
// • Cadastrar venda.
// • Listar vendas (se for supervisor devem listadas as vendas de todos os vendedores).
// • Retonar a tela inicial.
};
#endif