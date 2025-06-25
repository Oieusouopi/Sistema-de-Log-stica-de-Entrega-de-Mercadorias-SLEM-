//
// Created by eec on 18/06/25.
//

#include "VeiculoController.h"

#include <iostream>

#include "../Utils/EnumMenu.h"
#include "../Utils/ExibirMensagem.h"

VeiculoController::VeiculoController(VeiculoService &veiculoService): veiculoService(veiculoService) {}

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
                criar();
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

    std::cout << "\n----- CRIAÇÃO DE UM VEICULO -----\n";
    std::cout << "Para criar um veículo vamos precisar de algumas informações";
    std::cout << "se você der alguma informação que não é certa vai pedir a informação novamente";
    std::cout << "se você quiser cancelar a qualquer momento a criação do veiculo escreva 'CANCELAR'";
    std::cout << "-----------------------------\n";

    std::cout << "Qual a placa deste veiculo ? " << std::endl;

    std::string placa;

    std::cin >> placa;

    std::cout << "Qual o modelo deste veiculo ? " << std::endl;

    std::string modelo;

    std::cin >> modelo;

    // Vai ser trocado pelo metodo se selecionar um local do localService
    Local localSelecionado = selecionarLocal();

    Veiculo veiculo = Veiculo(placa, modelo, localSelecionado);

    veiculoService.criar(veiculo);
}

Local VeiculoController::selecionarLocal() {
    std::vector<Local> locaisDisponiveis = {
        Local("São Paulo"), Local("Belo Horizonte"), Local("Rio de Janeiro")
    };

    if (locaisDisponiveis.empty()) {
        std::cout << "Nenhum local cadastrado";
        Local("Não definido");
    }

    std::cout << "Selecione o local atual do veículo: " << std::endl;
    int itemSelecionado = 0;
    for (int i = 1; i < locaisDisponiveis.size(); i++) {
        std::cout << i << locaisDisponiveis[i].nome << std::endl;
    }

}


void VeiculoController::listar() {

}

void VeiculoController::excluir() {

}

void VeiculoController::updateLocalAtual() {

}

void VeiculoController::updateStatus() {

}




