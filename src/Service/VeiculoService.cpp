#include "VeiculoService.h"
#include <string>

#include "../Model/Local.h"
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
    return true;
}

std::vector<Veiculo> VeiculoService::listar() {}

void VeiculoService::updateLocalAtual(std::string placa, Local local) {

}

void VeiculoService::updateStatus(std::string placa, bool status) {

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



