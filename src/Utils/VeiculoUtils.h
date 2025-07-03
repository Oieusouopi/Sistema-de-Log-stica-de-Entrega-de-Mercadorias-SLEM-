//
// Created by eec on 30/06/25.
//

#ifndef VEICULOUTILS_H
#define VEICULOUTILS_H

#include <vector>
#include <cmath>
#include "../Model/Veiculo.h"
#include "../Model/Pedido.h"

class VeiculoUtils {
public:
    static Veiculo* encontrarVeiculoMaisProximo(const std::vector<Veiculo>& veiculos, const Pedido& pedido);
    static Pedido* encontrarPedidoSemVeiculoMaisProximo(const std::vector<Pedido>& pedidos, const std::vector<Veiculo>& veiculos, const Veiculo& veiculoDisponivel);

private:
    static double calcularDistancia(const Local& local1, const Local& local2);
};

#endif //VEICULOUTILS_H
