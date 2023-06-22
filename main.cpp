#include <iostream>

using namespace std;

void telaChefe() {
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
                break;
            
            case 1:
                // funcionarios.map((funcionario) => return funcionario.dados)
                break;
            
            case 2:
                // Ler nome do funcionario
                // funcionario = funcionarios.search(nomeFuncionario)
                // print funcionario.horas.dados
                break;
            
            case 3:
                // Ler nome do funcionario
                // funcionario = funcionarios.search(nomeFuncionario)
                // realizar calculo do salário de funcionario com base em funcionario.horas.dados
                break;
            
            case 4:
                break;
            
            default:
                cout << "Informe uma opção válida.\n" << endl;
                break;
        }
    } while(opcao != 4);
}

void telaFuncionario() {
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
                break;
            
            case 1:
                // int salario = calcSalario(funcionario.dados)
                // print salario
                break;
            
            case 2:
                // int valorVenda // <= adicionar o valor da venda
                // funcionario.addVenda(valorVenda)
                break;
            
            case 3:
                // if(funcionario.isSupervisor)
                    // supervisor.funcionarios.map((funcionario) => return funcionario.vendas)
                // else
                    // funcionario.vendas
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
        // Uma maneira de procurar todos os chefes
        // E examinar usuario e senha de cada chefe

        // for(quant de chefes)
            // if (chefe->getUsuario == usuario && chefe->getSenha == senha)
                // achou = true

        // Se achar um chefe q os dados batem c os q foram passados, vamos para a tela do chefe
        // if(achou)
            // Tela Chefe
    }
    // Procura se o usuario e senha existem na lista de Funcionarios
    else {
        // Uma maneira de procurar todos os funcionarios
        // E examinar usuario e senha de cada funcionario

        // for(quant de Funcionarios)
            // if (funcionario->getUsuario == usuario && funcionario->getSenha == senha)
                // achou = true
        
        // Se achar um chefe q os dados batem c os q foram passados, vamos para a tela do funcionario
        // if(achou)
            // Tela Funcionario
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