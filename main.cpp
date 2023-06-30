#include "Chefe.h"
#include "Funcionario.h"
#include "Supervisor.h"
#include "Vendedor.h"
#include "Venda.h"
#include "Hora.h"
#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

void cadastrarFuncionario(vector<Funcionario*> *funcionarios) {
    string nome = "", usuario = "", senha = "", funcao = "";
    string salarioPorHoraStr;
    float salarioPorHora = 0;
    int tipoFuncionario = -1;
    bool verifica;

    Funcionario *funcionario = new Vendedor();
    
    cout << "Informe os dados do Funcionario" << endl;
    cout << "Nome: ";
    cin.ignore();
    getline(cin, nome);
    system("clear||cls");

    cout << endl << "Usuario: ";
    getline (cin, usuario);
    system("clear||cls");


    cout << endl << "Senha: ";
    getline (cin, senha);
    system("clear||cls");


    do{ 
        verifica = true;
        try{
            cout << endl << "Salário por hora: ";
            cin >> salarioPorHoraStr;

            salarioPorHora = stof(salarioPorHoraStr);
        } catch (const invalid_argument& e) {
            cout << endl;
            cerr << "Erro: Entrada inválida. Digite um número válido." << endl;
            verifica = 0;
        }
    } while (verifica == false);
    system("clear||cls");


    cin.ignore(1000, '\n');
    cout << endl << "Função: ";
    getline (cin, funcao);
    system("clear||cls");


    do {
        cout << endl << "Tipo: " << endl << "   0- Vendedor" << endl << "   1- Supervisor" << endl;
        cout << "Escolha dentre as opções: ";
        cin >> tipoFuncionario;
        if(tipoFuncionario == 0)
            funcionario = new Vendedor(nome, usuario, senha, funcao, TipoFuncionario::Vendedor, salarioPorHora);
        else if(tipoFuncionario == 1)
            funcionario = new Supervisor(nome, usuario, senha, funcao, TipoFuncionario::Supervisor, salarioPorHora);
        else
            cout << "Informe um t&&o válido" << endl;
    } while(tipoFuncionario != 0 && tipoFuncionario != 1);
    system("clear||cls");

    funcionarios->push_back(funcionario);
}

void telaChefe(Chefe *chefe, vector<Funcionario*> *funcionarios) {
    string opcaoStr;
    int opcao = -1;
    bool verifica;
    do {
        verifica = 1; 
        try {
            cout << "---------------------Tela Chefe---------------------" << endl;
            cout << "    0- Cadastrar funcionário" << endl;
            cout << "    1- Listar funcionários cadastrados" << endl;
            cout << "    2- Checar ponto" << endl;
            cout << "    3- Calcular salário" << endl;
            cout << "    4- Voltar" << endl;
            cout << endl;
            cout << "Informe a opção que deseja execultar: ";
            cin >> opcaoStr;
            opcao = stoi(opcaoStr);
            system("clear||cls");
        } catch (const invalid_argument& e) {
            system("clear||cls");
            cerr << "Erro: Entrada inválida. Digite um número válido." << endl;
            verifica = 0;
        }

        if(verifica){
            switch (opcao) {
                case 0:
                    cadastrarFuncionario(funcionarios);
                    break;
                
                case 1:
                    for(auto funcionario:(*funcionarios)) {
                        cout << "Nome: " << funcionario->getNome() << endl;
                        cout << "Função: " << funcionario->getFuncao() << endl;
                    }
                    break;
                
                case 2:
                    // Passa por todos os funcionarios e informa os seus dados(Nome, Função, Tempo Trabalhado)
                    for(auto funcionario:chefe->getFuncionarios()) {
                        cout << "Nome: " << funcionario->getNome() << endl;
                        cout << "Função: " << funcionario->getFuncao() << endl;
                        cout << "Tempo Trabalhado: " << funcionario->calculoSalarioPorHoras(funcionario->getTipo())/funcionario->getSalarioPorHora() << " horas" << endl;
                    }
                    break;
                
                case 3:
                    // Passa por todos os funcionarios e informa os seus dados(Nome, Função, Salário)
                    for(auto funcionario:chefe->getFuncionarios()) {
                        cout << "Nome: " << funcionario->getNome() << endl;
                        cout << "Função: " << funcionario->getFuncao() << endl;
                        cout << "Salário: " << funcionario->calculoSalarioPorHoras(funcionario->getTipo()) << " horas" << endl;
                    }
                    break;
                
                case 4:
                    break;
                
                default:
                    cout << "Informe uma opção válida.\n" << endl;
                    break;
            }
        }
    } while(opcao != 4 && verifica == false);    
}

