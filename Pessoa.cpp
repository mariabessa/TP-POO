#include "Pessoa.h"
#include <string>
using namespace std;

Pessoa::Pessoa(string n) : nome{n} { }

void Pessoa :: imprime(){
    cout << "Nome: " << nome << "\n";
}