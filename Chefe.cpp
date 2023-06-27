#include "Chefe.h"

Chefe::Chefe(
    const std::string nome, const std::string usuario, const std::string senha,
    const vector<Funcionario> funcionarios
):  Pessoa(nome, usuario, senha), funcionarios(funcionarios) {}

void Chefe::setFuncionarios(vector<Funcionario> funcionarios) {
    this->funcionarios = funcionarios;
}
vector<Funcionario> Chefe::getFuncionarios() const {
    return this->funcionarios;
}

void Chefe::adicionarFuncionario(Funcionario funcionario) {
    this->funcionarios.push_back(funcionario);
}

void Chefe::listarFuncionarios() {
    for (auto i = this->funcionarios.begin(); i != this->funcionarios.end(); ++i)
        cout << (*i).getNome() << endl;
}

bool Chefe::logar(std::string usuario, std::string senha) {
    return (this->getUsuario() == usuario && this->getSenha() == senha);
}

/*
bool Chefe :: logar(std::string user, std::string s){
    return (usuario == user && senha == s);
}

void Chefe :: cadastrarFuncionario(std::string nome, std::string cargo, double salario, std::string user, std::string s){
    if(cargo == "Vendedor"){
        // a class chefe deveria ser friend da Vendedor?
        Vendedor* vendedor = new Vendedor(nome, salario);
        //adicionar este novo vendedor a lista de funcionarios do chefe
    }else if(cargo == "supervisor"){
        Supervisor* supervisor = new Supervisor(nome, salario);
        // mesmos questionamentos do primeiro if
    }else {
        cout << "O cargo informado é inválido." << endl;
    }
}
*/