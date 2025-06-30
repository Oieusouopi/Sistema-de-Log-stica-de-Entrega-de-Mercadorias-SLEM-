//
// Created by eec on 19/06/25.
//

#ifndef VEICULOSERVICE_H
#define VEICULOSERVICE_H
#include <string>
#include <vector>

#include "../Model/Local.h"
#include "../Model/Veiculo.h"
#include "../Utils/EnumStatusVeiculoUtils.h"

enum EnumResultadoCriacaoVeiculo {
    SUCESSO_CRIACAO_DO_VEICULO,
    PLACA_DUPLICADA,
};

class VeiculoService {

    public:
        EnumResultadoCriacaoVeiculo criar(Veiculo& veiculo);
        std::vector<Veiculo> listar();
        bool excluir(std::string placa);
        bool updateStatus(std::string placa, EnumStatusVeiculo status);
        void updateLocalAtual(std::string placa, Local local);
        bool validarPlaca(std::string placa);
    private:
        std::vector<Veiculo> veiculos;
};

#endif //VEICULOSERVICE_H
