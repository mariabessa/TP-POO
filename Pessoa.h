#ifndef PESSOA_H
#define PESSOA_H

#include <iostream>
#include <string>

using namespace std;

class Pessoa {
    private:
        std::string nome;
        std::string usuario;
        std::string senha;
    public:
        Pessoa(const std::string = "", const std::string = "", const std::string = "");
        virtual ~Pessoa();

        void setNome(std::string);
        std::string getNome() const;

        void setUsuario(std::string);
        const std::string &getUsuario() const;

        void setSenha(std::string);
        const std::string &getSenha() const;
};

#endif