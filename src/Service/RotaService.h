//
// Created by eec on 19/06/25.
//

#ifndef ROTASERVICE_H
#define ROTASERVICE_H

#include <vector>
#include <iostream>
#include "../Model/Pedido.h"
#include "../Model/Veiculo.h"

class RotaService {
public:
    void mostrarRota(const Pedido& pedido, const std::vector<Veiculo>& veiculos);
    
private:
    double calcularDistanciaTotal(const Veiculo& veiculo, const Pedido& pedido);
    double calcularDistancia(const Local& local1, const Local& local2);
    Veiculo* encontrarVeiculoAssociado(const Pedido& pedido, const std::vector<Veiculo>& veiculos);
};

#endif //ROTASERVICE_H
