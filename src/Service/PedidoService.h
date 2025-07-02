//
// Created by eec on 19/06/25.
//

#ifndef PEDIDOSERVICE_H
#define PEDIDOSERVICE_H
#include <string>
#include <vector>

#include "../Model/Pedido.h"
#include "../Repository/PedidoRepository.h"

enum EnumResultadoCriacaoPedido {
    SUCESSO_CRIACAO_DO_PEDIDO,
    ERRO_CRIACAO_DO_PEDIDO_SEM_LOCAL,
    ERRO_CRIACAO_DO_PEDIDO_COM_PESO_NEGATIVO,
};

class PedidoService {

    public:
        PedidoService(PedidoRepository &pedidoRespository);
        EnumResultadoCriacaoPedido criar(Pedido pedido);
        std::vector<Pedido> listar();
        void update(int id);
        void excluir(int id);
    private:
        PedidoRepository &pedidoRepository;
};

#endif //PEDIDOSERVICE_H
