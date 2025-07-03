//
// Created by eec on 19/06/25.
//

#ifndef PEDIDOSERVICE_H
#define PEDIDOSERVICE_H
#include <string>
#include <vector>

#include "VeiculoService.h"
#include "../Model/Pedido.h"
#include "../Repository/PedidoRepository.h"
#include "../Model/Veiculo.h"

enum EnumResultadoCriacaoPedido {
    SUCESSO_CRIACAO_DO_PEDIDO,
    ERRO_CRIACAO_DO_PEDIDO_SEM_LOCAL,
    ERRO_CRIACAO_DO_PEDIDO_COM_PESO_NEGATIVO,
};

class VeiculoService;
class LocalService;

class PedidoService {

    public:
        PedidoService(PedidoRepository &pedidoRespository, VeiculoService &veiculoService, LocalService &localService);
        EnumResultadoCriacaoPedido criar(Pedido pedido);
        std::vector<Pedido> listar();
        void update(int id);
        void excluir(int id);
        Pedido encontrarPedidoSemVeiculoMaisProximo(Veiculo veiculoDisponivel);
    private:
        PedidoRepository &pedidoRepository;
        VeiculoService &veiculoService;
        LocalService &localService;
};

#endif //PEDIDOSERVICE_H
