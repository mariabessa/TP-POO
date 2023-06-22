#ifndef CHEFE_H
#define CHEFE_H

#include <iostream>
// #include <vector>

#include "Pessoa.h"
#include "Funcionario.h"

using namespace std;

class Chefe : public Pessoa {
    private:
        // vector<Funcionario*> listaFuncionarios;
    public:
        Chefe();
        virtual ~Chefe();
        // bool logar(string, string);
        // void cadastrarFuncionario(string, string, double, string, string);
        //funcao de listar funcionarios
        //funcao de checar ponto
        //Cálculo do salário com base nas horas trabalhadas + bonificações.
};

#endif