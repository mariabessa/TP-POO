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
        
        void setFuncionarios(vector<Funcionario*>);
        vector<Funcionario*> getFuncionarios() const;

        void adicionarFuncionario(Funcionario*);
        void listarFuncionarios();
};

#endif