#include "LocalRepository.h"
//
// Created by eec on 30/06/25.
//

void LocalRepository::salvarTodos(char caminho[30]) {
    FILE* file = fopen(caminho, "rb");

    if (file == NULL) {
        std::cout << "Problema na abertura do arquivo";
        return;
    }

    fwrite(&locais,  sizeof(char) ,locais.size() * sizeof(Local), file);

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
