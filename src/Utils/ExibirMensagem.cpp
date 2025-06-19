//
// Created by eec on 19/06/25.
//

#include "ExibirMensagem.h"

#include <iostream>
#include <bits/ostream.tcc>

void ExibirMensagem::exibirMensagemDeErro() {

        std::string linha(30, '-');

        std::cout << linha << std::endl;
        std::cout << std::string(5, ' ') << "Essa tecla não existe" << std::endl;
        std::cout << linha << std::endl;

}

void ExibirMensagem::exibirBoasVindas() {
        std::string linha(100, '-'); // Linha com 100 hifens

        std::cout << linha << std::endl;
        std::cout << std::string(20, ' ') << "BEM-VINDO AO SISTEMA DE LOGÍSTICA DE ENTREGA DE MERCADORIAS" << std::endl;
        std::cout << linha << std::endl;
        std::cout << std::endl;
        std::cout << "Aqui o usuário (gerente) consegue gerenciar seus pedidos, veículos, locais do seu sistema\n";
        std::cout << "e trazer mais confiança para o seu cliente!" << std::endl;
        std::cout << "Para começar, vamos para a área de MENU." << std::endl;
        std::cout << std::endl;
}

void ExibirMensagem::exibirDespedida() {
        std::string linha(100, '-');

        std::cout << linha << std::endl;
        std::cout << std::string(30, ' ') << "OBRIGADO POR UTILIZAR NOSSO SISTEMA!" << std::endl;
        std::cout << linha << std::endl;
        std::cout << std::endl;
        std::cout << "Esperamos ter ajudado no gerenciamento de suas entregas.\n";
        std::cout << "Volte sempre que precisar. Até a próxima!" << std::endl;
        std::cout << std::endl;
}

