#ifndef VENDEDOR_H
#define VENDEDOR_H
#include "Funcionario.h"

class Vendedor : public Funcionario{
    private: 
        double vendas;
    public:
        Vendedor(string, double);
        ~Vendedor(){ }
        void registroVenda(double);
        double calcularSalario();
        void imprimeSalario();
};

#endif