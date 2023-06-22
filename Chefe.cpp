#include "Chefe.h"


Chefe :: Chefe (string nome, string user, string s) : Pessoa{nome}, usuario{user}, senha{s} { }

bool Chefe :: logar(string user, string s){
    return (usuario == user && senha == s);
}

void Chefe :: cadastrarFuncionario(string nome, string cargo, double salario, string user, string s){
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