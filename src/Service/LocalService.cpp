#include "LocalService.h"
//
// Created by eec on 18/06/25.
//

bool validarEndereco(const char end[]) {
        bool temLetra = false;
        for (int i = 0; end[i] != '\0'; i++) {
                unsigned char c = static_cast<unsigned char>(end[i]);
                if (isalpha(c) || (c >= 192 && c <= 255)) {
                        temLetra = true;
                } else if (isdigit(c) || c == ' ' || c == ',') {
                        continue;
                } else {
                        return false;
                }
        }
        return temLetra;
}

bool LocalService::existeEndereco(const std::string& endereco) const {
        for (const auto& local : locais) {
                if (local.getEndereco() == endereco) {
                        return true;
                }
        }
        return false;
}

void LocalService::criar(const Local& local) {
        if (!validarEndereco(local.getEndereco().c_str())) {
                std::cout << "Endereço inválido. Local não foi criado.\n";
                return;
        }

        if (existeEndereco(local.getEndereco())) {
                std::cout << "Endereço já cadastrado. Local duplicado não será criado.\n";
                return;
        }

        locais.push_back(local);
        std::cout << "Local criado com sucesso.\n";
}

std::vector<Local> LocalService::listar() {
        return locais;
}

int LocalService::gerarNovoId() {
        int maiorId = 0;

        for (const auto& local : locais) {
                if (local.getId() > maiorId) {
                        maiorId = local.getId();
                }
        }

        return maiorId + 1;
}

void LocalService::excluirPorId(int id) {
        locais.erase(
            std::remove_if(locais.begin(), locais.end(),
                           [id](const Local& l) { return l.getId() == id; }),
            locais.end());
}

bool LocalService::existeId(int id) {
        for (const auto& local : locais) {
                if (local.getId() == id) {
                        return true;
                }
        }
        return false;
}