void cadastrarPonto(Funcionario *funcionario) {
    Hora *pontoInicio, *pontoFim;
    int horasPontoInicio, minutosPontoInicio, horasPontoFim, minutosPontoFim;
    
    cout << "Informe as Horas do inicio do ponto: ";
    cin >> horasPontoInicio;
    cout << endl << "Informe os Minutos do inicio do ponto: ";
    cin >> minutosPontoInicio;
    cout << endl << "Informe as Horas do fim do ponto: ";
    cin >> horasPontoFim;
    cout << endl << "Informe os Minutos do fim do ponto: ";
    cin >> minutosPontoFim;

    pontoInicio = new Hora(horasPontoInicio, minutosPontoInicio);
    pontoFim = new Hora(horasPontoFim, minutosPontoFim);

    funcionario->cadastrarPonto(*pontoInicio, *pontoFim);

    cout << funcionario->getTempoTrabalhado().getHoras() << ":" << funcionario->getTempoTrabalhado().getMinutos() << endl;
}

void listarVendas(Vendedor *vendedor) {
    cout << "Nome do vendedor: " << vendedor->getNome() << endl;
    
    for(auto venda:vendedor->getVendas())
        cout << "Valor Venda: " << venda->getValor() << endl;
}

void telaFuncionario(Funcionario *funcionario) {
    Vendedor* vendedor = dynamic_cast<Vendedor*>(funcionario);
    Supervisor* supervisor = dynamic_cast<Supervisor*>(funcionario);
    int opcao = -1;
    bool verifica;
    string opcaoStr;
    do {
        verifica = 1;
        try {
            cout << "------------------Tela Funcionário------------------" << endl;
            cout << "    0- Cadastrar ponto" << endl;
            cout << "    1- Exibir salário" << endl;
            cout << "    2- Cadastrar venda" << endl;
            cout << "    3- Listar vendas" << endl;
            cout << "    4- Voltar para o Menu Inicial" << endl;
            cout << endl;
            cout << "Informe a opção que deseja execultar: ";
            cin >> opcaoStr;
            opcao = stoi(opcaoStr);
        } catch (const invalid_argument& e) {
            system("clear||cls");
            cerr << "Erro: Entrada inválida. Digite um número válido." << endl;
            verifica = 0;
        }
        if(verifica){
            switch (opcao) {
                case 0:
                    cadastrarPonto(funcionario);
                    break;
                
                case 1:
                    cout << "Salário" << funcionario->calculoSalarioPorHoras(funcionario->getTipo()) << endl;
                    break;
                
                case 2: {
                    if(funcionario->getTipo() == TipoFuncionario::Supervisor) {
                        cout << "Apenas Vendedores podem realizar vendas" << endl;  // Trocar por um alerta ou um warning
                        break;
                    }

                    float valorVenda; // <= adicionar o valor da venda
                    Venda* venda = new Venda();

                    cout << "Informe o Valor da Venda: ";
                    cin >> valorVenda;

                    venda->setValor(valorVenda);

                    vendedor->adicionarVenda(venda);

                    delete venda;

                    break;
                }

                case 3:
                    if(funcionario->getTipo() == TipoFuncionario::Supervisor) {
                        for(auto vendedor:supervisor->getVendedor())            
                            listarVendas(vendedor);
                        break;
                    }
                    listarVendas(vendedor);

                    break;
                
                case 4:
                    break;
                
                default:
                    cout << "Informe uma opção válida.\n" << endl;
                    break;
            }
        } 
    } while(opcao != 4);
}

bool login(Chefe *chefe, vector<Funcionario*> *funcionarios, int tipoLogin, string usuario, string senha) {
    bool achou = false;
    
    // Procura se o usuario e senha existem na lista de Chefes
    if(tipoLogin == 0) {
        // Uma maneira de procurar todos os chefes
        // E examinar usuario e senha de cada chefe
        achou = chefe->logar(usuario, senha);
        if(achou)
            cout << "Logou." << endl;
        else
            cout << "Não logou." << endl;

        // Se achar um chefe q os dados batem c os q foram passados, vamos para a tela do chefe
        if(achou)
            // Tela Chefe
            telaChefe(chefe, funcionarios);
    }
    else {
        // Uma maneira de procurar todos os funcionarios
        // E examinar usuario e senha de cada funcionario
        for(auto funcionario:(*funcionarios))
            if(funcionario->logar(usuario, senha)) {
                achou = true;
                telaFuncionario(funcionario);
            }
                
        // Se achar um funcionario q os dados batem c os q foram passados, vamos para a tela do funcionario
    }

    // Se o Chefe/Funcionario conseguiram acessar sua tela, sera retornado True e voltaremos para o Menu Inicial
    // Se os dados de login n bateram c os q temos armazenados, sera retornado False e voltaremos para o Menu de Login para o usuaro tentar novamente ou voltar manualmente para a o Menu Inicial

    return achou;
}

