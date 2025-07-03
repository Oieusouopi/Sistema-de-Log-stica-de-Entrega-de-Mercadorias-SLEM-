//
// Created by eec on 30/06/25.
//

#ifndef PEDIDOREPOSITORY_H
#define PEDIDOREPOSITORY_H
#include "../Model/Pedido.h"

class PedidoRepository {
public:
    void salvarBackup(char caminho[]);
    void restaurarBackup(char caminho[]);
    std::vector<Pedido> listar();
    Pedido buscarPorId(int id);
    void excluir(int id);
    void salvarOuAtualizar(Pedido pedido);
    int gerarNovoId();
private:
     std::vector<Pedido> pedidos;
};

#endif //PEDIDOREPOSITORY_H
