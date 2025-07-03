#include "VeiculoService.h"
#include "PedidoService.h"
#include <string>

#include "../Model/Local.h"
#include "../Model/Veiculo.h"
#include "../Utils/VeiculoUtils.h"
//
// Created by eec on 18/06/25.
//
EnumResultadoCriacaoVeiculo VeiculoService::criar(Veiculo &veiculo, PedidoService &pedidoService) {

    if (!validarPlaca(veiculo.placa)) {
        return PLACA_DUPLICADA;
    }

    veiculos.push_back(veiculo);

    // Se o veículo foi criado como disponível, verificar pedidos sem veículo
    if (veiculo.status == DISPONIVEL) {
        verificarEAssociarPedidos(pedidoService);
    }

    return SUCESSO_CRIACAO_DO_VEICULO;
}

bool VeiculoService::excluir(std::string placa) {
    for (int i = 0; i <= veiculos.size(); i++) {
        if (veiculos[i].placa == placa) {
            veiculos.erase(veiculos.begin() + i);
        } else {
            return false;
        }
    }

    return true;
}

std::vector<Veiculo> VeiculoService::listar() {
    return veiculos;
}

void VeiculoService::updateLocalAtual(std::string placa, Local local) {

}

void VeiculoService::updateStatus(std::string placa, bool status) {

}

void VeiculoService::updateStatus(std::string placa, EnumStatusVeiculo status, PedidoService& pedidoService) {
    for (auto& veiculo : veiculos) {
        if (veiculo.placa == placa) {
            veiculo.status = status;
            
            // Se o status foi alterado para disponível, verificar pedidos sem veículo
            if (status == DISPONIVEL) {
                veiculo.pedidoId = -1; // Remove associação de pedido anterior
                verificarEAssociarPedidos(pedidoService);
            }
            break;
        }
    }
}

void VeiculoService::updateStatusEPedido(std::string placa, EnumStatusVeiculo status, int pedidoId) {
    for (auto& veiculo : veiculos) {
        if (veiculo.placa == placa) {
            veiculo.status = status;
            veiculo.pedidoId = pedidoId;
            break;
        }
    }
}

void VeiculoService::verificarEAssociarPedidos(PedidoService& pedidoService) {
    // Buscar veículos disponíveis
    for (auto& veiculo : veiculos) {
        if (veiculo.status == DISPONIVEL) {
            // Buscar pedido sem veículo mais próximo
            std::vector<Pedido> pedidos = pedidoService.listar();
            Pedido* pedidoMaisProximo = VeiculoUtils::encontrarPedidoSemVeiculoMaisProximo(pedidos, veiculos, veiculo);
            
            if (pedidoMaisProximo != nullptr) {
                // Associar veículo ao pedido
                veiculo.status = OCUPADO;
                veiculo.pedidoId = pedidoMaisProximo->id;
                std::cout << "Veículo " << veiculo.placa << " foi automaticamente associado ao pedido " 
                          << pedidoMaisProximo->id << std::endl;
            }
        }
    }
}

bool VeiculoService::validarPlaca(std::string placa) {

    if (veiculos.empty()) {
        for (const auto& veiculo : veiculos) {
            if (veiculo.placa == placa) {
                return false;
            }
        }
    }

    return true;
}



