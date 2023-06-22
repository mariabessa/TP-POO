#include "Funcionario.h"

Funcionario::Funcionario(
    const string nome, const string usuario, const string senha,
    const float salarioPorHora, const Hora tempoTrabalhado,
    const Hora horasPendentes, const string funcao, const TipoFuncionario tipo
):  Pessoa(nome, usuario, senha), salarioPorHora(salarioPorHora),
    tempoTrabalhado(tempoTrabalhado), horasPendentes(horasPendentes), funcao(funcao),
    tipo(tipo) {}

void Funcionario::setSalarioPorHora(float salarioPorHora) {
    this->salarioPorHora = salarioPorHora;
}
float Funcionario::getSalarioPorHora() const {
    return salarioPorHora;
}

void Funcionario::setTempoTrabalhado(Hora tempoTrabalhado) {
    this->tempoTrabalhado = tempoTrabalhado;
}
Hora Funcionario::getTempoTrabalhado() const {
    return tempoTrabalhado;
}

void Funcionario::setHorasPendentes(Hora horasPendentes) {
    this->horasPendentes = horasPendentes;
}
Hora Funcionario::getHorasPendentes() const {
    return horasPendentes;
}

void Funcionario::setFuncao(string funcao) {
    this->funcao = funcao;
}
string Funcionario::getFuncao() const {
    return funcao;
}

void Funcionario::setTipo(TipoFuncionario tipo) {
    this->tipo = tipo;
}
TipoFuncionario Funcionario::getTipo() const {
    return tipo;
}

// Pega o horario de inicio e de fim do funcionário
// Calcula o tempo trabalhado
// Se o funcionario trabalhar mais que 10 horas em um dia, o sistema invalida
bool Funcionario::cadastrarPonto(Hora inicio, Hora fim) {
    int horasTrabalhado, minutosTrabalhado;

    horasTrabalhado = fim.getHoras() - inicio.getHoras();
    minutosTrabalhado = fim.getMinutos() - inicio.getMinutos();

    if(minutosTrabalhado < 0) {
        horasTrabalhado--;
        minutosTrabalhado += 60;
    }

    // Impede q o funcionário trabalhe mais que 10 horas por dia
    if(horasTrabalhado > 10 || (horasTrabalhado == 10 && minutosTrabalhado > 0)) {
        cout << "O funcionário trabalhou mais que 10 horas no dia.\n" << endl;
        cout << "Não será possível cadastrar o ponto.\n" << endl;
        cout << "Tente novamente.\n" << endl;
        return false;
    }

    Hora horasPendentes = this->getHorasPendentes();
    
    // Se o funcionário trabalhar mais que 8 horas no dia
    // atribuimos essas horas extras para outra variavel
    if(horasTrabalhado <= 10 && (horasTrabalhado == 8 && minutosTrabalhado > 0)) { 
        int horasExtras = horasTrabalhado - 8;
        int minutosExtras = minutosTrabalhado;

        horasPendentes.setHoras(horasPendentes.getHoras() + horasExtras);
        horasPendentes.setMinutos(horasPendentes.getMinutos() + minutosExtras);

        if(horasPendentes.getMinutos() >= 60)  {
            horasPendentes.setHoras(horasPendentes.getHoras() + 1);
            horasPendentes.setMinutos(horasPendentes.getMinutos() - 60);
        }
    }

    // Se o funcionário trabalhou menos que 8 horas no dia
    // adicionamos o tempo que ficou faltando nas horas pendentes
    if(horasTrabalhado < 8) {
        if(minutosTrabalhado != 0) {
            horasPendentes.setHoras(horasPendentes.getHoras() - (7 - horasTrabalhado));
            horasPendentes.setMinutos(horasPendentes.getMinutos() - (60 - minutosTrabalhado));

            if(horasPendentes.getMinutos() <= -60) {
                horasPendentes.setMinutos(horasPendentes.getMinutos() + 60);
                horasPendentes.setHoras(horasPendentes.getHoras() - 1);
            }
        }
        else horasPendentes.setHoras(horasPendentes.getHoras() - (8 - horasTrabalhado));
    }

    // Atribuimos as horas trabalhadas removendo as horas extras
    Hora tempoTrabalhado(horasTrabalhado, minutosTrabalhado);

    this->setTempoTrabalhado(tempoTrabalhado);

    cout << "Ponto cadastrado com sucesso.\n" << endl;

    return true;
}

double Funcionario::calcularSalario() {
    int salario, salarioPorHora = this->getSalarioPorHora();
    Hora tempoTrabalhado = this->getTempoTrabalhado();
    Hora tempoPendentes = this->getHorasPendentes();

    int horasTrabalhado = tempoTrabalhado.getHoras();
    int minutosTrabalhado = tempoTrabalhado.getMinutos();

    int horasPendentes = tempoPendentes.getHoras();
    int minutosPendentes = tempoPendentes.getMinutos();

    if(horasPendentes < 0) {
        horasTrabalhado += horasPendentes;
        minutosTrabalhado -= minutosPendentes;
    }
    if(minutosTrabalhado < 0) minutosTrabalhado += minutosPendentes;

    if(horasPendentes > 0) horasTrabalhado += (horasPendentes * 2);
    if(minutosTrabalhado > 0) minutosTrabalhado += (minutosPendentes * 2);

    if(minutosTrabalhado >= 60) {
        horasTrabalhado += 1;
        minutosTrabalhado -= 60;
    }

    salario = horasTrabalhado * salarioPorHora + (minutosTrabalhado * salarioPorHora)/60;
}