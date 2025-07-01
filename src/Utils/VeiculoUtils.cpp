//
// Created by eec on 30/06/25.
//

#include "VeiculoUtils.h"
#include <limits>
#include <iostream>

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
