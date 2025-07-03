//
//

#ifndef ENUMUTILS_H
#define ENUMUTILS_H

enum EnumStatusVeiculo {
    PENDENTE,
    DISPONIVEL,
    OCUPADO
};

char* statusToString(EnumStatusVeiculo status);

#endif //ENUMUTILS_H
