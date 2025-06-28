//
// Created by eec on 18/06/25.
//

#include "VeiculoController.h"

#include <iomanip>
#include <iostream>
#include <limits>

#include "../Service/LocalService.h"
#include "../Utils/EnumMenu.h"
#include "../Utils/EnumStatusVeiculoUtils.h"
#include "../Utils/ExibirMensagem.h"

VeiculoController::VeiculoController(VeiculoService &veiculoService, LocalService &localService): veiculoService(veiculoService), localService(localService) {}

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
                excluir();
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
    // std::cout << "se você quiser cancelar a qualquer momento a criação do veiculo escreva ''" << std::endl;
    std::cout << "-----------------------------\n";

    std::string placa;

    std::cout << "Qual a placa deste veiculo: ";

    std::cin >> placa;

    std::cout << "Qual o modelo deste veiculo: ";

    std::string modelo;

    std::cin.ignore();
    getline(std::cin, modelo);

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

    std::cout << "Redirecionando para o menu veículo..." << std::endl;
}

Local VeiculoController::selecionarLocal() {
    std::vector<Local> locaisDisponiveis = localService.listar();

    if (locaisDisponiveis.empty()) {
        std::cout << "Nenhum local cadastrado";
        Local("Não definido");
    }

    std::cout << "Selecione o local atual do veículo: " << std::endl;
    for (int i = 0; i < locaisDisponiveis.size(); i++) {
        std::cout << (i + 1) << " - " << locaisDisponiveis[i].getEndereco() << std::endl;
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

    std::cout << "\n-------------------------- LISTA DE VEÍCULOS ---------------------------\n";

    std::cout << std::left
              << std::setw(10) << "PLACA"
              << std::setw(20) << "MODELO"
              << std::setw(12) << "STATUS"
              << std::setw(30) << "LOCAL"  << "\n";

    std::cout << std::string(72, '-') << '\n';

    std::vector<Veiculo> veiculos = veiculoService.listar();

    for (const auto& v : veiculos) {
        std::cout << std::left
                  << std::setw(10) << v.placa
                  << std::setw(20) << v.modelo
                  << std::setw(12) << statusToString(v.status)
                  << std::setw(30) << v.localAtual.getEndereco()
                  << '\n';
    }

    std::cout << std::string(72, '-') << '\n';

    std::cout << "Redirecionando para o menu do veículo..." << std::endl;
}

void VeiculoController::excluir() {
    std::vector<Veiculo> veiculos = veiculoService.listar();

    if (veiculos.empty()) {
        std::cout << "Sem veículo nenhum cadastrado para ser excluído" << std::endl;
    } else {

        std::cout << "\n-------------------------- LISTA DE VEÍCULOS PARA SEREM EXCLUIDOS --------------------------\n";

        for (int i = 0; i < veiculos.size(); i++) {
            std::cout << (i + 1) << " - " << veiculos[i].placa << " | " << veiculos[i].modelo <<  std::endl;
        }

        int opcao = 0;
        while (true) {
            std::cout << "Digite o número do veículo pra excluir: ";
            std::cin >> opcao;

            if (std::cin.fail() || opcao < 1 || opcao > veiculos.size()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Opção inválida. Tente novamente." << std::endl;
            } else {
                break;
            }
        }

        if (veiculoService.excluir(veiculos[opcao - 1].placa)) {
            std::cout << "Veículo excluído com sucesso" << std::endl;
        } else {
            std::cout << "Aconteceu algum erro ao excluir o veículo" << std::endl;
        }
    }

    std::cout << "Redirecionando para o menu veículo...";
}

void VeiculoController::updateLocalAtual() {

}

void VeiculoController::updateStatus() {

}




