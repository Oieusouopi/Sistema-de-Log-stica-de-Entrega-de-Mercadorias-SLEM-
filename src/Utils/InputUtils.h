//
// Created by rafas on 03/07/2025.
//

#ifndef INPUTUTILS_H
#define INPUTUTILS_H

#include <iostream>
#include <string>
#include <sstream>

inline bool lerFloat(const std::string& prompt, float& resultado) {
    std::string entrada;
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, entrada);

        std::stringstream ss(entrada);
        if (ss >> resultado && ss.eof()) {
            return true;
        }

        std::cout << "Entrada inválida. Por favor, digite um número válido.\n";
    }
}

#endif //INPUTUTILS_H
