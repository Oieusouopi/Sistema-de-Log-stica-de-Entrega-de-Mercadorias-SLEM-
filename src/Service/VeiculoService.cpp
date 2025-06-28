#include "VeiculoService.h"
#include <string>

#include "../Model/Local.h"
//
// Created by eec on 18/06/25.
//
EnumResultadoCriacaoVeiculo VeiculoService::criar(Veiculo &veiculo) {
    return SUCESSO;
}

bool VeiculoService::excluir(std::string placa) {
    return true;
}

std::vector<Veiculo> VeiculoService::listar() {
    std::vector<Veiculo> veiculos = {
        Veiculo("ABC1234"),
        Veiculo("XYZ9876"),
        Veiculo("LMN4567")
    };

    return veiculos;

}

void VeiculoService::updateLocalAtual(std::string placa, Local local) {

}

void VeiculoService::updateStatus(std::string placa, bool status) {

}

bool VeiculoService::validarPlaca(std::string placa) {

}



