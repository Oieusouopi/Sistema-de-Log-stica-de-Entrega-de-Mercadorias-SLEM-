//
// Created by eec on 18/06/25.
//

#ifndef ROTACONTROLLER_H
#define ROTACONTROLLER_H
#include "../Service/RotaService.h"

class RotaController {

    public:
        RotaController(RotaService &rotaService);
        void menu();

    private:
        RotaService &rotaService;

};

#endif //ROTACONTROLLER_H
