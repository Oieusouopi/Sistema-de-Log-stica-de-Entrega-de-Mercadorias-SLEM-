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

class local{
private:
    float cord_x;
    float cord_y;
    char endereco[100];

public:
    local(float x, float y, const char end[]) {
        cord_x = x;
        cord_y = y;
        strcpy(endereco, end);
    }

    void setX(float x) { cord_x = x; }
    void setY(float y) { cord_y = y; }


    float getX() const { return cord_x; }
    float getY() const { return cord_y; }
    const char* getEndereco() const { return endereco; }

    void mostrar() const {
        std::cout << "Endereço: " << endereco
                  << "\nCoordenadas: (" << cord_x << ", " << cord_y << ")\n";
    }
};

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

bool validarEndereco(const char end[]) {
    bool temLetra = false;
    for (int i = 0; end[i] != '\0'; i++) {
        char c = end[i];
        if (isalpha(c)) {
            temLetra = true;
        } else if (isdigit(c) || c == ' ') {
            continue;
        } else {
            return false;
        }
    }
    return temLetra;
}

void LocalController::criar() {
    float x, y;
    char endereco[100];

    std::cout << "Digite a coordenada X: ";
    std::cin >> x;

    std::cout << "Digite a coordenada Y: ";
    std::cin >> y;

    std::cin.ignore();
    std::cout << "Digite o endereço (Ex: 'Sao Paulo', 'Avenida X, 123'): ";
    std::cin.getline(endereco, 100);

    if (!validarEndereco(endereco)) {
        std::cout << "Endereço inválido. O local não foi criado.\n";
        return;
    }

    std::cout << "Local criado com sucesso!\n";
}


void LocalController::excluir() {

}

void LocalController::listar() {

}