bool realizarLogin(Chefe *chefe, vector<Funcionario*> *funcionarios, int tipoLogin, string usuario, string senha) {
    // Se conseguir fazer login
    
    if(login(chefe, funcionarios,tipoLogin, usuario, senha)) return true;
    
    // Se n conseguir fazer login vai exibir mensagem de erro e retornara para a Tela de Login
    cout << "Login inválida.\n" << endl;

    return false;
}

void telaLogin(Chefe *chefe, vector<Funcionario*> *funcionarios) {
    string usuario, senha;
    string tipologinStr;
    int tipoLogin = -1;
    bool verifica;
    do {
        verifica = 1;
        try{
            cout << "-----------------------Login------------------------" << endl;
            cout << "    0- Login Chefe" << endl;
            cout << "    1- Login Funcionário" << endl;
            cout << "    2- Voltar ao Menu Inicial" << endl;
            cout << endl;
            cout << "Digite a opção desejada: ";
            cin >> tipologinStr;
            tipoLogin = stoi(tipologinStr);
            system("clear||cls");
        } catch (const invalid_argument& e) {
            system("clear||cls");
            cerr << "Erro: Entrada inválida. Digite um número válido." << endl;
            verifica = 0;
        }
        if(verifica){
            switch (tipoLogin)
            {
                case 0:
                case 1:
                    cout << "Informe o seu usuario:" << endl;
                    cin >> usuario;

                    cout << "Informe a sua senha:" << endl;
                    cin >> senha;
                    system("clear||cls");
                    // Se n conseguir fazer login retorna para o menu de login
                    if(!realizarLogin(chefe, funcionarios,tipoLogin, usuario, senha))
                        return;
                    break;
                
                case 2:
                    cout << "Voltando para a tela de login:" << endl;
                    break;
                
                default:
                    break;
            }
        }
    } while(tipoLogin != 2 && verifica == false); 
}

void telaInicial(Chefe *chefe, vector<Funcionario*> *funcionarios) {
    int opcao;
    string opcaoStr;
    bool verifica;
    do {
        verifica = 1;
        try{
            cout << "--------------------Menu Inicial--------------------" << endl;
            cout << "    0- Login" << endl;
            cout << "    1- Sair do menu" << endl;

            cout << "Informe a opção que deseja execultar:" << endl;
            cin >> opcaoStr;
            opcao = stoi(opcaoStr);
            system("clear||cls");
        } catch (const invalid_argument& e) {
            system("clear||cls");
            cerr << "Erro: Entrada inválida. Digite um número válido." << endl;
            verifica = 0;
        }

        switch (opcao) {
            case 0:
                telaLogin(chefe, funcionarios);
                break;
            
            case 1:
                cout << "Finalizando.\n" << endl;
                break;
            
            default:
                cout << "Informe uma opção válida.\n" << endl;
        }
    } while(opcao != 1 && verifica == false);
}

Chefe* iniciarChefe() {
    string nome, usuario, senha;
    string opcaoStr;
    int opcao;
    bool verifica;

    Chefe* chefe;

    system("clear||cls");
    cout << "----Cadastre o Chefe----" << endl;
    cout << endl;
    cout << "Informe seu nome: ";
    getline(cin, nome);
    system("clear||cls");
    do{
        verifica = true;
        try{
            cout << "Quer adicionar Usuario e Senha?" << endl;
            cout << "   0- Não (se mantem como padrão Usuario = 'admin' e Senha = 'admin')" << endl;
            cout << "   1- Sim" << endl;
            cout << endl;
            cout << "Digite a opção desejada: ";
            cin >> opcaoStr;
            opcao = stoi(opcaoStr);
            system("clear||cls");
        } catch (const invalid_argument& e) {
            system("clear||cls");
            cerr << "Erro: Entrada inválida. Digite um número válido." << endl;
            verifica = 0;
        }
    }while(verifica == false);

    if(opcao == 0) chefe = new Chefe(nome);
    else {
        cout << endl << "Usuário: ";
        cin >> usuario;
        cout << endl << "Senha: ";
        cin >> senha;

        chefe = new Chefe(nome, usuario, senha);
    }
    
    fflush(stdin);
    cout << "Chefe criado com sucesso" << endl << endl;

    return chefe;
}
// */

int main() {
    Chefe *chefe;
    vector<Funcionario*> funcionarios;

    chefe = iniciarChefe();
    
    telaInicial(chefe, &funcionarios);
    
    cout << "Finalizando o programa.\n" << endl;
    
    return 0;
}

