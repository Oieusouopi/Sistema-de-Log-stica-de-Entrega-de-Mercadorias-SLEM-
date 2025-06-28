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
        : placa(placa), modelo("Modelo " + placa), status(PENDENTE), localAtual(Local("Local " + placa)) {}
    Veiculo(std::string placa, std::string modelo, Local localAtual):placa(placa), modelo(modelo), status(PENDENTE),  localAtual(localAtual) {}

    std::string placa;
    std::string modelo;
    EnumStatusVeiculo status;
    Local localAtual;

};

#endif //VEICULO_H
