#include "LocalRepository.h"
//
// Created by eec on 30/06/25.
//

void LocalRepository::salvarBackup(char caminho[]) {
    FILE* file = fopen(caminho, "wb");

    if (file == NULL) {
        std::cout << "Problema na abertura do arquivo";
        return;
    }

    int quantidade = locais.size();
    fwrite(&quantidade, sizeof(int), 1, file);

    for (const Local& local : locais) {
        fwrite(&local, sizeof(Local), 1, file);
    }

    fclose(file);
}

void LocalRepository::restaurarBackup(char caminho[]) {
    FILE* file = fopen(caminho, "rb");

    if (file == NULL) {
        perror("Erro ao abrir arquivo");
        return;
    }

    int quantidade = 0;
    fread(&quantidade, sizeof(int), 1, file);

    locais.clear();

    for (int i = 0; i < quantidade; ++i) {
        Local local;
        fread(&local, sizeof(Local), 1, file);
        locais.push_back(local);
    }

    fclose(file);
}

std::vector<Local> LocalRepository::listar() {
    return locais;
}

Local LocalRepository::buscarPorId(int id) {

    for (auto& local : locais) {
        if (local.getId() == id) {
            return local;
        }
    }

    throw std::runtime_error("Local com ID " + std::to_string(id) + " não encontrado.");
}

void LocalRepository::excluir(int id) {
    locais.erase(
            std::remove_if(locais.begin(), locais.end(),
                           [id](const Local& l) { return l.getId() == id; }),
            locais.end());
}

void LocalRepository::salvarOuAtualizar(Local local) {
    for (auto& l : locais) {
        if (l.getId() == local.getId()) {
            l = local;
        }
    }

    int novoId = gerarNovoId();
    local.setId(novoId);
    locais.push_back(local);
}

int LocalRepository::gerarNovoId() {
    int maiorId = 0;

    for (const auto& local : locais) {
        if (local.getId() > maiorId) {
            maiorId = local.getId();
        }
    }

    return maiorId + 1;
}
