//
// Created by eec on 19/06/25.
//

#ifndef PEDIDOSERVICE_H
#define PEDIDOSERVICE_H
#include <string>
#include <vector>

#include "../Model/Pedido.h"

class PedidoService {

    public:
        void criar(const Pedido& pedido);
        std::vector<Pedido> listar();
        void update(int id);
        void excluir(int id);
    private:
        std::vector<Pedido> pedidos;
};

#endif //PEDIDOSERVICE_H
