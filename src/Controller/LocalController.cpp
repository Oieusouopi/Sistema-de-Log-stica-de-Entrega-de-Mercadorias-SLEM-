//
// Created by eec on 18/06/25.
//
#include "LocalController.h"

#include <iostream>
#include <cstring>

#include "../Utils/EnumMenu.h"
#include "../Utils/ExibirMensagem.h"

LocalController::LocalController(LocalService &localService): localService(localService) {
}

void LocalController::menu() {
    char teclaGlobal = '\0';
    std::string entrada;

    while (true) {

        std::cout << "\n----- MENU LOCAL -----\n";
        std::cout << static_cast<char>(CRIAR_LOCAL) << " -  Criar local\n";
        std::cout << static_cast<char>(EXCLUIR_LOCAL) << " -  Excluir local\n";
        std::cout << static_cast<char>(LISTAR_TODOS_LOCAIS) << " -  Listar todos locais\n";
        std::cout << static_cast<char>(VOLTAR_PARA_O_MENU_PRINCIPAL_LOCAL) << " -  Voltar para o menu principal\n";
        std::cout << "-----------------------------\n";

        std::cin >> entrada;

        if (entrada.length() != 1) {
            ExibirMensagem::exibirMensagemDeErro();
            continue;
        }

        teclaGlobal = entrada[0];

        switch (teclaGlobal) {
            case CRIAR_LOCAL:
                criar();
                break;
            case EXCLUIR_LOCAL:
                excluir();
                break;
            case LISTAR_TODOS_LOCAIS:
                listar();
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

    std::cout << "Digite a coordenada X: ";
    std::cin >> x;

    std::cout << "Digite a coordenada Y: ";
    std::cin >> y;

    std::cin.ignore();
    std::cout << "Digite o endereço (Ex: 'Sao Paulo', 'Avenida X 123'): ";
    std::cin.getline(endereco, 100);


    int novoId = localService.gerarNovoId();

    Local local(novoId, x, y, endereco);

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

    std::cout << "\n--- Lista de Locais Cadastrados ---\n";
    for (const auto& local : locais) {
        local.mostrar();
        std::cout << "--------------------------\n";
    }

}
