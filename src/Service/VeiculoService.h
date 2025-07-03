//
// Created by eec on 19/06/25.
//

#ifndef VEICULOSERVICE_H
#define VEICULOSERVICE_H
#include <string>
#include <vector>

#include "../Model/Local.h"
#include "../Model/Veiculo.h"
#include "../Repository/VeiculoRepository.h"

enum EnumResultadoCriacaoVeiculo {
    SUCESSO_CRIACAO_DO_VEICULO,
    PLACA_DUPLICADA,
};

class VeiculoService {

    public:
        VeiculoService(VeiculoRepository &veiculoRepository);
        EnumResultadoCriacaoVeiculo criar(Veiculo veiculo);
        std::vector<Veiculo> listar();
        void excluir(int id);
        void updateStatus(std::string placa, bool status);
        void updateStatus(std::string placa, EnumStatusVeiculo status, PedidoService& pedidoService);
        void updateLocalAtual(std::string placa, Local local);
        void updateStatusEPedido(std::string placa, EnumStatusVeiculo status, int pedidoId);
        void verificarEAssociarPedidos(class PedidoService& pedidoService);
        bool validarPlaca(std::string placa);
    private:
        VeiculoRepository &veiculoRepository;
};

#endif //VEICULOSERVICE_H
