#include "VeiculoService.h"
#include "PedidoService.h"
#include <string>

#include "LocalService.h"
#include "../Model/Local.h"
#include "../Model/Veiculo.h"
#include "../Utils/VeiculoUtils.h"
//
// Created by eec on 18/06/25.
//

VeiculoService::VeiculoService(VeiculoRepository &veiculoRepository, PedidoService &pedidoService, LocalService &localService):
    veiculoRepository(veiculoRepository), pedidoService(pedidoService), localService(localService) {}

EnumResultadoCriacaoVeiculo VeiculoService::criar(Veiculo veiculo) {

    if (!validarPlaca(veiculo.getPlaca())) {
        return PLACA_DUPLICADA;
    }

    if (veiculo.getLocalAtualId() == -1) {
        return SEM_LOCAL_CADASTRADO;
    }

    veiculoRepository.salvarOuAtualizar(veiculo);

    // Se o veículo foi criado como disponível, verificar pedidos sem veículo
    if (veiculo.getStatus() == DISPONIVEL) {
        verificarEAssociarPedidos();
    }

    return SUCESSO_CRIACAO_DO_VEICULO;
}

void VeiculoService::excluir(int id) {
    veiculoRepository.excluir(id);
}

std::vector<Veiculo> VeiculoService::listar() {
    return veiculoRepository.listar();
}

void VeiculoService::updateLocalAtual(std::string placa, Local local) {

}

void VeiculoService::updateStatus(std::string placa, EnumStatusVeiculo status) {
    std::vector<Veiculo> veiculos = veiculoRepository.listar();
    for (auto& veiculo : veiculos) {
        if (veiculo.getPlaca() == placa) {
            veiculo.setStatus(status);

            // Se o status foi alterado para disponível, verificar pedidos sem veículo
            if (status == DISPONIVEL) {
                veiculo.setPedidoId(-1);
                verificarEAssociarPedidos();
            }
            break;
        }
        veiculoRepository.salvarOuAtualizar(veiculo);
    }
}

void VeiculoService::updateStatusEPedido(int id, EnumStatusVeiculo status, int pedidoId) {
    Veiculo veiculo = veiculoRepository.buscarPorId(id);

    veiculo.setStatus(status);
    veiculo.setPedidoId(pedidoId);

    veiculoRepository.salvarOuAtualizar(veiculo);
}

void VeiculoService::verificarEAssociarPedidos() {
    std::vector<Veiculo> veiculos = veiculoRepository.listar();

    for (auto& veiculo : veiculos) {
        if (veiculo.getStatus() == DISPONIVEL) {
            // Buscar pedido sem veículo mais próximo
            std::vector<Pedido> pedidos = pedidoService.listar();
            Pedido pedidoMaisProximo = pedidoService.encontrarPedidoSemVeiculoMaisProximo(veiculo);

            if (pedidoMaisProximo.getId() != -1) {
                // Associar veículo ao pedido
                veiculo.setStatus(OCUPADO);
                veiculo.setPedidoId(pedidoMaisProximo.getId());
                std::cout << "Veículo " << veiculo.getPlaca() << " foi automaticamente associado ao pedido "
                          << pedidoMaisProximo.getId() << std::endl;
            }
        }
    }
}

bool VeiculoService::validarPlaca(std::string placa) {

    std::vector<Veiculo> veiculos = veiculoRepository.listar();

    if (veiculos.empty()) {
        for (auto& veiculo : veiculos) {
            if (veiculo.getPlaca() == placa) {
                return false;
            }
        }
    }

    return true;
}

Veiculo VeiculoService::encontrarVeiculoMaisProximo(Pedido pedido) {
    std::vector<Veiculo> veiculos = veiculoRepository.listar();

    if (veiculos.empty()) {
        std::cout << "Nenhum veículo disponível para buscar o seu pedido. Aguarde...\n";
        return Veiculo();
    }

    Veiculo veiculoMaisProximo;
    double menorDistancia = std::numeric_limits<double>::max();

    for (const Veiculo& veiculo : veiculos) {
        if (veiculo.getStatus() != DISPONIVEL) {
            continue;
        }

        Local localAtual = localService.buscarPorId(veiculo.getLocalAtualId());
        double distancia = VeiculoUtils::calcularDistancia(localAtual, pedido.getLocalOrigem());

        if (distancia < menorDistancia) {
            menorDistancia = distancia;
            veiculoMaisProximo = veiculo;
        }
    }

    if (veiculoMaisProximo.getId() == -1) {
        std::cout << "Nenhum veículo disponível encontrado.\n";
    } else {
        std::cout << "Veículo mais próximo encontrado: " << veiculoMaisProximo.getPlaca()
                  << " (Distância: " << menorDistancia << ")\n";
    }

    return veiculoMaisProximo;
}

Veiculo VeiculoService::buscarPorId(int id) {
    return veiculoRepository.buscarPorId(id);
}




