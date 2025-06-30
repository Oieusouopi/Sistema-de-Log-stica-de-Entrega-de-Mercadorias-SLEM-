//
// Created by eec on 30/06/25.
//

#ifndef LOCALREPOSITORY_H
#define LOCALREPOSITORY_H
#include <string>
#include <vector>

#include "../Model/Local.h"

class LocalRepository {

public:
    static int proximoId;
    void salvarTodos(char caminho[]);
    void salvarNoBanco();
    std::vector<Local> listar();
    Local buscarPorId(int id);
    void excluir(int id);
    bool salvarOuAtualizar(Local local);
    int gerarNovoId();

    private:
        std::vector<Local> locais;
};

#endif //LOCALREPOSITORY_H
