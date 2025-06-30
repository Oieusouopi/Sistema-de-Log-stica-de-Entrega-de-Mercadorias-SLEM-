//
// Created by eec on 18/06/25.
//

#ifndef LOCAL_H
#define LOCAL_H

#include <iostream>
#include <string>

class Local {
private:
    int id;
    float cord_x;
    float cord_y;
    std::string endereco;

public:

    Local(std::string endereco) : endereco(endereco) {}

    Local(int id, float x, float y, const std::string& end)
        : id(id), cord_x(x), cord_y(y), endereco(end) {}

    Local(const char* id, int x, int y);

    // Setters
    void setX(float x) { cord_x = x; }
    void setY(float y) { cord_y = y; }
    void setEndereco(std::string end) { this->endereco = end; }

    // Getters
    float getX() const { return cord_x; }
    float getY() const { return cord_y; }
    std::string getEndereco() const { return endereco; }
    int getId() const { return id; }


    void mostrar() const {
        std::cout << "ID: " << id
                  << "\nEndereço: " << endereco
                  << "\nCoordenadas: (" << cord_x << ", " << cord_y << ")\n";
    }
};

#endif // LOCAL_H
