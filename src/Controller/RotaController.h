//
// Created by eec on 18/06/25.
//

#ifndef ROTACONTROLLER_H
#define ROTACONTROLLER_H
#include "../Service/RotaService.h"

// Forward declarations
class PedidoService;
class VeiculoService;

class RotaController {

    public:
        RotaController(RotaService &rotaService, PedidoService &pedidoService, VeiculoService &veiculoService);
        void menu();
        void mostrarRotaPedido();

    private:
        RotaService &rotaService;
        PedidoService &pedidoService;
        VeiculoService &veiculoService;

};

#endif //ROTACONTROLLER_H
