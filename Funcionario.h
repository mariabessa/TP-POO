#ifndef FUNCIONARIO
#define FUNCIONARIO

#include <iostream>
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
            const float = 0.0, const Hora, const Hora, const string = "",
            const TipoFuncionario = TipoFuncionario::Vendedor
        );
        virtual ~Funcionario();

        // Getters e Setters

        void setSalarioPorHora(float);
        float getSalarioPorHora() const;

        void setTempoTrabalhado(Hora);
        Hora getTempoTrabalhado() const;

        void setHorasPendentes(Hora);
        Hora getHorasPendentes() const;

        void setFuncao(string);
        string getFuncao() const;
        
        void setTipo(TipoFuncionario);
        TipoFuncionario getTipo() const;

        // Funções

        bool cadastrarPonto(Hora, Hora);
        double calcularSalario();
        // bonificacao()    // Funcao que aumenta salario do funcionario
        // void ImprimeSalario();
};

#endif