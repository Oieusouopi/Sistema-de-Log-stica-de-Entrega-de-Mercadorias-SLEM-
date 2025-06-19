//
// Created by eec on 18/06/25.
//
#include <string>

#include "../Model/Local.h"

#ifndef VEICULOCONTROLLER_H
#define VEICULOCONTROLLER_H

class VeiculoController {
    public:
        static void criar();
        static void listar();
        static void excluir();
        static void updateStatus();
        static void updateLocalAtual();

};

#endif //VEICULOCONTROLLER_H
