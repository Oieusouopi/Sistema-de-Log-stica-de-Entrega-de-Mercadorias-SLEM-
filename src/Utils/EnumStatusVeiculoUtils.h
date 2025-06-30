//
// Created by eec on 27/06/25.
//

#include <string>


#ifndef ENUMSTATUSVEICULOUTILS_H
#define ENUMSTATUSVEICULOUTILS_H

#include "EnumStatusVeiculoUtils.h"
#include "EnumUtils.h"
enum EnumStatusVeiculo {
    PENDENTE,
    DISPONIVEL,
    OCUPADO
};

std::string statusToString(EnumStatusVeiculo status);

#endif //ENUMSTATUSVEICULOUTILS_H
