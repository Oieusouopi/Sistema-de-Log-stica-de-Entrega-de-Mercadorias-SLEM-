//
// Created by eec on 18/06/25.
//

#ifndef PEDIDOCONTROLLER_H
#define PEDIDOCONTROLLER_H
#include "../Service/PedidoService.h"

class PedidoController {
    public:
        PedidoController(PedidoService& pedidoService);
        void criar();
        void listar();
        void excluir();
        void update();
        void menu();

    private:
        PedidoService& pedidoService;
};

#endif //PEDIDOCONTROLLER_H
