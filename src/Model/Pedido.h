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
    localDestino(localDestino), localOrigem(localOrigem), pesoDoItem(pesoDoItem) {
        id = gerarIdUnico();
    };

    int id;
    Local localOrigem;
    Local localDestino;
    double pesoDoItem;

    static int gerarIdUnico() {
        static std::mt19937 gerador(std::chrono::system_clock::now().time_since_epoch().count());
        std::uniform_int_distribution<int> distribuicao(100000, 999999);
        return distribuicao(gerador);
    }
};

#endif //PEDIDO_H
