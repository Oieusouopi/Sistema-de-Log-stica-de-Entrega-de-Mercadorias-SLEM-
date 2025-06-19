//
// Created by eec on 19/06/25.
//

#ifndef LOCALSERVICE_H
#define LOCALSERVICE_H
#include <string>
#include <vector>

#include "../Model/Local.h"
#include "../Model/Veiculo.h"

class LocalService {

    public:
        void criar(const Local& local);
        std::vector<Veiculo> listar();
        void excluir(std::string nome);

    private:
        std::vector<Veiculo> veiculos;
};


#endif //LOCALSERVICE_H
