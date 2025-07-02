#include "LocalService.h"
//
// Created by eec on 18/06/25.
//

LocalService::LocalService(LocalRepository &localRepository): localRepository(localRepository) {};

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

bool LocalService::existeEndereco(const char endereco[]) const {
        std::vector<Local> locais = localRepository.listar();
        for (const auto& local : locais) {
                if (local.getEndereco() == endereco) {
                        return true;
                }
        }
        return false;
}

void LocalService::criar(const Local& local) {
        if (!validarEndereco(local.getEndereco())) {
                std::cout << "Endereço inválido. Local não foi criado.\n";
                return;
        }

        if (existeEndereco(local.getEndereco())) {
                std::cout << "Endereço já cadastrado. Local duplicado não será criado.\n";
                return;
        }


        localRepository.salvarOuAtualizar(local);

        std::cout << "Local criado com sucesso.\n";
}

std::vector<Local> LocalService::listar() {
        return localRepository.listar();
}

void LocalService::excluirPorId(int id) {
        localRepository.excluir(id);
}

bool LocalService::existeId(int id) {
        std::vector<Local> locais = localRepository.listar();

        for (const auto& local : locais) {
                if (local.getId() == id) {
                        return true;
                }
        }
        return false;
}

Local LocalService::buscarPorId(int id) {
        if (id != NULL && id > 0) {
                return localRepository.buscarPorId(id);
        }
}

bool LocalService::atualizarEnderecoPorId(int id, char novoEndereco[]) {
        if (!validarEndereco(novoEndereco)) {
                std::cout << "Endereço inválido. Atualização cancelada.\n";
                return false;
        }

        if (existeEndereco(novoEndereco)) {
                std::cout << "Endereço ja cadastrado. Atualização cancelada.\n";
                return false;
        }

        Local local = localRepository.buscarPorId(id);

        local.setEndereco(novoEndereco);

        localRepository.salvarOuAtualizar(local);

        std::cout << "ID não encontrado.\n";
        return false;
}
