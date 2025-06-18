
#include <iostream>
#include "Utils/EnumMenu.h"

void exibirBoasVindas();
void exibirDespedida();

void menuPrincipal();

void menuLocal();
void menuVeiculo();
void menuPedidos();
void menuRota();
void menuBanco();

void exibirMensagemDeErro();

char teclaGlobal;

int main() {

    exibirBoasVindas();
    menuPrincipal();

    return 0;
}

void menuPrincipal() {
    teclaGlobal = '\0';
    std::string entrada;
    bool sairDoSistema = false;

    while (!sairDoSistema) {
        std::cout << "\n----- MENU PRINCIPAL -----\n";
        std::cout << static_cast<char>(EXIBIR_MENU_LOCAL) << " -  Ir para o menu local\n";
        std::cout << static_cast<char>(EXIBIR_MENU_VEICULO) << " -  Ir para o menu veiculo\n";
        std::cout << static_cast<char>(EXIBIR_MENU_PEDIDO) << " -  Ir para o menu pedido\n";
        std::cout << static_cast<char>(EXIBIR_MENU_ROTA) << " -  Ir para o menu rota\n";
        std::cout << static_cast<char>(EXIBIR_MENU_BANCO) << " -  Ir para o menu banco\n";
        std::cout << static_cast<char>(FINALIZAR_PROGRAMA) << " -  Finalizar o programa\n";
        std::cout << "-----------------------------\n";

        std::cin >> entrada;

        if (entrada.length() != 1) {
            exibirMensagemDeErro();
            continue;
        }

        teclaGlobal = entrada[0];

        switch (teclaGlobal) {
            case EXIBIR_MENU_LOCAL:
                menuLocal();
                break;
            case EXIBIR_MENU_VEICULO:
                menuVeiculo();
                break;
            case EXIBIR_MENU_PEDIDO:
                menuPedidos();
                break;
            case EXIBIR_MENU_ROTA:
                menuRota();
                break;
            case EXIBIR_MENU_BANCO:
                menuBanco();
                break;
            case FINALIZAR_PROGRAMA:
                exibirDespedida();
                exit(1);
            default:
                exibirMensagemDeErro();
                break;
        }
    }

}

void menuLocal() {
    teclaGlobal = '\0';
    std::string entrada;

    while (true) {

        std::cout << "\n----- MENU LOCAL -----\n";
        std::cout << static_cast<char>(CRIAR_LOCAL) << " -  Criar local\n";
        std::cout << static_cast<char>(EXCLUIR_LOCAL) << " -  Excluir local\n";
        std::cout << static_cast<char>(LISTAR_TODOS_LOCAIS) << " -  Listar todos locais\n";
        std::cout << static_cast<char>(VOLTAR_PARA_O_MENU_PRINCIPAL_LOCAL) << " -  Voltar para o menu principal\n";
        std::cout << "-----------------------------\n";

        std::cin >> entrada;

        if (entrada.length() != 1) {
            exibirMensagemDeErro();
            continue;
        }

        teclaGlobal = entrada[0];

        switch (teclaGlobal) {
            case CRIAR_LOCAL:
                break;
            case EXCLUIR_LOCAL:
                break;
            case LISTAR_TODOS_LOCAIS:
                break;
            case VOLTAR_PARA_O_MENU_PRINCIPAL_LOCAL:
                return;
            default:
                exibirMensagemDeErro();
                break;
        }
    }
}

void menuVeiculo() {
    teclaGlobal = '\0';
    std::string entrada;

    while (true) {

        std::cout << "\n----- MENU VEICULO -----\n";
        std::cout << static_cast<char>(CRIAR_VEICULO) << " -  Criar Veiculo\n";
        std::cout << static_cast<char>(EXCLUIR_VEICULO) << " -  Excluir Veiculo\n";
        std::cout << static_cast<char>(LISTAR_TODOS_VEICULOS) << " -  Listar todos veiculos\n";
        std::cout << static_cast<char>(VOLTAR_PARA_O_MENU_PRINCIPAL_VEICULO) << " -  Voltar para o menu principal\n";
        std::cout << "-----------------------------\n";

        std::cin >> entrada;

        if (entrada.length() != 1) {
            exibirMensagemDeErro();
            continue;
        }

        teclaGlobal = entrada[0];

        switch (teclaGlobal) {
            case CRIAR_VEICULO:

                break;
            case EXCLUIR_VEICULO:
                break;
            case LISTAR_TODOS_VEICULOS:
                break;
            case VOLTAR_PARA_O_MENU_PRINCIPAL_VEICULO:
                return;
            default:
                exibirMensagemDeErro();
                break;
        }

    }
}

