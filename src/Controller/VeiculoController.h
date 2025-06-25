//
// Created by eec on 18/06/25.
//
#include <string>

#include "../Model/Local.h"
#include "../Service/VeiculoService.h"

#ifndef VEICULOCONTROLLER_H
#define VEICULOCONTROLLER_H

class VeiculoController {

public:
    VeiculoController(VeiculoService &veiculoService);
    void criar();
    void listar();
    void excluir();
    void updateStatus();
    void updateLocalAtual();
    void menu();

private:
    VeiculoService& veiculoService;
    Local selecionarLocal();


};

#endif //VEICULOCONTROLLER_H
