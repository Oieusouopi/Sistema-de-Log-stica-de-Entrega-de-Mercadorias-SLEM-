#include "PedidoService.h"
#include "VeiculoService.h"
#include "../Utils/VeiculoUtils.h"
//
// Created by eec on 18/06/25.
//
EnumResultadoCriacaoPedido PedidoService::criar(const Pedido& pedido, VeiculoService& veiculoService) {
    // Validações do pedido
    if (pedido.localOrigem.getEndereco() == "Não definido" || pedido.localDestino.getEndereco() == "Não definido") {
        return ERRO_CRIACAO_DO_PEDIDO_SEM_LOCAL;
    }

    if (pedido.pesoDoItem <= 0) {
        return ERRO_CRIACAO_DO_PEDIDO_COM_PESO_NEGATIVO;
    }

    std::vector<Veiculo> veiculos = veiculoService.listar();
    Veiculo* veiculoMaisProximo = VeiculoUtils::encontrarVeiculoMaisProximo(veiculos, pedido);
    
    if (veiculoMaisProximo != nullptr) {
        veiculoService.updateStatusEPedido(veiculoMaisProximo->placa, OCUPADO, pedido.id);
    }

    pedidos.push_back(pedido);

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




