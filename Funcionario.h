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
        std::string funcao;
        TipoFuncionario tipo;
    public:
        Funcionario(
            const std::string = "", const std::string = "", const std::string = "",
            const float = 0.0, const Hora, const Hora, const std::string = "",
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

        void setFuncao(std::string);
        const std::string &getFuncao() const;
        
        void setTipo(TipoFuncionario);
        TipoFuncionario getTipo() const;

        // Funções

        void cadastrarPonto();
        void calcularSalario();
        void bonificacao();    // Funcao que aumenta salario do funcionario
        // void ImprimeSalario();

    // private:
    protected:
        bool ponto(Hora, Hora, Hora*, int*, int*);
        float calculoSalarioPorHoras(TipoFuncionario);
};

#endif