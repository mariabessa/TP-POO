<<<<<<< Updated upstream
#ifndef VENDEDOR_H
#define VENDEDOR_H
#include "Funcionario.h"
#include <iostream>

class Vendedor : public Funcionario{
    friend class Chefe;
    friend class Supervisor;
    private: 
        double vendas;
    public:
        Vendedor(string, double);
        ~Vendedor(){ }
        void registroVenda(double);
        double calcularSalario();
        void imprimeSalario();
};

=======
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
        
        // float bonificacao();
        float bonificacao() override;
    public:
        Vendedor(
            const string = "", const string = "", const string = "",
            const string = "", const TipoFuncionario = TipoFuncionario::Vendedor,
            const float = 0.0, const Hora& = Hora(), const Hora& = Hora(),
            const vector<Hora*> = vector<Hora*>(),
            const vector<Venda*> = vector<Venda*>()
        );
        // virtual ~Vendedor();
    
        void setVendas(vector<Venda*>);
        vector<Venda*> getVendas() const;

        // bool cadastrarPonto(Hora, Hora);
        // float calcularSalario();
        void cadastrarPonto(Hora, Hora) override;
        float calcularSalario() override;

        void adicionarVenda(Venda*);
        // void listarVendas();
};

>>>>>>> Stashed changes
#endif