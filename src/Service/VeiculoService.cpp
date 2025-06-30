#include "VeiculoService.h"
#include <string>

#include "../Model/Local.h"
#include "../Utils/EnumStatusVeiculoUtils.h"

//
// Created by eec on 18/06/25.
//
EnumResultadoCriacaoVeiculo VeiculoService::criar(Veiculo &veiculo) {

    if (!validarPlaca(veiculo.placa)) {
        return PLACA_DUPLICADA;
    }

    veiculos.push_back(veiculo);

    return SUCESSO_CRIACAO_DO_VEICULO;
}

bool VeiculoService::excluir(std::string placa) {
    for (int i = 0; i <= veiculos.size(); i++) {
        if (veiculos[i].placa == placa) {
            veiculos.erase(veiculos.begin() + i);
        } else {
            return false;
        }
    }

    return true;
}

std::vector<Veiculo> VeiculoService::listar() {
    return veiculos;
}

void VeiculoService::updateLocalAtual(std::string placa, Local local) {
}

bool VeiculoService::updateStatus(std::string placa, EnumStatusVeiculo status) {
    for (int i = 0; i < veiculos.size(); i++) {
        if (veiculos[i].placa == placa) {
            veiculos[i].status = status;
            return true;
        }
    }

    return false;
}

bool VeiculoService::validarPlaca(std::string placa) {

    if (veiculos.empty()) {
        for (const auto& veiculo : veiculos) {
            if (veiculo.placa == placa) {
                return false;
            }
        }
    }

    return true;
}



