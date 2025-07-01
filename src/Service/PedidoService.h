//
// Created by eec on 19/06/25.
//

#ifndef PEDIDOSERVICE_H
#define PEDIDOSERVICE_H
#include <string>
#include <vector>

#include "../Model/Pedido.h"

enum EnumResultadoCriacaoPedido {
    SUCESSO_CRIACAO_DO_PEDIDO,
    ERRO_CRIACAO_DO_PEDIDO_SEM_LOCAL,
    ERRO_CRIACAO_DO_PEDIDO_COM_PESO_NEGATIVO,
};

class PedidoService {

    public:
        EnumResultadoCriacaoPedido criar(const Pedido& pedido, VeiculoService& veiculoService);
        std::vector<Pedido> listar();
        void update(int id);
        bool excluir(int id);
    private:
        std::vector<Pedido> pedidos;
};

#endif //PEDIDOSERVICE_H
