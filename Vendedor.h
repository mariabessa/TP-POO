#ifndef VENDEDOR_H
#define VENDEDOR_H

#include <iostream>
#include <string>
#include <vector>

#include "Funcionario.h"
#include "Hora.h"
#include "Venda.h"

using namespace std;

class Vendedor : public Funcionario {
    private:
        vector<Venda*> vendas;
        
        float bonificacao();
        // float bonificacao() override {}
    public:
        Vendedor(
            const string = "", const string = "", const string = "",
            const float = 0.0, const Hora& = Hora(), const Hora& = Hora(),
            const string = "", const TipoFuncionario = TipoFuncionario::Vendedor, 
            const vector<Venda*> = vector<Venda*>()
        );
        // virtual ~Vendedor();
    
        void setVendas(vector<Venda*>);
        vector<Venda*> getVendas() const;

        // bool cadastrarPonto(Hora, Hora);
        bool cadastrarPonto(Hora, Hora);
        // float calcularSalario();
        float calcularSalario();

        // void adicionarVenda(Venda);
        // void listarVendas();
};

#endif