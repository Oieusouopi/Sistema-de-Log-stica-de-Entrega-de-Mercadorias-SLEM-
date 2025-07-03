#include "PedidoRepository.h"

#include "../Model/Pedido.h"
//
// Created by eec on 30/06/25.
//

void PedidoRepository::salvarBackup(char caminho[]) {
    FILE* file = fopen(caminho, "wb");

    if (file == NULL) {
        std::cout << "Problema na abertura do arquivo";
        return;
    }

    int quantidade = pedidos.size();
    fwrite(&quantidade, sizeof(int), 1, file);

    for (const Pedido& local : pedidos) {
        fwrite(&local, sizeof(Pedido), 1, file);
    }

    fclose(file);
}

void PedidoRepository::restaurarBackup(char caminho[]) {
    FILE* file = fopen(caminho, "rb");

    if (file == NULL) {
        perror("Erro ao abrir arquivo");
        return;
    }

    int quantidade = 0;
    fread(&quantidade, sizeof(int), 1, file);

    pedidos.clear();

    for (int i = 0; i < quantidade; ++i) {
        Pedido pedido;
        fread(&pedido, sizeof(Pedido), 1, file);
        pedidos.push_back(pedido);
    }

    fclose(file);
}


void PedidoRepository::salvarOuAtualizar(Pedido pedido) {
    for (auto& p : pedidos) {
        if (p.getId() == pedido.getId()) {
            p = pedido;
            return;
        }
    }

    int novoId = gerarNovoId();

    pedido.setId(novoId);

    pedidos.push_back(pedido);
}

int PedidoRepository::gerarNovoId() {
    int maiorId = 0;

    for (const auto& pedido : pedidos) {
        if (pedido.getId() > maiorId) {
            maiorId = pedido.getId();
        }
    }

    return maiorId + 1;
}

std::vector<Pedido> PedidoRepository::listar() {
    return pedidos;
}

Pedido PedidoRepository::buscarPorId(int id) {
    for (auto& pedido : pedidos) {
        if (pedido.getId() == id) {
            return pedido;
        }
    }

    throw std::runtime_error("Pedido com ID " + std::to_string(id) + " não encontrado.");
}

void PedidoRepository::excluir(int id) {

    for (int i = 0; i <= pedidos.size(); i++) {
        if (pedidos[i].getId() == id) {
            pedidos.erase(pedidos.begin() + i);
        }
    }

}

