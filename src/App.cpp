#include "Controller/LocalController.h"
#include "Controller/PedidoController.h"
#include "Controller/VeiculoController.h"
#include "Service/LocalService.h"
#include "Service/PedidoService.h"
#include "Service/VeiculoService.h"
#include "App.h"

#include <iostream>

#include "Controller/RotaController.h"
#include "Service/RotaService.h"
#include "Utils/EnumMenu.h"
#include "Utils/ExibirMensagem.h"
//
// Created by eec on 19/06/25.
//

class AppImpl {
private:
    VeiculoService veiculoService;
    LocalService localService;
    PedidoService pedidoService;
    RotaService rotaService;

    VeiculoController veiculoController;
    LocalController localController;
    PedidoController pedidoController;
    RotaController rotaController;

public:

    char teclaGlobal;

    AppImpl()
        : veiculoController(veiculoService, localService),
          localController(localService),
          pedidoController(pedidoService),
          rotaController(rotaService) {}

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
                ExibirMensagem::exibirMensagemDeErro();
                continue;
            }

            teclaGlobal = entrada[0];

            switch (teclaGlobal) {
                case EXIBIR_MENU_LOCAL:
                    localController.menu();
                    break;
                case EXIBIR_MENU_VEICULO:
                    veiculoController.menu();
                    break;
                case EXIBIR_MENU_PEDIDO:
                    pedidoController.menu();
                    break;
                case EXIBIR_MENU_ROTA:
                    rotaController.menu();
                    break;
                case EXIBIR_MENU_BANCO:
                    // menuBanco();
                    break;
                case FINALIZAR_PROGRAMA:
                    ExibirMensagem::exibirDespedida();
                    exit(1);
                default:
                    ExibirMensagem::exibirMensagemDeErro();
                    break;
            }
        }

    }
};

void App::executar() {
    AppImpl app;
    app.menuPrincipal();
}