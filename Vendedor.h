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

#endif