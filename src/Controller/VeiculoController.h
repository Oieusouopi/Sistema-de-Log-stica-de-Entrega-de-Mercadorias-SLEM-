//
// Created by eec on 18/06/25.
//
#include <string>

#include "../Model/Local.h"
#include "../Service/VeiculoService.h"
#include "../Service/LocalService.h"

#ifndef VEICULOCONTROLLER_H
#define VEICULOCONTROLLER_H

class VeiculoController {
    private:
        VeiculoService veiculoService;

    public:
        void atualizarStatusVeiculo();
        void atualizarLocalAtualVeiculo();
};

#endif //VEICULOCONTROLLER_H
