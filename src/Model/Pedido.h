//
// Created by eec on 18/06/25.
//

#ifndef PEDIDO_H
#define PEDIDO_H
#include "Local.h"

class Pedido {

public:
    Pedido(Local localOrigem, Local localDestino, double pesoDoItem):
    localDestino(localDestino), localOrigem(localOrigem), pesoDoItem(pesoDoItem) {};
    Local localOrigem;
    Local localDestino;
    double pesoDoItem;
};

#endif //PEDIDO_H
