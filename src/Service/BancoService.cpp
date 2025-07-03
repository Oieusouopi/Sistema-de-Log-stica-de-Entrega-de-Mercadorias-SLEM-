#include "BancoService.h"
//
// Created by rafas on 02/07/2025.
//
BancoService::BancoService(PedidoRepository &pedidoRespository, LocalRepository &localRepository, VeiculoRepository &veiculoRepository):
    pedidoRepository(pedidoRespository), localRepository(localRepository), veiculoRepository(veiculoRepository) {}

void BancoService::salvarBackup() {
    pedidoRepository.salvarBackup("../src/Storage/pedido.bin");
    localRepository.salvarBackup("../src/Storage/local.bin");
    veiculoRepository.salvarBackup("../src/Storage/veiculo.bin");
}

void BancoService::restaurarBackup() {
    pedidoRepository.restaurarBackup("../src/Storage/pedido.bin");
    localRepository.restaurarBackup("../src/Storage/local.bin");
    veiculoRepository.restaurarBackup("../src/Storage/veiculo.bin");
}

