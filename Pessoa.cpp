#include "Pessoa.h"

Pessoa::Pessoa(
    const std::string nome, const std::string usuario, const std::string senha
): nome(nome), usuario(usuario), senha(senha) {}

void Pessoa::setNome(std::string nome) {
    this->nome = nome;
}
std::string Pessoa::getNome() const {
    return nome;
}

void Pessoa::setUsuario(std::string usuario) {
    this->usuario = usuario;
}
const std::string &Pessoa::getUsuario() const {
    return usuario;
}

void Pessoa::setSenha(std::string senha) {
    this->senha = senha;
}
const std::string &Pessoa::getSenha() const {
    return senha;
}