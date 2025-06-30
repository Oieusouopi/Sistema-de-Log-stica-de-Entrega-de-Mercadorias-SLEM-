
#include <iostream>

#include "App.h"
// #include <windows.h>


// void menuBanco(); // Tenho que pensar onde vou colocar esse menu



int main() {
    // SetConsoleOutputCP(CP_UTF8);
    App app;
    app.executar();
    return 0;
}

// void menuBanco() {
//     char teclaGlobal = '\0';
//     std::string entrada;
//
//     while (true) {
//
//         std::cout << "\n----- MENU BANCO -----\n";
//         std::cout << static_cast<char>(SALVAR_TODOS_DADOS) << " -  Salvar todos dados\n";
//         std::cout << static_cast<char>(RESTAURAR_DADOS_DE_BACKUPS_ANTIGOS) << " -  Restaurar dados de backups antigos\n";
//         std::cout << static_cast<char>(VOLTAR_PARA_O_MENU_PRINCIPAL_BANCO) << " -  Voltar para o menu principal\n";
//         std::cout << "-----------------------------\n";
//
//         std::cin >> entrada;
//
//         if (entrada.length() != 1) {
//             ExibirMensagem::exibirMensagemDeErro();
//             continue;
//         }
//
//         teclaGlobal = entrada[0];
//
//         switch (teclaGlobal) {
//             case SALVAR_TODOS_DADOS:
//                 break;
//             case RESTAURAR_DADOS_DE_BACKUPS_ANTIGOS:
//                 break;
//             case VOLTAR_PARA_O_MENU_PRINCIPAL_BANCO:
//                 return;
//             default:
//                 ExibirMensagem::exibirMensagemDeErro();
//                 break;
//         }
//
//     }
// }

