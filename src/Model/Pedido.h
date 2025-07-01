//
// Created by eec on 18/06/25.
//

#ifndef PEDIDO_H
#define PEDIDO_H
#include <chrono>
#include <random>

#include "Local.h"

class Pedido {

public:
    Pedido(Local localOrigem, Local localDestino, double pesoDoItem):
    id(0), localDestino(localDestino), localOrigem(localOrigem), pesoDoItem(pesoDoItem) {};

    Local localOrigem;
    Local localDestino;
    double pesoDoItem;
private:
    int id;
};

#endif //PEDIDO_H
