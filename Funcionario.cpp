#include "Funcionario.h"

Funcionario::Funcionario(string n, double s) : Pessoa{nome}, salarioHora{s}{ }

double Funcionario::calcularSalario(){
    return salarioHora * horasTrabalhadas;
}

// void Funcionario::ImprimeSalario(){
//     cout << "Salário :" << calcularSalario() << endl;
// }

void Funcionario::cadastrarPonto(double horas){
    horasTrabalhadas += horas;
}