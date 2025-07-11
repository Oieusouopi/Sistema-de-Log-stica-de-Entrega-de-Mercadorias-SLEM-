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

        std::cout << "\n---------- MENU PEDIDOS ----------\n";
        std::cout << static_cast<char>(CRIAR_PEDIDO) << " -  Criar pedido\n";
        std::cout << static_cast<char>(EXCLUIR_PEDIDO) << " -  Excluir pedido\n";
        std::cout << static_cast<char>(LISTAR_TODOS_PEDIDOS) << " -  Listar todos pedidos\n";
        std::cout << static_cast<char>(VOLTAR_PARA_O_MENU_PRINCIPAL_PEDIDOS) << " -  Voltar para o menu principal\n";
        std::cout << "---------------------------------\n";

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

    if (localOrigem.getId() == -1) {
        return;
    }

    std::cout << "Selecione o local de destino do pedido: ";

    Local localDestino = LocalUtils::selecionarLocal(localService);

    if (localDestino.getId() == -1) {
        return;
    }

    std::cout << "Digite o peso do item de entrega: (Cancelar operação digite 0):";

    double pesoDoItem = 0;

    std::cin >> pesoDoItem;

    if (pesoDoItem == 0) {
        std::cout << "Operação cancelada" << std::endl;
        return;
    }

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

    std::cout << "Redirecionando para o menu pedidos..." << std::endl;
}

void PedidoController::excluir() {
    std::vector<Pedido> pedidos = pedidoService.listar();

    if (pedidos.empty()) {
        std::cout << "Sem pedido cadastrado para ser excluído" << std::endl;
    } else {

        std::cout << "\n-------------------------- LISTA DE PEDIDOS PARA SEREM EXCLUIDOS --------------------------\n";

        for (int i = 0; i < pedidos.size(); i++) {
            std::cout << (i + 1) << " - #" << pedidos[i].getId() << " | " <<  std::endl;
        }

        int opcao = 0;
        while (true) {
            std::cout << "Digite o número do pedido pra excluir (ou um valor inválido para cancelar): ";
            std::cin >> opcao;

            if (std::cin.fail() || opcao < 1 || opcao > pedidos.size()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Opção inválida. Tente novamente." << std::endl;
            } else {
                break;
            }
        }

        pedidoService.excluir(pedidos[opcao - 1].getId());

        std::cout << "Pedido excluído com sucesso" << std::endl;
    }

    std::cout << "Redirecionando para o menu do pedido..." << std::endl;
}

void PedidoController::listar() {

    std::vector<Pedido> pedidos = pedidoService.listar();

    if (pedidos.empty()) {
        std::cout << "Nenhum pedido cadastrado.\n";
        return;
    }

    std::cout << "\n------------------------------- LISTA DE PEDIDOS ---------------------------------\n";

    std::cout << std::left
              << std::setw(20) << "LOCAL DE ORIGEM"
              << std::setw(20) << "LOCAL DE DESTINO"
              << std::setw(15) << "PESO DO ITEM"
              << std::setw(20)  << "PLACA DO VEÍCULO VINCULADO" << std::endl;

    std::cout << std::string(80, '-') << '\n';

    for ( auto& pedido : pedidos) {
        Veiculo veiculo = veiculoService.buscarPorId(pedido.getVeiculoVinculadoId());
        char placa[8] = "Nenhum";
        if (veiculo.getId() != -1) {
            strcpy(placa, veiculo.getPlaca());
        }

        std::cout << std::left
                 << std::setw(20) << pedido.getLocalOrigem().getEndereco()
                 << std::setw(20) << pedido.getLocalDestino().getEndereco()
                 << std::setw(15) << pedido.getPesoItem()
                 << std::setw(20) << placa
                 << '\n';
    }

    std::cout << std::string(80, '-') << '\n';

    std::cout << "Redirecionando para o menu do pedido..." << std::endl;
}