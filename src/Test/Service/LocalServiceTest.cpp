//
// Created by eec on 18/06/25.
//

#include "../../Service/LocalService.h"
#include "../../Model/Local.h"
#include <iostream>
#include <cassert>

void silenciarCout() {
    std::cout.setstate(std::ios_base::failbit);
}

void restaurarCout() {
    std::cout.clear();
}

void testarCriacaoLocal() {
    std::cout << "Executando teste: Criação de Local...\n";
    
    LocalService localService;
    Local local(1, 10.0f, 20.0f, "Rua das Flores, 123");
    
    silenciarCout();
    localService.criar(local);
    restaurarCout();
    
    std::vector<Local> locais = localService.listar();
    assert(locais.size() == 1);
    assert(locais[0].getId() == 1);
    assert(locais[0].getEndereco() == "Rua das Flores, 123");
    assert(locais[0].getX() == 10.0f);
    assert(locais[0].getY() == 20.0f);
    
    std::cout << "✓ Teste de criação de local passou!\n";
}

void testarListagemLocais() {
    std::cout << "Executando teste: Listagem de Locais...\n";
    
    LocalService localService;
    Local local1(1, 10.0f, 20.0f, "Rua A");
    Local local2(2, 30.0f, 40.0f, "Rua B");
    
    silenciarCout();
    localService.criar(local1);
    localService.criar(local2);
    restaurarCout();
    
    std::vector<Local> locais = localService.listar();
    assert(locais.size() == 2);
    assert(locais[0].getEndereco() == "Rua A");
    assert(locais[1].getEndereco() == "Rua B");
    
    std::cout << "✓ Teste de listagem de locais passou!\n";
}

void testarExisteId() {
    std::cout << "Executando teste: Verificação de ID existente...\n";
    
    LocalService localService;
    Local local(5, 10.0f, 20.0f, "Rua do Teste");
    
    silenciarCout();
    localService.criar(local);
    restaurarCout();
    
    assert(localService.existeId(5) == true);
    assert(localService.existeId(10) == false);
    
    std::cout << "✓ Teste de verificação de ID passou!\n";
}

void testarBuscarPorId() {
    std::cout << "Executando teste: Busca por ID...\n";
    
    LocalService localService;
    Local local(7, 15.0f, 25.0f, "Avenida Central");
    
    silenciarCout();
    localService.criar(local);
    restaurarCout();
    
    Local* localEncontrado = localService.buscarPorId(7);
    assert(localEncontrado != nullptr);
    assert(localEncontrado->getId() == 7);
    assert(localEncontrado->getEndereco() == "Avenida Central");
    
    Local* localNaoEncontrado = localService.buscarPorId(99);
    assert(localNaoEncontrado == nullptr);
    
    std::cout << "✓ Teste de busca por ID passou!\n";
}

void testarExclusaoPorId() {
    std::cout << "Executando teste: Exclusão por ID...\n";
    
    LocalService localService;
    Local local1(1, 10.0f, 20.0f, "Local 1");
    Local local2(2, 30.0f, 40.0f, "Local 2");
    
    silenciarCout();
    localService.criar(local1);
    localService.criar(local2);
    restaurarCout();
    
    assert(localService.listar().size() == 2);
    
    localService.excluirPorId(1);
    
    std::vector<Local> locais = localService.listar();
    assert(locais.size() == 1);
    assert(locais[0].getId() == 2);
    assert(localService.existeId(1) == false);
    assert(localService.existeId(2) == true);
    
    std::cout << "✓ Teste de exclusão por ID passou!\n";
}

void testarGerarNovoId() {
    std::cout << "Executando teste: Geração de novo ID...\n";
    
    LocalService localService;
    
    int novoId1 = localService.gerarNovoId();
    assert(novoId1 == 1);
    
    Local local1(3, 10.0f, 20.0f, "Local A");
    Local local2(7, 30.0f, 40.0f, "Local B");
    
    silenciarCout();
    localService.criar(local1);
    localService.criar(local2);
    restaurarCout();
    
    int novoId2 = localService.gerarNovoId();
    assert(novoId2 == 8); // 7 + 1
    
    std::cout << "✓ Teste de geração de novo ID passou!\n";
}

void testarExisteEndereco() {
    std::cout << "Executando teste: Verificação de endereço existente...\n";
    
    LocalService localService;
    Local local(1, 10.0f, 20.0f, "Rua Única");
    
    silenciarCout();
    localService.criar(local);
    restaurarCout();
    
    assert(localService.existeEndereco("Rua Única") == true);
    assert(localService.existeEndereco("Rua Inexistente") == false);
    
    std::cout << "✓ Teste de verificação de endereço passou!\n";
}

void testarAtualizarEndereco() {
    std::cout << "Executando teste: Atualização de endereço...\n";
    
    LocalService localService;
    Local local(10, 50.0f, 60.0f, "Endereço Original");
    
    silenciarCout();
    localService.criar(local);
    
    bool resultado1 = localService.atualizarEnderecoPorId(10, "Endereço Atualizado");
    restaurarCout();
    
    assert(resultado1 == true);
    
    Local* localAtualizado = localService.buscarPorId(10);
    assert(localAtualizado != nullptr);
    assert(localAtualizado->getEndereco() == "Endereço Atualizado");
    
    silenciarCout();
    bool resultado2 = localService.atualizarEnderecoPorId(99, "Endereço Novo");
    restaurarCout();
    
    assert(resultado2 == false);
    
    std::cout << "✓ Teste de atualização de endereço passou!\n";
}

void executarTodosOsTestes() {
    std::cout << "\n========== TESTES DO LOCAL SERVICE ==========\n";
    
    testarCriacaoLocal();
    testarListagemLocais();
    testarExisteId();
    testarBuscarPorId();
    testarExclusaoPorId();
    testarGerarNovoId();
    testarExisteEndereco();
    testarAtualizarEndereco();
    
    std::cout << "\n✅ TODOS OS TESTES PASSARAM COM SUCESSO!\n";
    std::cout << "=============================================\n";
}

int main() {
    try {
        executarTodosOsTestes();
        return 0;
    } catch (const std::exception& e) {
        std::cout << "❌ Erro durante execução dos testes: " << e.what() << std::endl;
        return 1;
    }
}
