//
// Created by eec on 18/06/25.
//

#ifndef LOCAL_H
#define LOCAL_H

#include <iostream>
#include <cstring>

class Local {
private:
    int id;
    float cord_x;
    float cord_y;
    char endereco[100];

public:
    Local(): id(-1) {}

    Local(const char* endereco) {
        strncpy(this->endereco, endereco, sizeof(this->endereco) - 1);
        this->endereco[sizeof(this->endereco) - 1] = '\0';
    }

    Local(float x, float y, const char* end)
        : cord_x(x), cord_y(y) {
        strncpy(this->endereco, end, sizeof(this->endereco) - 1);
        this->endereco[sizeof(this->endereco) - 1] = '\0';
    }

    void setId(int id) { this->id = id; }
    void setX(float x) { cord_x = x; }
    void setY(float y) { cord_y = y; }

    void setEndereco(const char* end) {
        strncpy(this->endereco, end, sizeof(this->endereco) - 1);
        this->endereco[sizeof(this->endereco) - 1] = '\0';
    }

    int getId() const { return id; }
    float getX() const { return cord_x; }
    float getY() const { return cord_y; }

    const char* getEndereco() const { return endereco; }

    void mostrar() const {
        std::cout << "ID: " << id
                  << "\nEndereço: " << endereco
                  << "\nCoordenadas: (" << cord_x << ", " << cord_y << ")\n";
    }
};

#endif // LOCAL_H
