//
// Created by eec on 28/06/25.
//

#include "../Model/Local.h"
#include "LocalUtils.h"

#include "../Service/LocalService.h"
#include "limits"

Local LocalUtils::selecionarLocal(LocalService& localService) {
    const std::vector<Local> locais = localService.listar();

    return selecionarLocal(locais);
}

Local LocalUtils::selecionarLocal(const std::vector<Local> locaisDisponiveis) {
    if (locaisDisponiveis.empty()) {
        std::cout << "Nenhum local cadastrado.\n";
        return Local("Não definido");
    }

    std::cout << "Selecione um local:\n";
    for (size_t i = 0; i < locaisDisponiveis.size(); ++i) {
        std::cout << (i + 1) << " - " << locaisDisponiveis[i].getEndereco() << "\n";
    }

    int opcao = 0;
    while (true) {
        std::cout << "Digite o número da opção: ";
        std::cin >> opcao;

        if (std::cin.fail() || opcao < 1 || static_cast<size_t>(opcao) > locaisDisponiveis.size()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Opção inválida. Tente novamente.\n";
        } else {
            break;
        }
    }

    return locaisDisponiveis[opcao - 1];
}
