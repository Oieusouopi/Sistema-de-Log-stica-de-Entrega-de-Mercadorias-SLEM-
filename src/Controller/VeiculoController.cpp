//
// Created by eec on 18/06/25.
//

#include "VeiculoController.h"
#include "LocalController.h"

#include <iostream>

#include "../Service/LocalService.h"
#include "../Utils/EnumMenu.h"
#include "../Utils/ExibirMensagem.h"
using namespace std;

void VeiculoController::menu() {
    char teclaGlobal = '\0';
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
            ExibirMensagem::exibirMensagemDeErro();
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
                ExibirMensagem::exibirMensagemDeErro();
                break;
        }

    }
}

void VeiculoController::criar() {

}

void VeiculoController::listar() {

}

void VeiculoController::excluir() {

}

void VeiculoController::updateLocalAtual() {

    std::string placa;
    cout << "Digite a placa do veiculo" << endl;

    cin >> placa;

    Veiculo veiculoAchado = veiculoService.acharVeiculoPlaca(placa);

    cout << "Selecione o local novo do veiculo: ";

    std::vector<Local> locais = {Local("Belo horizonte"), Local("São paulo"), Local("Vitoria") };

    for (int i = 0; i < locais.size(); i++) {
        cout << i << " - " << locais[i].nome << endl;
    }



    // pegar id veiculo
    // ver se o veiculo existe
    // se existe segue, se não, erro;
    // pegar id unico do local;
    // ver se o id existe;
}

void VeiculoController::updateStatus() {

}




