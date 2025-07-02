//
// Created by rafas on 02/07/2025.
//

#ifndef BANCOSERVICE_H
#define BANCOSERVICE_H
#include "../Repository/LocalRepository.h"
#include "../Repository/PedidoRepository.h"
#include "../Repository/VeiculoRepository.h"

class BancoService {

public:
    BancoService(PedidoRepository &pedidoRespository, LocalRepository &localRepository, VeiculoRepository &veiculoRepository);
    void salvarBackup();
    void restaurarBackup();
private:
    PedidoRepository &pedidoRepository;
    LocalRepository &localRepository;
    VeiculoRepository &veiculoRepository;
};
#endif //BANCOSERVICE_H
