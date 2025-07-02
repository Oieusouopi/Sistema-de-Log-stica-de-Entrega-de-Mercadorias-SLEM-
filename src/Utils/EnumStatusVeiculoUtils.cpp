//
// Created by eec on 27/06/25.
//
#include <string>

#include "EnumUtils.h"

char* statusToString(EnumStatusVeiculo status) {
    switch (status) {
        case PENDENTE: return "Pendente";
        case DISPONIVEL: return "Disponível";
        case OCUPADO: return "Ocupado";
        default: return "Desconhecido";
    }
}
