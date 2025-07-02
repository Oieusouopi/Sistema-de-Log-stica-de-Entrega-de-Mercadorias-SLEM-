//
// Created by eec on 18/06/25.
//

#ifndef VEICULO_H
#define VEICULO_H
#include <string>

#include "../Utils/EnumUtils.h"

class Veiculo {
private:
    int id;
    std::string placa;
    std::string modelo;
    EnumStatusVeiculo status;
    int localAtualId;

public:
    Veiculo(std::string placa)
        : id(0), placa(placa), modelo("Modelo " + placa), status(PENDENTE), localAtualId(0) {}
    Veiculo(std::string placa, std::string modelo, int localAtualId): id(0), placa(placa), modelo(modelo), status(PENDENTE),  localAtualId(localAtualId) {}

    void setId(int id) { this->id = id; }

    int getId() { return this->id; }

    void setPlaca(std::string) { this->placa = placa; }

    std::string getPlaca() { return this->placa; }

    void setModelo(std::string modelo) { this->modelo = modelo; }

    std::string getModelo() { return this->modelo; }

    void setStatus(EnumStatusVeiculo status) { this->status = status; }

    EnumStatusVeiculo getStatus() { return this->status; }

    void setLocalAtualId(int localAtualId) { this->localAtualId = localAtualId; }

    int getLocalAtualId() { return this->localAtualId; }
    Local localAtual;
    int pedidoId;

};

#endif //VEICULO_H
