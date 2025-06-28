//
// Created by eec on 27/06/25.
//
#include "EnumStatusVeiculoUtils.h"

std::string statusToString(EnumStatusVeiculo status) {
    switch (status) {
        case PENDENTE: return "PENDENTE";
        default: return "DESCONHECIDO";
    }
}