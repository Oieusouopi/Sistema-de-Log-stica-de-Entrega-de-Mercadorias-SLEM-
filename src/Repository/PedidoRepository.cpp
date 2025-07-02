#include "PedidoRepository.h"

#include "../Model/Pedido.h"
//
// Created by eec on 30/06/25.
//

void PedidoRepository::salvarOuAtualizar(Pedido pedido) {
    for (auto& p : pedidos) {
        if (p.getId() == pedido.getId()) {
            p = pedido;
        }
    }

    int novoId = gerarNovoId();

    pedido.setId(novoId);

    pedidos.push_back(pedido);
}

int PedidoRepository::gerarNovoId() {
    int maiorId = 0;

    for (const auto& pedido : pedidos) {
        if (pedido.getId() > maiorId) {
            maiorId = pedido.getId();
        }
    }

    return maiorId + 1;
}

std::vector<Pedido> PedidoRepository::listar() {
    return pedidos;
}

Pedido PedidoRepository::buscarPorId(int id) {
    for (auto& pedido : pedidos) {
        if (pedido.getId() == id) {
            return pedido;
        }
    }

    throw std::runtime_error("Local com ID " + std::to_string(id) + " não encontrado.");
}

void PedidoRepository::excluir(int id) {

    for (int i = 0; i <= pedidos.size(); i++) {
        if (pedidos[i].getId() == id) {
            pedidos.erase(pedidos.begin() + i);
        }
    }

}


void PedidoRepository::salvarBackup(char caminho[]) {

}

