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
        void setNome(string);
        void imprime();

};

#endif