//
// Created by eec on 19/06/25.
//

#ifndef ROTASERVICE_H
#define ROTASERVICE_H

#include <vector>
#include <iostream>

#include "LocalService.h"
#include "VeiculoService.h"
#include "../Model/Pedido.h"
#include "../Model/Veiculo.h"

class RotaService {
public:
    RotaService(VeiculoService &veiculoService, LocalService &localService);
    void mostrarRota(Pedido pedido);
    
private:
    VeiculoService &veiculoService;
    LocalService &localService;
    double calcularDistanciaTotal(Veiculo veiculo, Pedido pedido);
    double calcularDistancia(const Local& local1, const Local& local2);

    Veiculo encontrarVeiculoAssociado(Pedido pedido);
};

#endif //ROTASERVICE_H
