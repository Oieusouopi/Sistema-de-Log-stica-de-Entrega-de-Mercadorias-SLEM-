//
// Created by eec on 18/06/25.
//

#include "RotaService.h"
#include <cmath>
#include <iomanip>

RotaService::RotaService(VeiculoService &veiculoService, LocalService &localService): veiculoService(veiculoService), localService(localService) {}


void RotaService::mostrarRota(Pedido pedido) {
    std::vector<Veiculo> veiculos = veiculoService.listar();

    Veiculo veiculoAssociado = encontrarVeiculoAssociado(pedido);
    Local localAssociado = localService.buscarPorId(veiculoAssociado.getLocalAtualId());
    
    if (veiculoAssociado.getId() == -1) {
        std::cout << "\n========== ROTA DO PEDIDO ==========\n";
        std::cout << "Pedido ID: " << pedido.getId() << std::endl;
        std::cout << "Status: SEM VEÍCULO ASSOCIADO" << std::endl;
        std::cout << "Local de Origem: " << pedido.getLocalOrigem().getEndereco() << std::endl;
        std::cout << "Local de Destino: " << pedido.getLocalDestino().getEndereco() << std::endl;
        std::cout << "===================================\n";
        return;
    }
    
    // Calcular distância total
    double distanciaTotal = calcularDistanciaTotal(veiculoAssociado, pedido);
    
    // Exibir informações da rota
    std::cout << "\n========== ROTA DO PEDIDO ==========\n";
    std::cout << "Pedido ID: " << pedido.getId() << std::endl;
    std::cout << "Veículo Selecionado: " << veiculoAssociado.getPlaca()
              << " (" << veiculoAssociado.getModelo() << ")" << std::endl;
    std::cout << "Status do Veículo: ";
    switch(veiculoAssociado.getStatus()) {
        case PENDENTE: std::cout << "PENDENTE"; break;
        case DISPONIVEL: std::cout << "DISPONÍVEL"; break;
        case OCUPADO: std::cout << "OCUPADO"; break;
    }
    std::cout << std::endl;
    
    std::cout << "\n--- TRAJETO ---" << std::endl;
    std::cout << "1. Local Atual do Veículo: " << localAssociado.getEndereco()
              << " (x: " << std::fixed << std::setprecision(2) << localAssociado.getX()
              << ", y: " << localAssociado.getY() << ")" << std::endl;
              
    std::cout << "2. Local de Origem do Pedido: " << pedido.getLocalOrigem().getEndereco()
              << " (x: " << std::fixed << std::setprecision(2) << pedido.getLocalOrigem().getX()
              << ", y: " << pedido.getLocalOrigem().getY() << ")" << std::endl;
              
    std::cout << "3. Local de Destino do Pedido: " << pedido.getLocalDestino().getEndereco()
              << " (x: " << std::fixed << std::setprecision(2) << pedido.getLocalDestino().getX()
              << ", y: " << pedido.getLocalDestino().getY() << ")" << std::endl;
    
    std::cout << "\n--- DISTÂNCIAS ---" << std::endl;
    double distanciaVeiculoOrigem = calcularDistancia(localAssociado, pedido.getLocalOrigem());
    double distanciaOrigemDestino = calcularDistancia(pedido.getLocalOrigem(), pedido.getLocalDestino());
    
    std::cout << "Veículo → Origem: " << std::fixed << std::setprecision(2) 
              << distanciaVeiculoOrigem << " unidades" << std::endl;
    std::cout << "Origem → Destino: " << std::fixed << std::setprecision(2) 
              << distanciaOrigemDestino << " unidades" << std::endl;
    std::cout << "DISTÂNCIA TOTAL: " << std::fixed << std::setprecision(2) 
              << distanciaTotal << " unidades" << std::endl;
              
    std::cout << "\nPeso do Item: " << pedido.getPesoItem() << " kg" << std::endl;
    std::cout << "===================================\n";
}

double RotaService::calcularDistanciaTotal(Veiculo veiculo, Pedido pedido) {
    Local localAssociado = localService.buscarPorId(veiculo.getLocalAtualId());
    // Distância do veículo até o local de origem do pedido
    double distanciaVeiculoOrigem = calcularDistancia(localAssociado, pedido.getLocalOrigem());
    
    // Distância do local de origem até o local de destino do pedido
    double distanciaOrigemDestino = calcularDistancia(pedido.getLocalOrigem(), pedido.getLocalDestino());
    
    return distanciaVeiculoOrigem + distanciaOrigemDestino;
}

double RotaService::calcularDistancia(const Local& local1, const Local& local2) {
    double deltaX = local1.getX() - local2.getX();
    double deltaY = local1.getY() - local2.getY();
    return std::sqrt(deltaX * deltaX + deltaY * deltaY);
}

Veiculo RotaService::encontrarVeiculoAssociado(Pedido pedido) {
    std::vector<Veiculo> veiculos = veiculoService.listar();

    for (size_t i = 0; i < veiculos.size(); ++i) {
        if (veiculos[i].getPedidoId() == pedido.getId()) {
            return veiculos[i];
        }
    }

    Veiculo veiculo = Veiculo();
    veiculo.setId(-1);

    return veiculo;
}
