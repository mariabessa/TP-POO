#include "Funcionario.h"

Funcionario::Funcionario(
    const std::string nome, const std::string usuario, const std::string senha,
    const float salarioPorHora, const Hora tempoTrabalhado,
    const Hora horasPendentes, const std::string funcao, const TipoFuncionario tipo
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

void Funcionario::setFuncao(std::string funcao) {
    this->funcao = funcao;
}
const std::string &Funcionario::getFuncao() const {
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
void Funcionario::cadastrarPonto() {}

void Funcionario::calcularSalario() {}

void Funcionario::bonificacao() {}

bool Ponto(Hora inicio, Hora fim, Hora *horasPendentes, int *horasTrabalhado, int *minutosTrabalhado) {
    *horasTrabalhado = fim.getHoras() - inicio.getHoras();
    *minutosTrabalhado = fim.getMinutos() - inicio.getMinutos();

    if(*minutosTrabalhado < 0) {
        *horasTrabalhado--;
        *minutosTrabalhado += 60;
    }

    // Impede q o funcionário trabalhe mais que 10 horas por dia
    if(*horasTrabalhado > 10 || (*horasTrabalhado == 10 && *minutosTrabalhado > 0)) {
        cout << "O funcionário trabalhou mais que 10 horas no dia.\n" << endl;
        cout << "Não será possível cadastrar o ponto.\n" << endl;
        cout << "Tente novamente.\n" << endl;
        return false;
    }

    // Hora horasPendentes = this->getHorasPendentes();
    
    // Se o funcionário trabalhar mais que 8 horas no dia
    // atribuimos essas horas extras para outra variavel
    if(*horasTrabalhado <= 10 && (*horasTrabalhado == 8 && *minutosTrabalhado > 0)) { 
        int horasExtras = *horasTrabalhado - 8;
        int minutosExtras = *minutosTrabalhado;

        (*horasPendentes).setHoras((*horasPendentes).getHoras() + horasExtras);
        (*horasPendentes).setMinutos((*horasPendentes).getMinutos() + minutosExtras);

        if((*horasPendentes).getMinutos() >= 60)  {
            (*horasPendentes).setHoras((*horasPendentes).getHoras() + 1);
            (*horasPendentes).setMinutos((*horasPendentes).getMinutos() - 60);
        }
    }

    return true;
}

float Funcionario::calculoSalarioPorHoras(TipoFuncionario tipoFuncionario) {
    int salarioPorHora = this->getSalarioPorHora();
    float multiplicadorHorasExtras;
    Hora tempoTrabalhado = this->getTempoTrabalhado();
    Hora tempoPendentes = this->getHorasPendentes();

    float horasTrabalhado = tempoTrabalhado.getHoras();
    float minutosTrabalhado = tempoTrabalhado.getMinutos();

    int horasPendentes = (tempoPendentes).getHoras();
    int minutosPendentes = (tempoPendentes).getMinutos();
    
    if(tipoFuncionario == TipoFuncionario::Vendedor) multiplicadorHorasExtras = 2.0;
    else multiplicadorHorasExtras = 2.5;

    if(horasPendentes < 0) {
        horasTrabalhado += horasPendentes;
        minutosTrabalhado -= minutosPendentes;
    }
    if(minutosTrabalhado < 0) minutosTrabalhado += minutosPendentes;

    if(horasPendentes > 0) horasTrabalhado += (horasPendentes * multiplicadorHorasExtras);
    if(minutosTrabalhado > 0) minutosTrabalhado += (minutosPendentes * multiplicadorHorasExtras);

    if(minutosTrabalhado >= 60) {
        horasTrabalhado += 1;
        minutosTrabalhado -= 60;
    }

    return horasTrabalhado * salarioPorHora + (minutosTrabalhado * salarioPorHora)/60;
}