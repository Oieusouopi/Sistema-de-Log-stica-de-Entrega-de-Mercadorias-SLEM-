//
// Created by eec on 19/06/25.
//

#ifndef LOCALSERVICE_H
#define LOCALSERVICE_H
#include <string>
#include <vector>

#include "../Model/Local.h"

class LocalService {

    public:
        void criar(const Local& local);
        std::vector<Local> listar();
        void excluir(std::string nome);
        void encontrarlocalid(int id);

    private:
        std::vector<Local> locais;
};


#endif //LOCALSERVICE_H
