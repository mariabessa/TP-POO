<<<<<<< Updated upstream
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

=======
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
        vector<Funcionario*> funcionarios;
    public:
        Chefe(
            const string = "", const string = "admin", const string = "admin",
            const vector<Funcionario*> = vector<Funcionario*>()
        );
        // virtual ~Chefe();

        void setFuncionarios(vector<Funcionario*>);
        vector<Funcionario*> getFuncionarios() const;

        void adicionarFuncionario(Funcionario*);
        void listarFuncionarios();
        // bool logar(string, string);
        // void cadastrarFuncionario(string, string, double, string, string);
        //funcao de listar funcionarios
        //funcao de checar ponto
        //Cálculo do salário com base nas horas trabalhadas + bonificações.
};

>>>>>>> Stashed changes
#endif