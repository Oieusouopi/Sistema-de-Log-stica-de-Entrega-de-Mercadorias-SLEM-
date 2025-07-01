//
// Created by eec on 30/06/25.
//

#ifndef PEDIDOREPOSITORY_H
#define PEDIDOREPOSITORY_H

class PedidoRepository {
public:
    static int proximoId;
    void salvarTodos(char caminho[]);
    void salvarNoBanco();
    std::vector<Local> listar();
    Local buscarPorId(int id);
    void excluir(int id);
    bool salvarOuAtualizar(Local local);
    int gerarNovoId();
private:
    static std::vector<Pedido> pedidos;
};

#endif //PEDIDOREPOSITORY_H
