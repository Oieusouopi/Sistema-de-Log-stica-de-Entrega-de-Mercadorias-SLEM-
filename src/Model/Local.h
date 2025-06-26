//
// Created by eec on 18/06/25.
//

#ifndef LOCAL_H
#define LOCAL_H
#include <iostream>
#include <string.h>

class Local {
private:
    float cord_x;
    float cord_y;
    std::string endereco;

public:
    Local(std::string endereco): endereco(endereco) {}

    Local(float x, float y, const std::string end): cord_x(x), cord_y(y), endereco(end) {}

    void setX(float x) { cord_x = x; }
    void setY(float y) { cord_y = y; }
    void setEndereco(std::string end) { this->endereco = end; }


    float getX() const { return cord_x; }
    float getY() const { return cord_y; }
    std::string getEndereco() const { return endereco; }

    void mostrar() const {
        std::cout << "Endereço: " << endereco
                  << "\nCoordenadas: (" << cord_x << ", " << cord_y << ")\n";
    }
};

#endif //LOCAL_H
