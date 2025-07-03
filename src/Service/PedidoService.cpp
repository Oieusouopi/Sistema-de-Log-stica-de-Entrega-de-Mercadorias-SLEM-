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

    std::vector<Veiculo> veiculos = veiculoService.listar();
    Veiculo veiculoMaisProximo = veiculoService.encontrarVeiculoMaisProximo(pedido);

    if (veiculoMaisProximo.getId() !=  -1) {
        veiculoService.updateStatusEPedido(veiculoMaisProximo.getId(), OCUPADO, pedido.getId());
        pedido.setVeiculoVinculadoId(veiculoMaisProximo.getId());
    }

    pedidoRepository.salvarOuAtualizar(pedido);

    return SUCESSO_CRIACAO_DO_PEDIDO;
}

std::vector<Pedido> PedidoService::listar() {
    return pedidoRepository.listar();
}

void PedidoService::excluir(int id) {
    Pedido pedido = pedidoRepository.buscarPorId(id);

    if (pedido.getVeiculoVinculadoId() != -1) {
        veiculoService.updateStatusEPedido(pedido.getVeiculoVinculadoId(), DISPONIVEL, -1);
    }

    pedidoRepository.excluir(id);
}

void PedidoService::salvarOuAtualizar(Pedido pedido) {
    pedidoRepository.salvarOuAtualizar(pedido);
}

Pedido PedidoService::encontrarPedidoSemVeiculoMaisProximo(Veiculo veiculoDisponivel) {
    std::vector<Pedido> pedidos = pedidoRepository.listar();
    std::vector<Veiculo> veiculos = veiculoService.listar();

    if (pedidos.empty()) {
        std::cout << "Nenhum pedido disponível no sistema.\n";
        return Pedido(); // id será -1 se isso for garantido no construtor padrão
    }

    // Identifica os pedidos que já estão vinculados a veículos
    std::set<int> pedidosComVeiculo;
    for (Veiculo& veiculo : veiculos) {
        if (veiculo.getStatus() == OCUPADO && veiculo.getPedidoId() != -1) {
            pedidosComVeiculo.insert(veiculo.getPedidoId());
        }
    }

    Pedido pedidoMaisProximo;
    double menorDistancia = std::numeric_limits<double>::max();

    Local localVeiculo = localService.buscarPorId(veiculoDisponivel.getLocalAtualId());

    for (Pedido& pedido : pedidos) {
        if (pedidosComVeiculo.find(pedido.getId()) == pedidosComVeiculo.end()) {
            double distancia = VeiculoUtils::calcularDistancia(localVeiculo, pedido.getLocalOrigem());

            if (distancia < menorDistancia) {
                menorDistancia = distancia;
                pedidoMaisProximo = pedido;
            }
        }
    }

    if (pedidoMaisProximo.getId() != -1) {
        std::cout << "Pedido mais próximo sem veículo para o veículo " << veiculoDisponivel.getPlaca()
                  << ": Pedido ID " << pedidoMaisProximo.getId()
                  << " (Distância: " << menorDistancia << ")\n";
    } else {
        std::cout << "Nenhum pedido sem veículo disponível para o veículo " << veiculoDisponivel.getPlaca() << ".\n";
    }

    return pedidoMaisProximo;
}

Pedido PedidoService::buscarPorId(int id) {
    return pedidoRepository.buscarPorId(id);
}






