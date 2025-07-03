//
// Created by eec on 18/06/25.
//

#ifndef VEICULO_H
#define VEICULO_H
#include <string.h>

#include "../Utils/EnumUtils.h"

class Veiculo {
public:
    Veiculo(std::string placa)
        : placa(placa), modelo("Modelo " + placa), status(PENDENTE), localAtual(Local("Local " + placa)), pedidoId(NULL) {}
    Veiculo(std::string placa, std::string modelo, Local localAtual):placa(placa), modelo(modelo), status(PENDENTE),  localAtual(localAtual), pedidoId(NULL) {}
    Veiculo(std::string placa, std::string modelo, EnumStatusVeiculo status, Local localAtual, int pedidoId)
        : placa(placa), modelo(modelo), status(status), localAtual(localAtual), pedidoId(pedidoId) {}

    std::string placa;
    std::string modelo;
    EnumStatusVeiculo status;
    Local localAtual;
    int pedidoId;

};

#endif //VEICULO_H
