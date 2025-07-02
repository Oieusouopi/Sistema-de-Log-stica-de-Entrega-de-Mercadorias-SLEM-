//
// Created by eec on 18/06/25.
//

#ifndef VEICULO_H
#define VEICULO_H
#include <string>

#include <cstring>  // Para strncpy, strlen
#include "../Utils/EnumUtils.h"

class Veiculo {
private:
    int id;
    char placa[8];
    char modelo[30];
    EnumStatusVeiculo status;
    int localAtualId;

public:
    Veiculo() {}
    Veiculo(const char* placa) : id(0), status(PENDENTE), localAtualId(0) {
        strncpy(this->placa, placa, sizeof(this->placa) - 1);
        this->placa[sizeof(this->placa) - 1] = '\0';
        strncpy(this->modelo, "Modelo ", sizeof(this->modelo) - 1);
        this->modelo[sizeof(this->modelo) - 1] = '\0';
        strncat(this->modelo, placa, sizeof(this->modelo) - strlen(this->modelo) - 1);
    }

    Veiculo(const char* placa, const char* modelo, int localAtualId)
        : id(0), status(PENDENTE), localAtualId(localAtualId) {
        strncpy(this->placa, placa, sizeof(this->placa) - 1);
        this->placa[sizeof(this->placa) - 1] = '\0';
        strncpy(this->modelo, modelo, sizeof(this->modelo) - 1);
        this->modelo[sizeof(this->modelo) - 1] = '\0';
    }

    void setId(int id) { this->id = id; }

    int getId() const { return this->id; }

    void setPlaca(const char* placa) {
        strncpy(this->placa, placa, sizeof(this->placa) - 1);
        this->placa[sizeof(this->placa) - 1] = '\0';
    }

    const char* getPlaca() const { return this->placa; }

    void setModelo(const char* modelo) {
        strncpy(this->modelo, modelo, sizeof(this->modelo) - 1);
        this->modelo[sizeof(this->modelo) - 1] = '\0';
    }

    const char* getModelo() const { return this->modelo; }

    void setStatus(EnumStatusVeiculo status) { this->status = status; }

    EnumStatusVeiculo getStatus() const { return this->status; }

    void setLocalAtualId(int localAtualId) { this->localAtualId = localAtualId; }

    int getLocalAtualId() const { return this->localAtualId; }
};

#endif // VEICULO_H
