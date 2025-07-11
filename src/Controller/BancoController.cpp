#include "BancoController.h"

#include <iostream>
#include <string>

#include "../Utils/EnumMenu.h"
#include "../Utils/ExibirMensagem.h"
//
// Created by eec on 30/06/25.
//
BancoController::BancoController(BancoService &bancoService): bancoService(bancoService) {}


void BancoController::menu() {
    char teclaGlobal = '\0';
    std::string entrada;

    while (true) {
        std::cout << "\n---------- MENU BANCO ----------\n";
        std::cout << static_cast<char>(SALVAR_TODOS_DADOS) << " -  Salvar todos dados\n";
        std::cout << static_cast<char>(RESTAURAR_DADOS_DE_BACKUPS_ANTIGOS) << " -  Restaurar Backups\n";
        std::cout << static_cast<char>(VOLTAR_PARA_O_MENU_PRINCIPAL_BANCO) << " -  Voltar para o menu principal\n";
        std::cout << "---------------------------------\n";

        std::cin >> entrada;

        if (entrada.length() != 1) {
            ExibirMensagem::exibirMensagemDeErro();
            continue;
        }

        teclaGlobal = entrada[0];

        switch (teclaGlobal) {
            case SALVAR_TODOS_DADOS:
                salvarBackup();
                break;
            case RESTAURAR_DADOS_DE_BACKUPS_ANTIGOS:
                restaurarBackup();
                break;
            case VOLTAR_PARA_O_MENU_PRINCIPAL_BANCO:
                return;
            default:
                ExibirMensagem::exibirMensagemDeErro();
                break;
        }
    }

}

void BancoController::restaurarBackup() {
    bancoService.restaurarBackup();
    std::cout << "Backup restaurado com sucesso!\n";
}


void BancoController::salvarBackup() {
    bancoService.salvarBackup();
    std::cout << "Backup salvo com sucesso!\n";
}
