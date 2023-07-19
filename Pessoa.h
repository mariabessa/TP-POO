<<<<<<< Updated upstream
#ifndef PESSOA_H
#define PESSOA_H
#include <string>
#include <iostream>
using namespace std;

class Pessoa {
    protected: 
        string nome;
    public:
        Pessoa(string);
        ~Pessoa() { }
        void imprime();
};

=======
#ifndef PESSOA_H
#define PESSOA_H

#include <iostream>
#include <string>

using namespace std;

class Pessoa {
    private:
        string nome;
        string usuario;
        string senha;
    public:
        Pessoa(const string = "", const string = "", const string = "");
        // virtual ~Pessoa();

        void setNome(string);
        string getNome() const;

        void setUsuario(string);
        const string &getUsuario() const;

        void setSenha(string);
        const string &getSenha() const;

        bool logar(string, string);
};

>>>>>>> Stashed changes
#endif