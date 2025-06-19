//
// Created by eec on 19/06/25.
//

#ifndef VEICULOSERVICE_H
#define VEICULOSERVICE_H
#include <string>
#include <vector>

#include "../Model/Local.h"
#include "../Model/Veiculo.h"

class VeiculoService {

    public:
        void criar(Veiculo& veiculo);
        std::vector<Veiculo> listar();
        void excluir(std::string placa);
        void updateStatus(std::string placa, bool status);
        void updateLocalAtual(std::string placa, Local local);

    private:
        std::vector<Veiculo> veiculos;
};

#endif //VEICULOSERVICE_H
