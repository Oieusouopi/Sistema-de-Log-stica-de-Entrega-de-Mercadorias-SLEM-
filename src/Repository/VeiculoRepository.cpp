#include "VeiculoRepository.h"

#include <stdexcept>

#include "../Model/Veiculo.h"
//
// Created by eec on 30/06/25.
//
int VeiculoRepository::gerarNovoId() {
    int maiorId = 0;

    for (auto& veiculo : veiculos) {
        if (veiculo.getId() > maiorId) {
            maiorId = veiculo.getId();
        }
    }

    return maiorId + 1;
}

void VeiculoRepository::salvarOuAtualizar(Veiculo veiculo) {
    for (auto& v : veiculos) {
        if (v.getId() == veiculo.getId()) {
            v = veiculo;
        }
    }

    int novoId = gerarNovoId();

    veiculo.setId(novoId);

    veiculos.push_back(veiculo);
}

void VeiculoRepository::excluir(int id) {
    for (int i = 0; i <= veiculos.size(); i++) {
        if (veiculos[i].getId() == id) {
            veiculos.erase(veiculos.begin() + i);
        }
    }
}

std::vector<Veiculo> VeiculoRepository::listar() {
    return veiculos;
}

Veiculo VeiculoRepository::buscarPorId(int id) {
    for (auto& veiculo : veiculos) {
        if (veiculo.getId() == id) {
            return veiculo;
        }
    }

    throw std::runtime_error("Local com ID " + std::to_string(id) + " não encontrado.");
}

void VeiculoRepository::salvarBackup(char caminho[]) {

}



