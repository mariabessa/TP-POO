#ifndef SUPERVISOR_H
#define SUPERVISOR_H

#include <iostream>
#include <string>
#include <vector>

#include "Funcionario.h"
#include "Vendedor.h"
#include "Venda.h"

class Supervisor : public Funcionario {
    private:
        vector<Vendedor*> vendedores;
        
        float bonificacao() override;
    public:
        Supervisor(
            const string = "", const string = "", const string = "",
            const string = "", const TipoFuncionario = TipoFuncionario::Vendedor,
            const float = 0.0, const Hora& = Hora(), const Hora& = Hora(),
            const vector<Hora*> = vector<Hora*>(),
            const vector<Vendedor*> = vector<Vendedor*>()
        );
        
        void setVendedor(vector<Vendedor*>);
        vector<Vendedor*> getVendedor() const;

        void cadastrarPonto(Hora, Hora) override;
        float calcularSalario() override;
};
#endif