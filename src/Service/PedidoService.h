//
// Created by eec on 19/06/25.
//

#ifndef PEDIDOSERVICE_H
#define PEDIDOSERVICE_H
#include <string>

class PedidoService {
    public:
        static void criar();
        static void listar();
        static void update(int id);
        static void excluir(int id);
};

#endif //PEDIDOSERVICE_H
