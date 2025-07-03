//
// Created by eec on 18/06/25.
//

#include "VeiculoController.h"
#include "../Service/PedidoService.h"

#include <iomanip>
#include <iostream>
#include <limits>

#include "../Service/LocalService.h"
#include "../Utils/EnumMenu.h"
#include "../Utils/EnumStatusVeiculoUtils.h"
#include "../Utils/ExibirMensagem.h"
#include "../Utils/InputUtils.h"
#include "../Utils/LocalUtils.h"

VeiculoController::VeiculoController(VeiculoService &veiculoService, LocalService &localService, PedidoService &pedidoService): veiculoService(veiculoService), localService(localService), pedidoService(pedidoService) {}

void VeiculoController::menu() {
    char teclaGlobal = '\0';
    std::string entrada;

    while (true) {

        std::cout << "\n--------- MENU VEICULO ---------\n";
        std::cout << static_cast<char>(CRIAR_VEICULO) << " -  Criar Veiculo\n";
        std::cout << static_cast<char>(EXCLUIR_VEICULO) << " -  Excluir Veiculo\n";
        std::cout << static_cast<char>(LISTAR_TODOS_VEICULOS) << " -  Listar todos veiculos\n";
        std::cout << static_cast<char>(ATUALIZAR_VEICULOS) << " -  Atualizar Veiculos\n";
        std::cout << static_cast<char>(VOLTAR_PARA_O_MENU_PRINCIPAL_VEICULO) << " -  Voltar para o menu principal\n";
        std::cout << "--------------------------------\n";

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

    std::cout << "\n------------------- CRIAÇÃO DE UM VEICULO ------------------------\n";
    std::cout << "Para criar um veículo vamos precisar de algumas informações" << std::endl;
    std::cout << "se você der alguma informação que não é certa vai pedir a informação novamente" << std::endl;
    std::cout << "---------------------------------------------------------------------\n";

    std::cin.ignore();

    std::string placaStr;
    if (!lerStringComTamanhoExato("Qual a placa deste veículo (7 caracteres) (Cancelar operação digite 0): ", placaStr, 7)) {
        std::cout << "Operação cancelada" << std::endl;
        return;
    }

    std::string modeloStr;
    if (!lerStringComTamanhoMaximo("Qual o modelo deste veículo (até 30 caracteres) (Cancelar operação digite 0): ", modeloStr, 30)) {
        std::cout << "Operação cancelada" << std::endl;
        return;
    };

    char placa[7];
    char modelo[30];

    std::strncpy(placa, placaStr.c_str(), 7);
    std::strncpy(modelo, modeloStr.c_str(), 30);

    Local localSelecionado = LocalUtils::selecionarLocal(localService);

    Veiculo veiculo = Veiculo(placa, modelo, localSelecionado.getId());


    EnumResultadoCriacaoVeiculo resultado = veiculoService.criar(veiculo);
    switch (resultado) {
        case SUCESSO_CRIACAO_DO_VEICULO:
            std::cout << "Veiculo criado com sucesso" << std::endl;
            break;
        case PLACA_DUPLICADA:
            std::cout << "Veículo com placa duplicada não é possivel criar" << std::endl;
            break;
        case SEM_LOCAL_CADASTRADO:
            std::cout << "Sem local cadastrado não é possivel criar um veículo" << std::endl;
            break;
        default:
            std::cout << "Veiculo não criado aconteceu algum erro inesperado" << std::endl;
            break;
    }

    std::cout << "Redirecionando para o menu veículo..." << std::endl;
}


void VeiculoController::listar() {

    std::vector<Veiculo> veiculos = veiculoService.listar();

    if (veiculos.empty()) {
        std::cout << "Nenhum veiculo cadastrado.\n";
        return;
    }

    std::cout << "\n-------------------------- LISTA DE VEÍCULOS ---------------------------\n";

    std::cout << std::left
              << std::setw(10) << "PLACA"
              << std::setw(20) << "MODELO"
              << std::setw(12) << "STATUS"
              << std::setw(30) << "LOCAL"  << "\n";

    std::cout << std::string(72, '-') << '\n';

    for (auto& v : veiculos) {
        Local local = localService.buscarPorId(v.getLocalAtualId());

        std::cout << std::left
                  << std::setw(10) << v.getPlaca()
                  << std::setw(20) << v.getModelo()
                  << std::setw(12) << statusToString(v.getStatus())
                  << std::setw(30) << local.getEndereco()
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
        std::cout << "\n-------------------------- LISTA DE VEÍCULOS PARA SEREM EXCLUÍDOS --------------------------\n";

        std::cout << std::left
                  << std::setw(10) << "PLACA"
                  << std::setw(20) << "MODELO"
                  << std::setw(12) << "STATUS"
                  << std::setw(30) << "LOCAL" << "\n";

        for (const Veiculo& v : veiculos) {
            std::cout << "ID: " << v.getId() << " | "
                      << v.getPlaca() << " | "
                      << v.getModelo() << std::endl;
        }

        int idSelecionado;
        std::cout << "Digite o ID do veículo para excluir (ou um valor inválido para cancelar): ";
        std::cin >> idSelecionado;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Entrada inválida. Operação cancelada." << std::endl;
        } else {
            Veiculo* veiculoEncontrado = nullptr;
            for (auto& v : veiculos) {
                if (v.getId() == idSelecionado) {
                    veiculoEncontrado = &v;
                    break;
                }
            }

            if (veiculoEncontrado == nullptr) {
                std::cout << "Nenhum veículo com esse ID foi encontrado. Operação cancelada." << std::endl;
            } else {
                veiculoService.excluir(veiculoEncontrado->getId());
                std::cout << "Veículo excluído com sucesso." << std::endl;
            }
        }
    }

    std::cout << "Redirecionando para o menu veículo..." << std::endl;
}



void VeiculoController::updateLocalAtual() {
    std::string placa;

    std::cout << "Digite a placa do veículo: ";
    std::cin >> placa;

    Local novoLocal = LocalUtils::selecionarLocal(localService);

    veiculoService.updateLocalAtual(placa, novoLocal);

    std::cout << "Local atual do veículo atualizado com sucesso!" << std::endl;
}

void VeiculoController::updateStatus() {
        std::string placa;
        std::cout << "Digite a placa do veículo: ";
        std::cin >> placa;
        std::cin.ignore();

        std::cout << "Digite o novo status:\n";
        std::cout << "0 - Pendente\n";
        std::cout << "1 - Disponível\n";
        std::cout << "2 - Ocupado\n";

        int opcao;
        std::cin >> opcao;

        EnumStatusVeiculo novoStatus;

        switch (opcao) {
            case 0: novoStatus = PENDENTE; break;
            case 1: novoStatus = DISPONIVEL; break;
            case 2: novoStatus = OCUPADO; break;
            default:
                std::cout << "Opção inválida." << std::endl;
                return;
        }

        veiculoService.updateStatus(placa, novoStatus);
        std::cout << "Status atualizado com sucesso!" << std::endl;
    }





