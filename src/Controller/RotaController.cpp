#include "RotaController.h"
#include "../Service/PedidoService.h"
#include "../Service/VeiculoService.h"
#include <iostream>
#include <limits>
//
// Created by eec on 18/06/25.
//
RotaController::RotaController(RotaService &rotaService, PedidoService &pedidoService, VeiculoService &veiculoService): 
    rotaService(rotaService), pedidoService(pedidoService), veiculoService(veiculoService) {}

void RotaController::menu() {
    char teclaGlobal = '\0';
    std::string entrada;

    while (true) {
        std::cout << "\n---------- MENU ROTAS ----------\n";
        std::cout << "1 - Mostrar rota de um pedido\n";
        std::cout << "2 - Voltar para o menu principal\n";
        std::cout << "--------------------------------\n";

        std::cin >> entrada;
        teclaGlobal = entrada[0];

        switch (teclaGlobal) {
            case '1':
                mostrarRotaPedido();
                break;
            case '2':
                return;
            default:
                std::cout << "Opção inválida. Tente novamente.\n";
                break;
        }
    }
}

void RotaController::mostrarRotaPedido() {
    std::vector<Pedido> pedidos = pedidoService.listar();
    
    if (pedidos.empty()) {
        std::cout << "Nenhum pedido cadastrado.\n";
        return;
    }

    // Listar pedidos disponíveis
    std::cout << "\n--- PEDIDOS DISPONÍVEIS ---\n";
    for (size_t i = 0; i < pedidos.size(); ++i) {
        std::cout << (i + 1) << " - Pedido ID: " << pedidos[i].getId()
                  << " | Origem: " << pedidos[i].getLocalOrigem().getEndereco()
                  << " | Destino: " << pedidos[i].getLocalDestino().getEndereco() << std::endl;
    }

    int opcao = 0;
    while (true) {
        std::cout << "\nDigite o número do pedido para ver a rota: ";
        std::cin >> opcao;

        if (std::cin.fail() || opcao < 1 || static_cast<size_t>(opcao) > pedidos.size()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Opção inválida. Tente novamente.\n";
        } else {
            break;
        }
    }

    // Mostrar rota do pedido selecionado
    std::vector<Veiculo> veiculos = veiculoService.listar();
    rotaService.mostrarRota(pedidos[opcao - 1]);
}
