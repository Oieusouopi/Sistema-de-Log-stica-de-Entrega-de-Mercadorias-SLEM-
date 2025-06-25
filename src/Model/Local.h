//
// Created by eec on 18/06/25.
//

#ifndef LOCAL_H
#define LOCAL_H
#include <string.h>

class Local {
public:
    Local(char *nome) {
        strncpy(this->nome, nome, sizeof(this->nome - 1));
        this->nome[sizeof(this->nome) - 1] = '\0';

    }
    char nome[30];

};

#endif //LOCAL_H
