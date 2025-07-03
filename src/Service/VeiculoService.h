//
// Created by eec on 19/06/25.
//

#ifndef VEICULOSERVICE_H
#define VEICULOSERVICE_H
#include <string>
#include <vector>

#include "LocalService.h"
#include "PedidoService.h"
#include "../Model/Local.h"
#include "../Model/Veiculo.h"
#include "../Repository/VeiculoRepository.h"
#include "../Model/Pedido.h"

enum EnumResultadoCriacaoVeiculo {
    SUCESSO_CRIACAO_DO_VEICULO,
    PLACA_DUPLICADA,
    SEM_LOCAL_CADASTRADO
};

class PedidoService;

class VeiculoService {

    public:
        VeiculoService(VeiculoRepository &veiculoRepository, PedidoService &pedidoService, LocalService &localService);
        EnumResultadoCriacaoVeiculo criar(Veiculo veiculo);
        std::vector<Veiculo> listar();
        void excluir(int id);
        void updateStatus(std::string placa, bool status);
        void updateStatus(std::string placa, EnumStatusVeiculo status);
        void updateLocalAtual(std::string placa, Local local);
        void updateStatusEPedido(int id, EnumStatusVeiculo status, int pedidoId);
        void verificarEAssociarPedidos();
        bool validarPlaca(std::string placa);
        Veiculo encontrarVeiculoMaisProximo(Pedido pedido);
        Veiculo buscarPorId(int id);
    private:
        VeiculoRepository &veiculoRepository;
        PedidoService &pedidoService;
        LocalService &localService;
};

#endif //VEICULOSERVICE_H
