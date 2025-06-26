
#include <iostream>

#include "App.h"
#include "Controller/VeiculoController.h"
#include "Service/VeiculoService.h"
#include <windows.h>

// void menuBanco(); // Tenho que pensar onde vou colocar esse menu



int main() {
    SetConsoleOutputCP(CP_UTF8);
    App app;
    app.executar();
    return 0;
}

