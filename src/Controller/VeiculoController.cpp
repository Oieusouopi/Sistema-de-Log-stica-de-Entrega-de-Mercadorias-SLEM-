//
// Created by eec on 18/06/25.
//

#include "VeiculoController.h"
#include "LocalController.h"

#include <iostream>
#include <limits>

#include "../Service/LocalService.h"
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
        std::cout << static_cast<char>(ATUALIZAR_VEICULOS) << " -  Atualizar Veiculos\n";
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
            case ATUALIZAR_VEICULOS:
                updateLocalAtual();
                updateStatus();
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
            std::cout << "Veiculo criado com sucesso" << std::endl;git
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
    std::string placa;

    std::cout << "Digite a placa do veículo: ";
    std::cin >> placa;

    std::vector<Local> locais = {
        Local("Minas Gerais", 0, 0),
        Local("São Paulo", 10, 5),
        Local("Rio de Janeiro", -8, 4),
        Local("Bahia", 15, -3)
    };

    std::cout << "\nLocais disponíveis:\n";
    for (int i = 0; i < locais.size(); ++i) {
        std::cout << i + 1 << " - " << locais[i].getEndereco()
                  << " (" << locais[i].getX() << ", " << locais[i].getY() << ")\n";
    }

    int escolha;
    std::cout << "Digite o número do local desejado: ";
    std::cin >> escolha;

    if (escolha < 1 || escolha > locais.size()) {
        std::cout << "Opção inválida!" << std::endl;
        return;
    }

    Local novoLocal = locais[escolha - 1];

    veiculoService.updateLocalAtual(placa, novoLocal);

    std::cout << "Local atual do veículo atualizado com sucesso!" << std::endl;
}

void VeiculoController::updateStatus() {

    std::cout << "Digite o novo status (1 - Disponível, 0 - Ocupado): ";
    std::cin >> opcao;

    if (opcao == 1)
        status = true;
    else if (opcao == 0)
        status = false;
    else {
        std::cout << "Opção inválida." << std::endl;
        return;
    }

    veiculoService.updateStatus(placa, status);
    std::cout << "Status atualizado com sucesso!" << std::endl;
}




