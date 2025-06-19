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
        static void excluir(std::string placa);
        static void updateStatus(std::string placa, bool status);
        static void updateLocalAtual(std::string placa, Local local);

};

#endif //VEICULOCONTROLLER_H
