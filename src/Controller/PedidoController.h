//
// Created by eec on 18/06/25.
//

#ifndef PEDIDOCONTROLLER_H
#define PEDIDOCONTROLLER_H
#include "../Service/LocalService.h"
#include "../Service/PedidoService.h"
#include "../Service/VeiculoService.h"

class PedidoController {
    public:
        PedidoController(PedidoService& pedidoService, LocalService& localService, VeiculoService& veiculoService);
        void criar();
        void listar();
        void excluir();
        void update();
        void menu();

    private:
        PedidoService& pedidoService;
        LocalService& localService;
        VeiculoService& veiculoService;
};

#endif //PEDIDOCONTROLLER_H
