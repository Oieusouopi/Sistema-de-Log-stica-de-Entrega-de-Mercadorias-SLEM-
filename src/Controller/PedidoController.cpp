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

PedidoController::PedidoController(PedidoService &pedidoService, LocalService &localService, VeiculoService &veiculoService): pedidoService(pedidoService), localService(localService), veiculoService(veiculoService) {}


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
                excluir();
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

    switch (pedidoService.criar(pedido, veiculoService)) {
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

    std::cout << "Redirecionando para o menu pedidos..." << std::endl;
}

void PedidoController::excluir() {
    std::vector<Pedido> pedidos = pedidoService.listar();

    if (pedidos.empty()) {
        std::cout << "Sem pedido cadastrado para ser excluído" << std::endl;
    } else {

        std::cout << "\n-------------------------- LISTA DE PEDIDOS PARA SEREM EXCLUIDOS --------------------------\n";

        for (int i = 0; i < pedidos.size(); i++) {
            std::cout << (i + 1) << " - #" << pedidos[i].id << " | " <<  std::endl;
        }

        int opcao = 0;
        while (true) {
            std::cout << "Digite o número do pedido pra excluir: ";
            std::cin >> opcao;

            if (std::cin.fail() || opcao < 1 || opcao > pedidos.size()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Opção inválida. Tente novamente." << std::endl;
            } else {
                break;
            }
        }

        if (pedidoService.excluir(pedidos[opcao - 1].id)) {
            std::cout << "Pedido excluído com sucesso" << std::endl;
        } else {
            std::cout << "Aconteceu algum erro ao excluir o veículo" << std::endl;
        }
    }

    std::cout << "Redirecionando para o menu do pedido..." << std::endl;
}

void PedidoController::listar() {

    std::cout << "\n-------------------------- LISTA DE PEDIDOS ---------------------------\n";

    std::cout << std::left
              << std::setw(20) << "LOCAL DE ORIGEM"
              << std::setw(20) << "LOCAL DE DESTINO"
              << std::setw(10) << "PESO DO ITEM";

    std::cout << std::string(72, '-') << '\n';

    std::vector<Pedido> pedidos = pedidoService.listar();

    for (const auto& pedido : pedidos) {
        std::cout << std::left
                 << std::setw(10) << pedido.localOrigem.getEndereco()
                 << std::setw(20) << pedido.localDestino.getEndereco()
                 << std::setw(12) << pedido.pesoDoItem
                 << '\n';
    }

    std::cout << std::string(72, '-') << '\n';

    std::cout << "Redirecionando para o menu do pedido..." << std::endl;
}