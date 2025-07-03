//
// Created by eec on 18/06/25.
//

#include "RotaService.h"
#include <cmath>
#include <iomanip>

void RotaService::mostrarRota(const Pedido& pedido, const std::vector<Veiculo>& veiculos) {
    // Encontrar o veículo associado ao pedido
    Veiculo* veiculoAssociado = encontrarVeiculoAssociado(pedido, veiculos);
    
    if (veiculoAssociado == nullptr) {
        std::cout << "\n========== ROTA DO PEDIDO ==========\n";
        std::cout << "Pedido ID: " << pedido.id << std::endl;
        std::cout << "Status: SEM VEÍCULO ASSOCIADO" << std::endl;
        std::cout << "Local de Origem: " << pedido.localOrigem.getEndereco() << std::endl;
        std::cout << "Local de Destino: " << pedido.localDestino.getEndereco() << std::endl;
        std::cout << "===================================\n";
        return;
    }
    
    // Calcular distância total
    double distanciaTotal = calcularDistanciaTotal(*veiculoAssociado, pedido);
    
    // Exibir informações da rota
    std::cout << "\n========== ROTA DO PEDIDO ==========\n";
    std::cout << "Pedido ID: " << pedido.id << std::endl;
    std::cout << "Veículo Selecionado: " << veiculoAssociado->placa 
              << " (" << veiculoAssociado->modelo << ")" << std::endl;
    std::cout << "Status do Veículo: ";
    switch(veiculoAssociado->status) {
        case PENDENTE: std::cout << "PENDENTE"; break;
        case DISPONIVEL: std::cout << "DISPONÍVEL"; break;
        case OCUPADO: std::cout << "OCUPADO"; break;
    }
    std::cout << std::endl;
    
    std::cout << "\n--- TRAJETO ---" << std::endl;
    std::cout << "1. Local Atual do Veículo: " << veiculoAssociado->localAtual.getEndereco() 
              << " (x: " << std::fixed << std::setprecision(2) << veiculoAssociado->localAtual.getX() 
              << ", y: " << veiculoAssociado->localAtual.getY() << ")" << std::endl;
              
    std::cout << "2. Local de Origem do Pedido: " << pedido.localOrigem.getEndereco()
              << " (x: " << std::fixed << std::setprecision(2) << pedido.localOrigem.getX() 
              << ", y: " << pedido.localOrigem.getY() << ")" << std::endl;
              
    std::cout << "3. Local de Destino do Pedido: " << pedido.localDestino.getEndereco()
              << " (x: " << std::fixed << std::setprecision(2) << pedido.localDestino.getX() 
              << ", y: " << pedido.localDestino.getY() << ")" << std::endl;
    
    std::cout << "\n--- DISTÂNCIAS ---" << std::endl;
    double distanciaVeiculoOrigem = calcularDistancia(veiculoAssociado->localAtual, pedido.localOrigem);
    double distanciaOrigemDestino = calcularDistancia(pedido.localOrigem, pedido.localDestino);
    
    std::cout << "Veículo → Origem: " << std::fixed << std::setprecision(2) 
              << distanciaVeiculoOrigem << " unidades" << std::endl;
    std::cout << "Origem → Destino: " << std::fixed << std::setprecision(2) 
              << distanciaOrigemDestino << " unidades" << std::endl;
    std::cout << "DISTÂNCIA TOTAL: " << std::fixed << std::setprecision(2) 
              << distanciaTotal << " unidades" << std::endl;
              
    std::cout << "\nPeso do Item: " << pedido.pesoDoItem << " kg" << std::endl;
    std::cout << "===================================\n";
}

double RotaService::calcularDistanciaTotal(const Veiculo& veiculo, const Pedido& pedido) {
    // Distância do veículo até o local de origem do pedido
    double distanciaVeiculoOrigem = calcularDistancia(veiculo.localAtual, pedido.localOrigem);
    
    // Distância do local de origem até o local de destino do pedido
    double distanciaOrigemDestino = calcularDistancia(pedido.localOrigem, pedido.localDestino);
    
    return distanciaVeiculoOrigem + distanciaOrigemDestino;
}

double RotaService::calcularDistancia(const Local& local1, const Local& local2) {
    double deltaX = local1.getX() - local2.getX();
    double deltaY = local1.getY() - local2.getY();
    return std::sqrt(deltaX * deltaX + deltaY * deltaY);
}

Veiculo* RotaService::encontrarVeiculoAssociado(const Pedido& pedido, const std::vector<Veiculo>& veiculos) {
    for (size_t i = 0; i < veiculos.size(); ++i) {
        if (veiculos[i].pedidoId == pedido.id) {
            return const_cast<Veiculo*>(&veiculos[i]);
        }
    }
    return nullptr;
}
