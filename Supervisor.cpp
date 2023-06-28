#include "Supervisor.h"

// /*
Supervisor::Supervisor(
    const string nome, const string usuario, const string senha,
    const float salarioPorHora, const Hora& tempoTrabalhado,
    const Hora& horasPendentes, const string funcao, const TipoFuncionario tipo,
    const vector<Vendedor*> vendedores
): Funcionario(
        nome, usuario, senha, salarioPorHora, tempoTrabalhado, 
        horasPendentes, funcao, tipo
    ), vendedores(vendedores) {}
// */

bool Supervisor::cadastrarPonto(Hora inicio, Hora fim) {
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

float Supervisor::calcularSalario() {
    return calculoSalarioPorHoras(this->getTipo()) + bonificacao();
}

float Supervisor::bonificacao() {
    float valorTotal = 0.0;

    for(auto i = this->vendedores.begin(); i != this->vendedores.end(); ++i) {
        vector<Venda*> vendas = (*i)->getVendas();
        for(auto j = vendas.begin(); j != vendas.end(); ++j)
            valorTotal += (*j)->getValor() * 0.01;
    }
    
    return valorTotal;
}

/*
void Supervisor::adicionarVendedor(Vendedor vendedor) {
    this->vendedores.push_back(vendedor);
}

void Supervisor::listarVendedores() {
    for (auto i = this->vendedores.begin(); i != this->vendedores.end(); ++i)
        cout << (*i).getNome() << endl;
}
*/