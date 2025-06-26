cmake_minimum_required(VERSION 3.31)
project(Sistema_de_Logistica_de_Entrega_de_Mercadorias)

set(CMAKE_CXX_STANDARD 26)

add_executable(Sistema_de_Logistica_de_Entrega_de_Mercadorias src/main.cpp
        src/Model/Pedido.h
        src/Model/Local.h
        src/Model/Veiculo.h
        src/Service/PedidoService.cpp
        src/Service/LocalService.cpp
        src/Service/VeiculoService.cpp
        src/Controller/PedidoController.cpp
        src/Controller/LocalController.cpp
        src/Controller/VeiculoController.cpp
        src/Controller/RotaController.cpp
        src/Service/RotaService.cpp
        src/Utils/EnumMenu.h
        src/Test/Controller/LocalControllerTest.cpp
        src/Test/Controller/PedidoControllerTest.cpp
        src/Test/Controller/VeiculoControllerTest.cpp
        src/Test/Service/LocalServiceTest.cpp
        src/Test/Service/PedidoServiceTest.cpp
        src/Test/Service/VeiculoServiceTest.cpp
        src/Controller/LocalController.h
        src/Controller/PedidoController.h
        src/Controller/RotaController.h
        src/Controller/VeiculoController.h
        src/Service/LocalService.h
        src/Service/PedidoService.h
        src/Service/RotaService.h
        src/Service/VeiculoService.h
        src/App.cpp
        src/App.h
        src/Utils/ExibirMensagem.cpp
        src/Utils/ExibirMensagem.h
        src/Utils/EnumUtils.h)