void menuPedidos() {
    teclaGlobal = '\0';
    std::string entrada;

    while (true) {

        std::cout << "\n----- MENU PEDIDOS -----\n";
        std::cout << static_cast<char>(CRIAR_PEDIDO) << " -  Criar pedido\n";
        std::cout << static_cast<char>(EXCLUIR_PEDIDO) << " -  Excluir pedido\n";
        std::cout << static_cast<char>(LISTAR_TODOS_PEDIDOS) << " -  Listar todos pedidos\n";
        std::cout << static_cast<char>(VOLTAR_PARA_O_MENU_PRINCIPAL_PEDIDOS) << " -  Voltar para o menu principal\n";
        std::cout << "-----------------------------\n";

        std::cin >> entrada;

        if (entrada.length() != 1) {
            exibirMensagemDeErro();
            continue;
        }

        teclaGlobal = entrada[0];

        switch (teclaGlobal) {
            case CRIAR_PEDIDO:
                break;
            case EXCLUIR_PEDIDO:
                break;
            case LISTAR_TODOS_PEDIDOS:
                break;
            case VOLTAR_PARA_O_MENU_PRINCIPAL_PEDIDOS:
                return;
            default:
                exibirMensagemDeErro();
                break;
        }

    }
}


// Falta pensar sobre essa implementação
void menuRota() {
    //
    // std::cin >> teclaGlobal;
    // switch (teclaGlobal) {
    //     case TECLA_1:
    //         break;
    //     case TECLA_2:
    //         break;
    //     case TECLA_3:
    //         break;
    //     case TECLA_4:
    //         break;
    //     case TECLA_5:
    //         break;
    //     case TECLA_6:
    //         break;
    //     default:
    //         break;
    // }

}

void menuBanco() {
    teclaGlobal = '\0';
    std::string entrada;

    while (true) {

        std::cout << "\n----- MENU BANCO -----\n";
        std::cout << static_cast<char>(SALVAR_TODOS_DADOS) << " -  Salvar todos dados\n";
        std::cout << static_cast<char>(RESTAURAR_DADOS_DE_BACKUPS_ANTIGOS) << " -  Restaurar dados de backups antigos\n";
        std::cout << static_cast<char>(VOLTAR_PARA_O_MENU_PRINCIPAL_BANCO) << " -  Voltar para o menu principal\n";
        std::cout << "-----------------------------\n";

        std::cin >> entrada;

        if (entrada.length() != 1) {
            exibirMensagemDeErro();
            continue;
        }

        teclaGlobal = entrada[0];

        switch (teclaGlobal) {
            case SALVAR_TODOS_DADOS:
                break;
            case RESTAURAR_DADOS_DE_BACKUPS_ANTIGOS:
                break;
            case VOLTAR_PARA_O_MENU_PRINCIPAL_BANCO:
                return;
            default:
                exibirMensagemDeErro();
                break;
        }

    }
}

void exibirBoasVindas() {
    std::string linha(100, '-'); // Linha com 100 hifens

    std::cout << linha << std::endl;
    std::cout << std::string(20, ' ') << "BEM-VINDO AO SISTEMA DE LOGÍSTICA DE ENTREGA DE MERCADORIAS" << std::endl;
    std::cout << linha << std::endl;
    std::cout << std::endl;
    std::cout << "Aqui o usuário (gerente) consegue gerenciar seus pedidos, veículos, locais do seu sistema\n";
    std::cout << "e trazer mais confiança para o seu cliente!" << std::endl;
    std::cout << "Para começar, vamos para a área de MENU." << std::endl;
    std::cout << std::endl;
}

void exibirDespedida() {
    std::string linha(100, '-');

    std::cout << linha << std::endl;
    std::cout << std::string(30, ' ') << "OBRIGADO POR UTILIZAR NOSSO SISTEMA!" << std::endl;
    std::cout << linha << std::endl;
    std::cout << std::endl;
    std::cout << "Esperamos ter ajudado no gerenciamento de suas entregas.\n";
    std::cout << "Volte sempre que precisar. Até a próxima!" << std::endl;
    std::cout << std::endl;
}

void exibirMensagemDeErro() {

    std::string linha(30, '-');

    std::cout << linha << std::endl;
    std::cout << std::string(5, ' ') << "Essa tecla não existe" << std::endl;
    std::cout << linha << std::endl;

}