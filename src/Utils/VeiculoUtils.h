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
    // Função que encontra o veículo mais próximo de um pedido
    static Veiculo* encontrarVeiculoMaisProximo(const std::vector<Veiculo>& veiculos, const Pedido& pedido);

private:
    // Função auxiliar para calcular a distância euclidiana entre dois locais
    static double calcularDistancia(const Local& local1, const Local& local2);
};

#endif //VEICULOUTILS_H
