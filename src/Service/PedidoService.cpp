#include "PedidoService.h"
//
// Created by eec on 18/06/25.
//
EnumResultadoCriacaoPedido PedidoService::criar(const Pedido& pedido) {

    pedidos.push_back(pedido);

    if (pedido.localOrigem.getEndereco() == "Não definido" || pedido.localDestino.getEndereco() == "Não definido") {
        return ERRO_CRIACAO_DO_PEDIDO_SEM_LOCAL;
    }

    if (pedido.pesoDoItem <= 0) {
        return ERRO_CRIACAO_DO_PEDIDO_COM_PESO_NEGATIVO;
    }

    return SUCESSO_CRIACAO_DO_PEDIDO;
}

std::vector<Pedido> PedidoService::listar() {

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




