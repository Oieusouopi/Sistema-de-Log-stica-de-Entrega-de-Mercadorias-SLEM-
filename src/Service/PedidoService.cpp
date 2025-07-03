#include "PedidoService.h"
#include "VeiculoService.h"
#include "../Utils/VeiculoUtils.h"
#include <set>
//
// Created by eec on 18/06/25.
//
PedidoService::PedidoService(PedidoRepository &pedidoRepository, VeiculoService &veiculoService, LocalService &localService):
    pedidoRepository(pedidoRepository), veiculoService(veiculoService), localService(localService) {}

EnumResultadoCriacaoPedido PedidoService::criar(Pedido pedido) {

    if (pedido.getLocalOrigem().getEndereco() == "Não definido" || pedido.getLocalDestino().getEndereco() == "Não definido") {
        return ERRO_CRIACAO_DO_PEDIDO_SEM_LOCAL;
    }

    if (pedido.getPesoItem() <= 0) {
        return ERRO_CRIACAO_DO_PEDIDO_COM_PESO_NEGATIVO;
    }

    pedidoRepository.salvarOuAtualizar(pedido);
    std::vector<Veiculo> veiculos = veiculoService.listar();
    Veiculo veiculoMaisProximo = veiculoService.encontrarVeiculoMaisProximo(pedido);

    if (veiculoMaisProximo.getId() !=  -1) {
        veiculoService.updateStatusEPedido(veiculoMaisProximo.getPlaca(), OCUPADO, pedido.getId());
    }

    pedidoRepository.salvarOuAtualizar(pedido);

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
Pedido PedidoService::encontrarPedidoSemVeiculoMaisProximo(Veiculo veiculoDisponivel) {
    std::vector<Pedido> pedidos = pedidoRepository.listar();
    std::vector<Veiculo> veiculos = veiculoService.listar();

    if (pedidos.empty()) {
        return Pedido();
    }

    std::set<int> pedidosComVeiculo;
    for (auto& veiculo : veiculos) {
        if (veiculo.getStatus() == OCUPADO && veiculo.getPedidoId() != -1) {
            pedidosComVeiculo.insert(veiculo.getPedidoId());
        }
    }

    Pedido pedidoMaisProximo;
    double menorDistancia = std::numeric_limits<double>::max();

    for (size_t i = 0; i < pedidos.size(); ++i) {

        if (pedidosComVeiculo.find(pedidos[i].getId()) == pedidosComVeiculo.end()) {
            Local localAtual = localService.buscarPorId(veiculoDisponivel.getLocalAtualId());
            double distancia = VeiculoUtils::calcularDistancia(localAtual, pedidos[i].getLocalOrigem());

            if (distancia < menorDistancia) {
                menorDistancia = distancia;
                pedidoMaisProximo = pedidos[i];
            }
        }
    }

    if (pedidoMaisProximo.getId() == -1) {
        std::cout << "Pedido sem veículo encontrado para o veículo " << veiculoDisponivel.getPlaca()
                  << ": Pedido ID " << pedidoMaisProximo.getId() << " (Distância: " << menorDistancia << ")\n";
    }

    return pedidoMaisProximo;
}




