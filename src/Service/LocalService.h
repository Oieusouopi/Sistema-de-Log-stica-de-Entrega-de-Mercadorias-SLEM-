//
// Created by eec on 19/06/25.
//

#ifndef LOCALSERVICE_H
#define LOCALSERVICE_H
#include <string>
#include <vector>
#include <algorithm>

#include "../Model/Local.h"
#include "../Repository/LocalRepository.h"

class LocalService {

    public:
        LocalService(LocalRepository &localRepository);
        void criar(const Local& local);
        std::vector<Local> listar();
        void excluirPorId(int id);
        bool existeId(int id);
        int gerarNovoId();
        bool existeEndereco(const char endereco[]) const;
        bool atualizarEnderecoPorId(int id, char novoEndereco[]);
        Local buscarPorId(int id);
    private:
        LocalRepository &localRepository;
};


#endif //LOCALSERVICE_H
