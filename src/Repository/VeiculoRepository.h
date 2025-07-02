//
// Created by eec on 30/06/25.
//

#ifndef VEICULOREPOSITORY_H
#define VEICULOREPOSITORY_H
#include <vector>

#include "../Model/Veiculo.h"

class VeiculoRepository {
public:
    void salvarBackup(char caminho[]);
    std::vector<Veiculo> listar();
    Veiculo buscarPorId(int id);
    void excluir(int id);
    void salvarOuAtualizar(Veiculo veiculo);
    int gerarNovoId();
private:
    std::vector<Veiculo> veiculos;
};

#endif //VEICULOREPOSITORY_H
