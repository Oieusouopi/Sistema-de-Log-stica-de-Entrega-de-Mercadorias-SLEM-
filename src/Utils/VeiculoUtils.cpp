//
// Created by eec on 30/06/25.
//

#include "VeiculoUtils.h"
#include <limits>
#include <iostream>

#include "../Service/LocalService.h"
#include "../Service/VeiculoService.h"


double VeiculoUtils::calcularDistancia(const Local& local1, const Local& local2) {
    double deltaX = local1.getX() - local2.getX();
    double deltaY = local1.getY() - local2.getY();
    return std::sqrt(deltaX * deltaX + deltaY * deltaY);
}

