#include <iostream>

#include "sensor_nivel.hpp"

int main() {
    SensorNivel sensor{"LT-101", 42.5, "%"};

    std::cout << sensor.resumo() << '\n';

    sensor.ativar();
    bool aceita = sensor.registrarLeitura(55.0);

    std::cout << "Leitura aceita: " << (aceita ? "true" : "false") << '\n';
    std::cout << sensor.resumo() << '\n';

    return 0;
}