#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include "pessoa.h"

class Funcionario : public Pessoa {
    protected:
        double salarioHora;
        double horasTrabalhadas;
    public:
        Funcionario(string, double);
        ~Funcionario() { }
        double calcularSalario();
        // void ImprimeSalario();
        void cadastrarPonto(double horas);
};

#endif