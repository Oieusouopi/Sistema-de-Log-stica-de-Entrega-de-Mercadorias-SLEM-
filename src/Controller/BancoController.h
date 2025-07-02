//
// Created by eec on 30/06/25.
//

#ifndef BANCOCONTROLLER_H
#define BANCOCONTROLLER_H
#include "../Service/BancoService.h"

class BancoController {
    public:
        BancoController(BancoService &bancoService);
        void menu();
        void salvarDados();
        void restaurar();
    private:
        BancoService bancoService;
};

#endif //BANCOCONTROLLER_H
