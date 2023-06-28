#ifndef FUNCIONARIO
#define FUNCIONARIO

#include <iostream>
#include <string>

#include "Pessoa.h"
#include "Hora.h"

using namespace std;

enum class TipoFuncionario { Vendedor, Supervisor };

class Funcionario : public Pessoa {
    protected:    
        float salarioPorHora;
        Hora tempoTrabalhado;
        Hora horasPendentes;
    private:
        string funcao;
        TipoFuncionario tipo;
    public:
        Funcionario(
            const string = "", const string = "", const string = "",
            const float = 0.0, const Hora& = Hora(), const Hora& = Hora(),
            const string = "", const TipoFuncionario = TipoFuncionario::Vendedor
        );
        // virtual ~Funcionario();

        // Getters e Setters

        void setSalarioPorHora(float);
        float getSalarioPorHora() const;

        void setTempoTrabalhado(Hora);
        Hora getTempoTrabalhado() const;

        void setHorasPendentes(Hora);
        Hora getHorasPendentes() const;

        void setFuncao(string);
        const string &getFuncao() const;
        
        void setTipo(TipoFuncionario);
        TipoFuncionario getTipo() const;

        // Funções

        // Pega o horario de inicio e de fim do funcionário
        // Calcula o tempo trabalhado
        // Se o funcionario trabalhar mais que 10 horas em um dia, o sistema invalida
        virtual void cadastrarPonto() = 0;
        virtual float calcularSalario() = 0;
        virtual float bonificacao() = 0;    // Funcao que aumenta salario do funcionario
        // void ImprimeSalario();

    // private:
    protected:
        bool ponto(Hora, Hora, Hora*, int*, int*);
        float calculoSalarioPorHoras(TipoFuncionario);
};

#endif