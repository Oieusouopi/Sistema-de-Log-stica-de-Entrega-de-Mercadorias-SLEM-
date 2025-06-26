//
// Created by eec on 18/06/25.
//

#ifndef VEICULO_H
#define VEICULO_H
#include <cstring>

class Veiculo {
private:
    char placa[7];
    char modelo [50];
    bool status;
    Local local;
public:
    Veiculo(char p[], char m[], bool s=false) {
        strcpy(placa, p);
        strcpy(modelo, m);
        status = s;
    };

    char getPlaca() {return *placa;}
    char getModelo() {return *modelo;}
    bool getStatus() {return status;}

    void setStatus(bool s) {status = s;}
    void setPlaca(char p) {placa = p[]; }
    void setModelo (char m) {modelo = m[];}
};

#endif //VEICULO_H
