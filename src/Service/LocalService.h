//
// Created by eec on 19/06/25.
//

#ifndef LOCALSERVICE_H
#define LOCALSERVICE_H
#include <string>
#include <vector>
#include <algorithm>

#include "../Model/Local.h"

class LocalService {

    public:
        void criar(const Local& local);
        std::vector<Local> listar();
        void excluirPorId(int id);
        bool existeId(int id);
        int gerarNovoId();
        bool existeEndereco(const std::string& endereco) const;


    private:
        std::vector<Local> locais;
};


#endif //LOCALSERVICE_H
