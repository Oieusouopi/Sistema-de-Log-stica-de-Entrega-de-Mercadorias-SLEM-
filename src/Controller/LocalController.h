//
// Created by eec on 18/06/25.
//

#ifndef LOCALCONTROLLER_H
#define LOCALCONTROLLER_H
#include "../Service/LocalService.h"

class LocalController {
    public:
        LocalController(LocalService& localService);
        void criar();
        void listar();
        void excluir();
        void menu();

    private:
        LocalService& localService;
};

#endif //LOCALCONTROLLER_H
