//
// Created by eec on 28/06/25.
//

#ifndef LOCALUTILS_H
#define LOCALUTILS_H
#include <vector>

#include "../Model/Local.h"
#include "../Service/LocalService.h"

class LocalUtils {
public:
    static Local selecionarLocal(std::vector<Local> locais);
    static Local selecionarLocal(LocalService& localService);
};

#endif //LOCALUTILS_H
