//
// Created by eec on 18/06/25.
//

#ifndef PEDIDO_H
#define PEDIDO_H
#include <chrono>
#include <random>

#include "Local.h"

class Pedido {
private:
    int id;
    Local localOrigem;
    Local localDestino;
    double pesoItem;
    int veiculoVinculadoId;

public:
    Pedido(): id(-1), veiculoVinculadoId(-1) {};
    Pedido(Local localOrigem, Local localDestino, double pesoItem):
    id(-1), localDestino(localDestino), localOrigem(localOrigem), pesoItem(pesoItem), veiculoVinculadoId(-1) {};

    int getId() const { return id; }

    void setId(int id) { this->id = id; }

    Local getLocalOrigem() { return this->localOrigem; }

    void setLocalOrigem(Local localOrigem) { this->localOrigem = localOrigem; }

    Local getLocalDestino() { return this->localDestino; }

    void setLocalDestino(Local localDestino) { this->localDestino = localDestino; }

    double getPesoItem() {return this->pesoItem; }

    void setPesoItem(double pesoItem) { this->pesoItem = pesoItem; }

    void setVeiculoVinculadoId(int veiculoVinculadoId) { this->veiculoVinculadoId = veiculoVinculadoId; }

    int getVeiculoVinculadoId() { return this->veiculoVinculadoId; }
};

#endif //PEDIDO_H
