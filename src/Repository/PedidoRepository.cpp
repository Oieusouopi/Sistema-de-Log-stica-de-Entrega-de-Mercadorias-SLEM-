#include "PedidoRepository.h"

#include "../Model/Pedido.h"
//
// Created by eec on 30/06/25.
//
bool PedidoRepository::salvarOuAtualizar(Pedido pedido) {
    for (auto& p : pedidos) {
        if (p.getId() == pedido.getId()) {
            l = local;
        }
    }

    int novoId = gerarNovoId();
    local.setId(novoId);
    pedidos.push_back(local);
}