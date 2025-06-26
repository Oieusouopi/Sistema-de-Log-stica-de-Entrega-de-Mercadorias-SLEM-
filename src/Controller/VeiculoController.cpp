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
    std:: string placa;
    std:: string nomeLocal;
    int x, y;

    cout << "Digite a placa do veículo: ";
    cin >> placa;

    cout << "Digite o nome do novo local: ";
    cin.ignore();
    getline(cin, nomeLocal);

    cout << "Digite a coordenada X: ";
    cin >> x;

    cout << "Digite a coordenada Y: ";
    cin >> y;

    Local novoLocal;
    novoLocal.nome = nomeLocal;
    novoLocal.x = x;
    novoLocal.y = y;

    veiculoService.updateLocalAtual(placa, novoLocal);
    cout << "Local atual do veículo atualizado com sucesso!" << endl;

}

void VeiculoController::updateStatus() {
    std::string placa;
    int opcao;
    bool status;

    cout << "Digite a placa do veículo: ";
    cin >> placa;

    cout << "Digite o novo status (1 - Disponível, 0 - Ocupado): ";
    cin >> opcao;

    if (opcao == 1)
        status = true;
    else if (opcao == 0)
        status = false;
    else {
        cout << "Opção inválida." << endl;
        return;
    }

    veiculoService.updateStatus(placa, status);
    cout << "Status atualizado com sucesso!" << endl;
}




