#include "LocalService.h"
//
// Created by eec on 18/06/25.
//
void LocalService::criar(const Local& local) {

}

std::vector<Local> LocalService::listar() {
    std::vector<Local> locaisDisponiveis = {
        Local("São Paulo"), Local("Belo Horizonte"), Local("Rio de Janeiro")
    };

    return locaisDisponiveis;
}

void LocalService::excluir(std::string nome) {

}

