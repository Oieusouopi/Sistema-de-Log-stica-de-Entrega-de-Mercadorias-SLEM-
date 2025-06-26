//
// Created by eec on 18/06/25.
//

#include "VeiculoController.h"

#include <iomanip>
#include <iostream>
#include <limits>

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
                listar();
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
    std::cout << "Para criar um veículo vamos precisar de algumas informações" << std::endl;
    std::cout << "se você der alguma informação que não é certa vai pedir a informação novamente" << std::endl;
    std::cout << "se você quiser cancelar a qualquer momento a criação do veiculo escreva 'CANCELAR'" << std::endl;
    std::cout << "-----------------------------\n";

    std::cout << "Qual a placa deste veiculo: ";

    std::string placa;

    std::cin >> placa;

    std::cout << "Qual o modelo deste veiculo: ";

    std::string modelo;

    std::cin.ignore();
    getline(std::cin, modelo);

    // Vai ser trocado pelo metodo se selecionar um local do localService
    Local localSelecionado = selecionarLocal();

    Veiculo veiculo = Veiculo(placa, modelo, localSelecionado);

    EnumResultadoCriacaoVeiculo resultado = veiculoService.criar(veiculo);

    switch (resultado) {
        case SUCESSO:
            std::cout << "Veiculo criado com sucesso" << std::endl;
            break;
        default:
            std::cout << "Veiculo não criado aconteceu algum erro inesperado" << std::endl;
        break;
    }

    std::cout << "Redirecionando para o menu principal...";
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
    for (int i = 1; i < locaisDisponiveis.size(); i++) {
        std::cout << i << " - " << locaisDisponiveis[i].getEndereco() << std::endl;
    }

    int opcao = 0;
    while (true) {
        std::cout << "Digite o número da opção: ";
        std::cin >> opcao;

        if (std::cin.fail() || opcao < 1 || opcao > locaisDisponiveis.size()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Opção inválida. Tente novamente." << std::endl;
        } else {
            break;
        }
    }

    return locaisDisponiveis[opcao - 1];
}


void VeiculoController::listar() {

    std::cout << "\n-------------------------- LISTA DE VEÍCULOS --------------------------\n";

    std::cout << std::left
              << std::setw(10) << "PLACA"
              << std::setw(20) << "MODELO"
              << std::setw(12) << "STATUS"
              << std::setw(30) << "LOCAL"  << "\n";

    std::cout << std::string(72, '-') << '\n';

    // std::vector<Veiculo> veiculos = veiculoService.listar();
    std::vector<Veiculo> veiculos = {Veiculo("Veiculo_1"), Veiculo(), Veiculo()};


}

void VeiculoController::excluir() {

}

void VeiculoController::updateLocalAtual() {

}

void VeiculoController::updateStatus() {

}




