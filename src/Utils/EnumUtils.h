//
//

#ifndef ENUMUTILS_H
#define ENUMUTILS_H

enum EnumStatusVeiculo {
    PENDENTE,
    DISPONIVEL,
    OCUPADO
};

std::string statusToString(EnumStatusVeiculo status);

#endif //ENUMUTILS_H
