#include "Chefe.h"

Chefe::Chefe(
    const string nome, const string usuario, const string senha,
    const vector<Funcionario*> funcionarios
):  Pessoa(nome, usuario, senha), funcionarios(funcionarios) {}

void Chefe::setFuncionarios(vector<Funcionario*> funcionarios) {
    this->funcionarios = funcionarios;
}
vector<Funcionario*> Chefe::getFuncionarios() const {
    return this->funcionarios;
}
