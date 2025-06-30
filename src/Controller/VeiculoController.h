//
// Created by eec on 18/06/25.
//
#include <string>

#include "../Model/Local.h"
#include "../Service/LocalService.h"
#include "../Service/VeiculoService.h"

#ifndef VEICULOCONTROLLER_H
#define VEICULOCONTROLLER_H

class VeiculoController {

public:
    VeiculoController(VeiculoService &veiculoService, LocalService &localService);
    void criar();
    void listar();
    void excluir();
    void updateStatus();
    void updateLocalAtual();
    void menu();

private:
    VeiculoService& veiculoService;
    LocalService& localService;



};

#endif //VEICULOCONTROLLER_H
