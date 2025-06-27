#include "LocalService.h"
//
// Created by eec on 18/06/25.
//
void LocalService::criar(const Local& local) {
        locais.push_back(local);
}

std::vector<Local> LocalService::listar() {
        return locais;
}

void LocalService::excluir(std::string nome) {

}

