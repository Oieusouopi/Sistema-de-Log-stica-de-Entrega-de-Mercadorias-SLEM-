//
// Created by eec on 19/06/25.
//

#ifndef VEICULOSERVICE_H
#define VEICULOSERVICE_H

class VeiculoService {

    public:
        static void criar();
        static void listar();
        static void excluir(std::string placa);
        static void updateStatus(std::string placa, bool status);
        static void updateLocalAtual(std::string placa, Local local);

};

#endif //VEICULOSERVICE_H
