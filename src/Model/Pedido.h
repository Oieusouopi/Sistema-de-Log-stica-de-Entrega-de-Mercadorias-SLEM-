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

public:
    Pedido() {};
    Pedido(Local localOrigem, Local localDestino, double pesoItem):
    id(0), localDestino(localDestino), localOrigem(localOrigem), pesoItem(pesoItem) {};

    int getId() const { return id; }

    void setId(int id) { this->id = id; }

    Local getLocalOrigem() { return this->localOrigem; }

    void setLocalOrigem(Local localOrigem) { this->localOrigem = localOrigem; }

    Local getLocalDestino() { return this->localDestino; }

    void setLocalDestino(Local localDestino) { this->localDestino = localDestino; }

    double getPesoItem() {return this->pesoItem; }

    void setPesoItem(double pesoItem) { this->pesoItem = pesoItem; }
};

#endif //PEDIDO_H
