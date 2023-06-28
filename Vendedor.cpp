#include "Vendedor.h"

Vendedor::Vendedor(
    const string nome, const string usuario, const string senha,
    const float salarioPorHora, const Hora& tempoTrabalhado,
    const Hora& horasPendentes, const string funcao,
    const TipoFuncionario tipo, const vector<Venda*> vendas
): Funcionario(
        nome, usuario, senha, salarioPorHora, tempoTrabalhado, 
        horasPendentes, funcao, tipo
    ), vendas(vendas) {}

void Vendedor::setVendas(vector<Venda*> vendas) {
    this->vendas = vendas;
}
vector<Venda*> Vendedor::getVendas() const {
    return this->vendas;
}

bool Vendedor::cadastrarPonto(Hora inicio, Hora fim) {
    int horasTrabalhado, minutosTrabalhado;
    Hora horasPendentes = this->getHorasPendentes();
    
    if(!this->ponto(inicio, fim, &horasPendentes, &horasTrabalhado, &minutosTrabalhado))
        return false;

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

float Vendedor::calcularSalario() {
    return calculoSalarioPorHoras(this->getTipo()) + bonificacao();
}

float Vendedor::bonificacao() {
    float valorTotal = 0.0;

    for (auto i = this->vendas.begin(); i != this->vendas.end(); ++i)
        valorTotal += (*i)->getValor() * 0.1;
    
    return valorTotal;
}

/*
void Vendedor::adicionarVenda(Venda venda) {
    this->vendas.push_back(venda);
}

void Vendedor::listarVendas() {
    for (auto i = this->vendas.begin(); i != this->vendas.end(); ++i)
        cout << (*i).getValor() << endl;
}
*/