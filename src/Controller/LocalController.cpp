//
// Created by eec on 18/06/25.
//
#include "LocalController.h"

#include <iostream>
#include <cstring>
#include <iomanip>

#include "../Utils/EnumMenu.h"
#include "../Utils/ExibirMensagem.h"
#include "../Utils/InputUtils.h"

LocalController::LocalController(LocalService &localService): localService(localService) {
}

void LocalController::menu() {
    char teclaGlobal = '\0';
    std::string entrada;

    while (true) {

        std::cout << "\n---------- MENU LOCAL ---------\n";
        std::cout << static_cast<char>(CRIAR_LOCAL) << " -  Criar local\n";
        std::cout << static_cast<char>(EXCLUIR_LOCAL) << " -  Excluir local\n";
        std::cout << static_cast<char>(LISTAR_TODOS_LOCAIS) << " -  Listar todos locais\n";
        std::cout << static_cast<char>(ATUALIZAR_LOCAL) << " -  Atualizar local\n";
        std::cout << static_cast<char>(VOLTAR_PARA_O_MENU_PRINCIPAL_LOCAL) << " -  Voltar para o menu principal\n";
        std::cout << "----------------------------------\n";

        std::cin >> entrada;

        if (entrada.length() != 1) {
            ExibirMensagem::exibirMensagemDeErro();
            continue;
        }

        teclaGlobal = entrada[0];

        switch (teclaGlobal) {
            case CRIAR_LOCAL:
                std::cin.ignore();
                criar();
                break;
            case EXCLUIR_LOCAL:
                excluir();
                break;
            case LISTAR_TODOS_LOCAIS:
                listar();
                break;
            case ATUALIZAR_LOCAL:
                atualizar();
                break;
            case VOLTAR_PARA_O_MENU_PRINCIPAL_LOCAL:
                return;
            default:
                ExibirMensagem::exibirMensagemDeErro();
                break;
        }
    }
}

void LocalController::criar() {
    float x, y;
    char endereco[100];

    lerFloat("Digite a coordenada X: ", x);
    lerFloat("Digite a coordenada Y: ", y);

    std::cout << "Digite o endereço (Ex: 'Sao Paulo', 'Avenida X 123'): ";
    std::cin.getline(endereco, 100);

    Local local(x, y, endereco);

    localService.criar(local);
}


void LocalController::excluir() {
    std::cout << "Digite o ID do local para excluir: ";
    int id;
    std::cin >> id;

    if (localService.existeId(id)) {
        localService.excluirPorId(id);
        std::cout << "Local com ID " << id << " excluído com sucesso.\n";
    } else {
        std::cout << "Nenhum local encontrado com o ID " << id << ".\n";
    }
}

void LocalController::listar() {
    std::vector<Local> locais = localService.listar();

    if (locais.empty()) {
        std::cout << "Nenhum local cadastrado.\n";
        return;
    }

    std::cout << "\n-------------------------- LISTA DE LOCAIS ------------------------\n";

    std::cout << std::left
              << std::setw(10) << "ID"
              << std::setw(30) << "ENDEREÇO"
              << std::setw(10) << "CORDENADA X"
              << std::setw(10) << "CORDENADA Y" << "\n";

    std::cout << std::string(70, '-') << '\n';

    for (const auto& local : locais) {

        std::cout << std::left
                  << std::setw(10) << local.getId()
                  << std::setw(30) << local.getEndereco()
                  << std::setw(10) << local.getX()
                  << std::setw(10) << local.getY() << '\n';
    }

    std::cout << std::string(70, '-') << '\n';

    std::cout << "Redirecionando para o menu do local..." << std::endl;
}

void LocalController::atualizar() {
    int id;
    std::cout << "Digite o ID do local que deseja atualizar: ";
    std::cin >> id;

    Local local;

    try {
        local = localService.buscarPorId(id);
    } catch (const std::exception& e) {
        std::cerr << "Erro: " << e.what() << std::endl;
        return;
    }

    std::cout << "Local atual:\n";
    local.mostrar();

    char opcao;
    std::cout << "O que deseja atualizar?\n";
    std::cout << "1 - Coordenada X\n";
    std::cout << "2 - Coordenada Y\n";
    std::cout << "3 - Endereço\n";
    std::cout << "Escolha: ";
    std::cin >> opcao;

    switch (opcao) {
        case '1': {
            float novoX;
            std::cin.ignore();
            lerFloat("Nova coordenada X: ", novoX);
            if (localService.atualizarCordX(local.getId(), novoX)) {
                std::cout << "Coordenada X atualizada com sucesso.\n";
            }
            break;
        }
        case '2': {
            float novoY;
            std::cin.ignore();
            lerFloat("Nova coordenada X: ", novoY);
            if (localService.atualizarCordY(local.getId(), novoY)) {
                std::cout << "Coordenada Y atualizada com sucesso.\n";
            };
            break;
        }
        case '3': {
            char novoEndereco[100];
            std::cin.ignore();
            std::cout << "Novo endereço: ";
            std::cin.getline(novoEndereco, 100);

            if (!localService.atualizarEnderecoPorId(id, novoEndereco)) {
                std::cout << "Endereço atualizado com sucesso.\n";
            }
            break;
        }
        default:
            std::cout << "Opção inválida.\n";
            return;
    }
}
