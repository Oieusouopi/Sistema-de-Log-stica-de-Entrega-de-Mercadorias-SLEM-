//
// Created by eec on 18/06/25.
//
#include "LocalController.h"

#include <iostream>

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
                break;
            case EXCLUIR_LOCAL:
                break;
            case LISTAR_TODOS_LOCAIS:
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

}

void LocalController::excluir() {

}

void LocalController::listar() {

}
