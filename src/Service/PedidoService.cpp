#include "PedidoService.h"
#include "VeiculoService.h"
#include "../Utils/VeiculoUtils.h"
//
// Created by eec on 18/06/25.
//
PedidoService::PedidoService(PedidoRepository &pedidoRepository): pedidoRepository(pedidoRepository) {}

EnumResultadoCriacaoPedido PedidoService::criar(Pedido pedido) {

    if (pedido.getLocalOrigem().getEndereco() == "Não definido" || pedido.getLocalDestino().getEndereco() == "Não definido") {
        return ERRO_CRIACAO_DO_PEDIDO_SEM_LOCAL;
    }

    if (pedido.getPesoItem() <= 0) {
        return ERRO_CRIACAO_DO_PEDIDO_COM_PESO_NEGATIVO;
    }

    pedidoRepository.salvarOuAtualizar(pedido);
    std::vector<Veiculo> veiculos = veiculoService.listar();
    Veiculo* veiculoMaisProximo = VeiculoUtils::encontrarVeiculoMaisProximo(veiculos, pedido);

    if (veiculoMaisProximo != nullptr) {
        veiculoService.updateStatusEPedido(veiculoMaisProximo->placa, OCUPADO, pedido.id);
    }

    pedidos.push_back(pedido);

    return SUCESSO_CRIACAO_DO_PEDIDO;
}

std::vector<Pedido> PedidoService::listar() {
    return pedidoRepository.listar();
}

void PedidoService::excluir(int id) {
    pedidoRepository.excluir(id);
}

void PedidoService::update(int id) {

}




