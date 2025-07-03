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

    if (veiculo.getStatus() == DISPONIVEL) {
        verificarEAssociarPedidos();
    }

    return SUCESSO_CRIACAO_DO_VEICULO;
}

void VeiculoService::excluir(int id) {
    Veiculo veiculo = veiculoRepository.buscarPorId(id);

    if (veiculo.getPedidoId() != -1) {
        Pedido pedido = pedidoService.buscarPorId(veiculo.getPedidoId());
        pedido.setVeiculoVinculadoId(-1);
        pedidoService.salvarOuAtualizar(pedido);
    }

    veiculoRepository.excluir(id);
}

std::vector<Veiculo> VeiculoService::listar() {
    return veiculoRepository.listar();
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
            std::vector<Pedido> pedidos = pedidoService.listar();
            Pedido pedidoMaisProximo = pedidoService.encontrarPedidoSemVeiculoMaisProximo(veiculo);

            if (pedidoMaisProximo.getId() != -1) {
                veiculo.setStatus(OCUPADO);
                veiculo.setPedidoId(pedidoMaisProximo.getId());
                pedidoMaisProximo.setVeiculoVinculadoId(veiculo.getId());

                veiculoRepository.salvarOuAtualizar(veiculo);
                pedidoService.salvarOuAtualizar(pedidoMaisProximo);
                std::cout << "Veículo " << veiculo.getPlaca() << " foi automaticamente associado ao pedido "
                          << pedidoMaisProximo.getId() << std::endl;
            }
        }
    }
}

bool VeiculoService::validarPlaca(const char* placa) {
    std::vector<Veiculo> veiculos = veiculoRepository.listar();

    for (const Veiculo& veiculo : veiculos) {
        if (std::strcmp(veiculo.getPlaca(), placa) == 0) {
            return false; // placa já existe
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

bool VeiculoService::atualizarPlacaPorId(int id, const char* novaPlaca) {
    Veiculo veiculo = veiculoRepository.buscarPorId(id);

    if (!validarPlaca(novaPlaca)) {
        std::cout << "Erro: placa já existe no sistema.\n";
        return false;
    }

    if (veiculo.getId() == -1) {
        return false;
    }

    veiculo.setPlaca(novaPlaca);

    veiculoRepository.salvarOuAtualizar(veiculo);

    return true;
}

bool VeiculoService::atualizarLocalAtualPorId(int id, int novoLocalId) {
    Local local = localService.buscarPorId(novoLocalId);
    Veiculo veiculo = veiculoRepository.buscarPorId(id);
    if (local.getId() == -1) {
        return false;
    }

    veiculo.setLocalAtualId(novoLocalId);

    veiculoRepository.salvarOuAtualizar(veiculo);

    return true;
}

