#include "Chefe.h"
#include "Funcionario.h"
#include "Supervisor.h"

#include <iostream>

using namespace std;

void cadastrarFuncionario(Chefe* chefe) {
    string nome, usuario, senha, funcao;
    float salarioPorHora;
    int tipoFuncionario = -1;

    Funcionario *funcionario;
    
    cout << "Informe os dados do Funcionario" << endl;
    cout << "Nome: ";
    cin >> nome;
    cout << endl << "Usuario: ";
    cin >> usuario;
    cout << endl << "Senha: ";
    cin >> senha;
    cout << endl << "Salário por hora: ";
    cin >> salarioPorHora;
    cout << endl << "Função: ";
    cin >> funcao;
    do {
        cout << endl << "Tipo: " << endl << "   0- Vendedor" << endl << "   1- Supervisor";
        cin >> tipoFuncionario;

        if(tipoFuncionario == 0)
            funcionario = new Vendedor(nome, usuario, senha, funcao, TipoFuncionario::Vendedor, salarioPorHora);
        else if(tipoFuncionario == 1)
            funcionario = new Supervisor(nome, usuario, senha, funcao, TipoFuncionario::Supervisor, salarioPorHora);
        else
            cout << "Informe um tipo válido" << endl;
    } while(tipoFuncionario != 0 || tipoFuncionario != 1);

    chefe->adicionarFuncionario(funcionario);

    delete funcionario;
}

void telaChefe(Chefe *chefe) {
    int opcao;

    do {
        cout << "---------------------Tela Chefe---------------------" << endl;
        cout << "    0- Cadastrar funcionário" << endl;
        cout << "    1- Listar funcionários cadastrados" << endl;
        cout << "    2- Checar ponto" << endl;
        cout << "    3- Calcular salário" << endl;
        cout << "    4- Voltar para o Menu Inicial" << endl;

        cout << "Informe a opção que deseja execultar:" << endl;
        cin >> opcao;

        switch (opcao) {
            case 0:
                // Funcionario funcionario = new Funcionario(...dados)
                // funcionarios.lista(add funcionario)
                cadastrarFuncionario(chefe);
                break;
            
            case 1:
                // funcionarios.map((funcionario) => return funcionario.dados)
                chefe->listarFuncionarios();
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
    } while(opcao != 4);
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

    funcionario->cadastrarPonto(pontoInicio, pontoFim);
}

void telaFuncionario(Funcionario *funcionario) {
    int opcao;

    do {
        cout << "------------------Tela Funcionário------------------" << endl;
        cout << "    0- Cadastrar ponto" << endl;
        cout << "    1- Exibir salário" << endl;
        cout << "    2- Cadastrar venda" << endl;
        cout << "    3- Listar vendas" << endl;
        cout << "    4- Voltar para o Menu Inicial" << endl;

        cout << "Informe a opção que deseja execultar:" << endl;
        cin >> opcao;

        switch (opcao) {
            case 0:
                // int horarioChegada, horarioSaida
                // int horasTrabalhada = horarioSaida - horarioChegada
                // funcionario.setPonto(horasTrabalhada)
                cadastrarPonto(funcionario);
                break;
            
            case 1:
                // int salario = calcSalario(funcionario.dados)
                // print salario
                cout << "Salário" << funcionario->calculoSalarioPorHoras(funcionario->getTipo()) << endl;
                break;
            
            case 2:
                if(funcionario->getTipo() == TipoFuncionario::Supervisor) {
                    cout << "Apenas Vendedores podem realizar vendas" << endl;  // Trocar por um alerta ou um warning
                    break;
                }

                int valorVenda; // <= adicionar o valor da venda
                Venda* venda = new Venda();

                cout << "Informe o Valor da Venda: ";
                cin >> valorVenda;

                venda->setValor(valorVenda);
                
                funcionario.adicionarVenda(venda);

                delete venda;

                break;
            
            case 3:
                // if(funcionario.isSupervisor)
                    // supervisor.funcionarios.map((funcionario) => return funcionario.vendas)
                // else
                    // funcionario.vendas
                for(auto venda:funcionario.getVendas())
                    cout << "Valor Venda: " << venda->getValor() << endl;

                break;
            
            case 4:
                break;
            
            default:
                cout << "Informe uma opção válida.\n" << endl;
                break;
        }
    } while(opcao != 4);
}

bool login(int tipoLogin, string usuario, string senha) {
    bool achou = false;
    
    // Procura se o usuario e senha existem na lista de Chefes
    if(tipoLogin == 0) {
        Chefe *chefe = new Chefe();
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
            telaChefe(chefe);
    }
    else {
        // Uma maneira de procurar todos os funcionarios
        // E examinar usuario e senha de cada funcionario
        for(auto funcionario:funcionarios)
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

bool realizarLogin(int tipoLogin, string usuario, string senha) {
    // Se conseguir fazer login
    
    if(login(tipoLogin, usuario, senha)) return true;
    // if(true) return true;
    
    // Se n conseguir fazer login vai exibir mensagem de erro e retornara para a Tela de Login
    cout << "Login inválida.\n" << endl;

    return false;
}

void telaLogin() {
    int tipoLogin;
    string usuario, senha;
    
    do {
        cout << "-----------------------Login------------------------" << endl;
        cout << "    0- Login Chefe" << endl;
        cout << "    1- Login Funcionário" << endl;
        cout << "    2- Voltar ao Menu Inicial" << endl;
        cin >> tipoLogin;

        switch (tipoLogin)
        {
            case 0:
            case 1:
                cout << "Informe o seu usuario:" << endl;
                cin >> usuario;

                cout << "Informe a sua senha:" << endl;
                cin >> senha;

                // Se n conseguir fazer login retorna para o menu de login
                if(!realizarLogin(tipoLogin, usuario, senha))
                    return;
                break;
            
            case 2:
                cout << "Voltando para a tela de login:" << endl;
                break;
            
            default:
                break;
        }
    } while(tipoLogin != 2);
}

void telaInicial() {
    int opcao;

    do {
        cout << "--------------------Menu Inicial--------------------" << endl;
        cout << "    0- Login" << endl;
        cout << "    1- Sair do menu" << endl;

        cout << "Informe a opção que deseja execultar:" << endl;
        cin >> opcao;

        switch (opcao) {
            case 0:
                telaLogin();
                break;
            
            case 1:
                cout << "Finalizando.\n" << endl;
                break;
            
            default:
                cout << "Informe uma opção válida.\n" << endl;
        }
    } while(opcao != 1);
}

int main() {
    
    telaInicial();
    
    cout << "Finalizando o programa.\n" << endl;
    
    return 0;
}