#include "Vendedor.h"

Vendedor::Vendedor(string n, double s) : Funcionario{n, s} { }

void Vendedor::registroVenda(double valor){
    vendas += valor;
}

double Vendedor::calcularSalario(){
    double salario = Funcionario::calcularSalario();
    //recebe o valor como parametro ou pode ser feito assim mesmo?
    return salario + (vendas * 0.1);
}

void Vendedor::imprimeSalario(){
    cout << "Salario Base: " << Funcionario::calcularSalario() << endl;
    cout << "Bonificações: " << (vendas * 0.1) << endl;
}