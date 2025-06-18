
#include <iostream>
#include "Utils/EnumMenu.h"

char teclaGlobal;

void exibirBoasVindas();
void exibirDespedida();

void menuPrincipal();

void menuLocal();
void menuVeiculo();
void menuPedidos();
void menuRota();

int main() {

    exibirBoasVindas();
    menuPrincipal();

    return 0;
}

void menuPrincipal() {
    teclaGlobal = '\0';
    bool sairDoSistema = false;

    std::cin >> teclaGlobal;

    while (!sairDoSistema) {
        switch (teclaGlobal) {
            case EXIR_MENU_LOCAL:
                break;
            case EXIBIR_MENU_VEICULO:
                break;
            case EXIBIR_MENU_PEDIDO:
                break;
            case EXIBIR_MENU_ROTA:
                break;
            case EXIBIR_MENU_BANCO:
                break;
            case FINALIZAR_PROGRAMA:
                exibirDespedida();
                sairDoSistema = true;
                break;
            default:
                break;
        }
    }

}

void menuLocal() {
    teclaGlobal = '\0';

    std::cin >> teclaGlobal;
    switch (teclaGlobal) {
        case CRIAR_LOCAL:
            break;
        case EXCLUIR_LOCAL:
            break;
        case LISTAR_TODOS_LOCAIS:
            break;
        case VOLTAR_PARA_O_MENU_PRINCIPAL_LOCAL:
            break;
        default:
            break;
    }
}

void menuVeiculo() {
    teclaGlobal = '\0';

    std::cin >> teclaGlobal;
    switch (teclaGlobal) {
        case CRIAR_VEICULO:
            break;
        case EXCLUIR_VEICULO:
            break;
        case LISTAR_TODOS_VEICULOS:
            break;
        case VOLTAR_PARA_O_MENU_PRINCIPAL_VEICULO:
            break;
        default:
            break;
    }
}

void menuPedidos() {
    teclaGlobal = '\0';

    std::cin >> teclaGlobal;
    switch (teclaGlobal) {
        case CRIAR_PEDIDO:
            break;
        case EXIBIR_PEDIDO:
            break;
        case LISTAR_TODOS_PEDIDOS:
            break;
        case VOLTAR_PARA_O_MENU_PRINCIPAL_PEDIDOS:
            break;
        default:
            break;
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

    std::cin >> teclaGlobal;
    switch (teclaGlobal) {
        case SALVAR_TODOS_DADOS:
            break;
        case RESTAURAR_DADOS_DE_BACKUPS_ANTIGOS:
            break;
        case VOLTAR_PARA_O_MENU_PRINCIPAL_BANCO:
            break;
        default:
            break;
    }

}

void exibirBoasVindas()
{
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

void exibirDespedida()
{
    std::string linha(100, '-');

    std::cout << linha << std::endl;
    std::cout << std::string(30, ' ') << "OBRIGADO POR UTILIZAR NOSSO SISTEMA!" << std::endl;
    std::cout << linha << std::endl;
    std::cout << std::endl;
    std::cout << "Esperamos ter ajudado no gerenciamento de suas entregas.\n";
    std::cout << "Volte sempre que precisar. Até a próxima!" << std::endl;
    std::cout << std::endl;
}
