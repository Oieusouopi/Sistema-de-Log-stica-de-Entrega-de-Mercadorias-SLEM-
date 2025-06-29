//
// Created by eec on 18/06/25.
//
#include "PedidoController.h"

#include <iomanip>
#include <iostream>

#include "../Service/LocalService.h"
#include "../Utils/EnumMenu.h"
#include "../Utils/ExibirMensagem.h"
#include "../Utils/LocalUtils.h"

PedidoController::PedidoController(PedidoService &pedidoService, LocalService &localService): pedidoService(pedidoService), localService(localService) {}


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
                criar();
                break;
            case EXCLUIR_PEDIDO:
                break;
            case LISTAR_TODOS_PEDIDOS:
                listar();
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

    std::cout << "\n----- CRIAÇÃO DE UM PEDIDO -----\n";
    std::cout << "Para criar um pedido vamos precisar de algumas informações" << std::endl;

    std::cout << "Selecione o local de origem do pedido: ";

    Local localOrigem = LocalUtils::selecionarLocal(localService);

    std::cout << "Selecione o local de destino do pedido: ";

    Local localDestino = LocalUtils::selecionarLocal(localService);

    std::cout << "Digite o peso do item de entrega: ";

    double pesoDoItem = 0;

    std::cin >> pesoDoItem;

    Pedido pedido = Pedido(localOrigem, localDestino, pesoDoItem);

    switch (pedidoService.criar(pedido)) {
        case SUCESSO_CRIACAO_DO_PEDIDO:
            std::cout << "Pedido criado com sucesso" << std::endl;
            break;
        case ERRO_CRIACAO_DO_PEDIDO_COM_PESO_NEGATIVO:
            std::cout << "Não é possivel criar pedido com peso negativo" << std::endl;
            break;
        case ERRO_CRIACAO_DO_PEDIDO_SEM_LOCAL:
            std::cout << "Não é possivel criar pedido sem local de origem ou local de destino" << std::endl;
            break;
    }

    std::cout << "Redirecionando para o menu pedidos...";
}

void PedidoController::excluir() {

}

void PedidoController::listar() {

    std::cout << "\n-------------------------- LISTA DE PEDIDOS ---------------------------\n";

    std::cout << std::left
              << std::setw(10) << "PLACA"
              << std::setw(20) << "MODELO"
              << std::setw(12) << "STATUS"
              << std::setw(30) << "LOCAL"  << "\n";

}