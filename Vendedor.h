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
        vector<Venda> vendas;
        
        float bonificacao();
    public:
        Vendedor(
            const std::string = "", const std::string = "", const std::string = "",
            const float = 0.0, const Hora, const Hora,
            const std::string = "", const TipoFuncionario, 
            const vector<Venda>
        );
        virtual ~Vendedor();
    
        void setVendas(vector<Venda>);
        vector<Venda> getVendas() const;

        bool cadastrarPonto(Hora, Hora);
        float calcularSalario();

        // void adicionarVenda(Venda);
        // void listarVendas();
};

#endif