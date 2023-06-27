#ifndef CHEFE_H
#define CHEFE_H

#include <iostream>
#include <string>
#include <vector>

#include "Pessoa.h"
#include "Funcionario.h"

using namespace std;

class Chefe : public Pessoa {
    private:
        vector<Funcionario> funcionarios;
    public:
        Chefe(
            const std::string = "", const std::string = "admin", const std::string = "admin",
            const vector<Funcionario>
        );
        virtual ~Chefe();

        void setFuncionarios(vector<Funcionario>);
        vector<Funcionario> getFuncionarios() const;

        void adicionarFuncionario(Funcionario);
        void listarFuncionarios();
        bool logar(std::string, std::string);
        // void cadastrarFuncionario(std::string, std::string, double, std::string, std::string);
        //funcao de listar funcionarios
        //funcao de checar ponto
        //Cálculo do salário com base nas horas trabalhadas + bonificações.
};

#endif