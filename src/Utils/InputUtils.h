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

        if (entrada == "0") {
            return false;
        }

        std::stringstream ss(entrada);
        if (ss >> resultado && ss.eof()) {
            return true;
        }

        std::cout << "Entrada inválida. Por favor, digite um número válido.\n";
    }
}

inline bool lerStringComTamanhoExato(const std::string& prompt, std::string& resultado, int tamanhoExato) {
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, resultado);

        if (resultado == "0") {
            return false;
        }

        if ((int)resultado.size() == tamanhoExato) {
            return true;
        }

        std::cout << "Entrada inválida. Digite exatamente " << tamanhoExato << " caracteres.\n";
    }
}

inline bool lerStringComTamanhoMaximo(const std::string& prompt, std::string& resultado, int tamanhoMaximo) {
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, resultado);

        if (resultado == "0") {
            return false;
        }

        if (!resultado.empty() && (int)resultado.size() <= tamanhoMaximo) {
            return true;
        }

        std::cout << "Entrada inválida. Digite até " << tamanhoMaximo << " caracteres (e não deixe vazio).\n";
    }
}

#endif //INPUTUTILS_H
