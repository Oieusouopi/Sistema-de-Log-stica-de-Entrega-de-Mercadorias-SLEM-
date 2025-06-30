#include "PedidoService.h"
//
// Created by eec on 18/06/25.
//
EnumResultadoCriacaoPedido PedidoService::criar(const Pedido& pedido) {
    return SUCESSO_CRIACAO_DO_PEDIDO;
}

std::vector<Pedido> PedidoService::listar() {
    return pedidos;
}

bool PedidoService::excluir(int id) {

    for (int i = 0; i <= pedidos.size(); i++) {
        if (pedidos[i].id == id) {
            pedidos.erase(pedidos.begin() + i);
        } else {
            return false;
        }
    }

    return true;
}

void PedidoService::update(int id) {

}




