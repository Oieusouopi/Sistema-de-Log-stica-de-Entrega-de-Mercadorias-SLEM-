//
// Created by eec on 30/06/25.
//

#include "VeiculoUtils.h"
#include <limits>
#include <iostream>
#include <set>

Veiculo* VeiculoUtils::encontrarVeiculoMaisProximo(const std::vector<Veiculo>& veiculos, const Pedido& pedido) {
    if (veiculos.empty()) {
        std::cout << "Nenhum veículo disponível.\n";
        return nullptr;
    }

    Veiculo* veiculoMaisProximo = nullptr;
    double menorDistancia = std::numeric_limits<double>::max();

    for (size_t i = 0; i < veiculos.size(); ++i) {
        if (veiculos[i].status == DISPONIVEL) {
            double distancia = calcularDistancia(veiculos[i].localAtual, pedido.localOrigem);
            
            if (distancia < menorDistancia) {
                menorDistancia = distancia;
                veiculoMaisProximo = const_cast<Veiculo*>(&veiculos[i]);
            }
        }
    }

    if (veiculoMaisProximo == nullptr) {
        std::cout << "Nenhum veículo disponível encontrado.\n";
    } else {
        std::cout << "Veículo mais próximo encontrado: " << veiculoMaisProximo->placa 
                  << " (Distância: " << menorDistancia << ")\n";
    }

    return veiculoMaisProximo;
}

double VeiculoUtils::calcularDistancia(const Local& local1, const Local& local2) {
    double deltaX = local1.getX() - local2.getX();
    double deltaY = local1.getY() - local2.getY();
    return std::sqrt(deltaX * deltaX + deltaY * deltaY);
}

Pedido* VeiculoUtils::encontrarPedidoSemVeiculoMaisProximo(const std::vector<Pedido>& pedidos, const std::vector<Veiculo>& veiculos, const Veiculo& veiculoDisponivel) {
    if (pedidos.empty()) {
        return nullptr;
    }

    // Criar lista de IDs de pedidos que já têm veículo associado
    std::set<int> pedidosComVeiculo;
    for (const auto& veiculo : veiculos) {
        if (veiculo.status == OCUPADO && veiculo.pedidoId != -1) {
            pedidosComVeiculo.insert(veiculo.pedidoId);
        }
    }

    Pedido* pedidoMaisProximo = nullptr;
    double menorDistancia = std::numeric_limits<double>::max();

    for (size_t i = 0; i < pedidos.size(); ++i) {
        // Verifica se o pedido já tem veículo associado
        if (pedidosComVeiculo.find(pedidos[i].id) == pedidosComVeiculo.end()) {
            double distancia = calcularDistancia(veiculoDisponivel.localAtual, pedidos[i].localOrigem);
            
            if (distancia < menorDistancia) {
                menorDistancia = distancia;
                pedidoMaisProximo = const_cast<Pedido*>(&pedidos[i]);
            }
        }
    }

    if (pedidoMaisProximo != nullptr) {
        std::cout << "Pedido sem veículo encontrado para o veículo " << veiculoDisponivel.placa 
                  << ": Pedido ID " << pedidoMaisProximo->id << " (Distância: " << menorDistancia << ")\n";
    }

    return pedidoMaisProximo;
}
