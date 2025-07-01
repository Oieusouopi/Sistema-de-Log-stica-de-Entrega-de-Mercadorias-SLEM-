//
// Created by eec on 19/06/25.
//

#ifndef VEICULOSERVICE_H
#define VEICULOSERVICE_H
#include <string>
#include <vector>

#include "../Model/Local.h"
#include "../Model/Veiculo.h"
#include "../Utils/EnumUtils.h"

// Forward declaration
class PedidoService;

enum EnumResultadoCriacaoVeiculo {
    SUCESSO_CRIACAO_DO_VEICULO,
    PLACA_DUPLICADA,
};

class VeiculoService {

    public:
        EnumResultadoCriacaoVeiculo criar(Veiculo& veiculo, PedidoService& pedidoService);
        std::vector<Veiculo> listar();
        bool excluir(std::string placa);
        void updateStatus(std::string placa, bool status);
        void updateStatus(std::string placa, EnumStatusVeiculo status, PedidoService& pedidoService);
        void updateLocalAtual(std::string placa, Local local);
        void updateStatusEPedido(std::string placa, EnumStatusVeiculo status, int pedidoId);
        void verificarEAssociarPedidos(class PedidoService& pedidoService);
        bool validarPlaca(std::string placa);
    private:
        std::vector<Veiculo> veiculos;
};

#endif //VEICULOSERVICE_H
