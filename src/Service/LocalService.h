//
// Created by eec on 19/06/25.
//

#ifndef LOCALSERVICE_H
#define LOCALSERVICE_H
#include <string>

class LocalService {
    public:
        static void criar();
        static void listar();
        static void excluir(std::string nome);
};


#endif //LOCALSERVICE_H
