#ifndef CHEFE_H
#define CHEFE_H
#include "Pessoa.h"
#include "Supervisor.h"
#include "Vendedor.h"
#include <vector>
#include <iostream>


class Chefe : public Pessoa{
    private:
        string usuario;
        string senha;
        vector<Funcionario*> listaFuncionarios;
        //atributos devem ser estaticos
        //chefe tem uma lista de funcionarios
        //Funcionario tbm tem usuario e senha, deveria ser um atributo de pessoa??
    public:
        Chefe(string, string, string);
        ~Chefe() { }
        bool logar(string, string);
        void cadastrarFuncionario(string, string, double, string, string);
        //funcao de listar funcionarios
        //funcao de checar ponto
        //Cálculo do salário com base nas horas trabalhadas + bonificações.
        //Retonar a tela inicial.
};

#endif