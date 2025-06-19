//
// Created by eec on 18/06/25.
//
#include "PedidoController.h"

#include <iostream>

#include "../Utils/EnumMenu.h"
#include "../Utils/ExibirMensagem.h"

PedidoController::PedidoController(PedidoService &pedidoService): pedidoService(pedidoService) {}


void PedidoController::menu() {
    char teclaGlobal = '\0';
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
            ExibirMensagem::exibirMensagemDeErro();
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
                ExibirMensagem::exibirMensagemDeErro();
                break;
        }

    }
}

void PedidoController::criar() {

}

void PedidoController::excluir() {

}

void PedidoController::listar() {

}