/*
 * Instrucciones de Compilación:
 *
 * Para compilar este programa, utiliza el siguiente comando:
 *
 *     g++ vehiculo.cpp coche.cpp main.cpp -o herencia
 *
 * O si prefieres usar la opción de estándar C++17:
 *
 *     g++ -std=c++17 vehiculo.cpp coche.cpp main.cpp -o herencia
 *
 * Para ejecutar el programa:
 *
 *     ./herencia
 */

#include <iostream>
#include "vehiculo.h"
#include "coche.h"
#include "Camion.h"
#include "Autobus.h"
#include "moto.h"

int main() {
    std::cout << "=== Ejemplo de herencia: Vehiculo y derivados ===" << std::endl;
    std::cout << std::endl;

    // base con parámetros completos (marca, modelo, año, licencia, placas)
    Vehiculo veh1("Ford", "F-150", 2019, "C", "ABC-123");
    std::cout << "Vehículo base:" << std::endl;
    veh1.mostrarInformacion();
    std::cout << std::endl;

    // Coche concreto
    Coche coche1("Toyota", "Corolla", "TOY-001", 2022, 1800, 2, 4);
    std::cout << "Coche 1:" << std::endl;
    coche1.mostrarInformacion();
    std::cout << std::endl;

    // Camión concreto
    Camion camion1("Volvo", "FH16", "VOL-999", 2020, 4500, 4, 2);
    std::cout << "Camión 1:" << std::endl;
    camion1.mostrarInformacion();
    std::cout << std::endl;

    // Autobús concreto
    Autobus bus1("Mercedes", "Sprinter", "BUS-555", 2018, 2200, 3, 50);
    std::cout << "Autobús 1:" << std::endl;
    bus1.mostrarInformacion();
    std::cout << std::endl;

    // Moto concreta
    Moto moto1("Honda", "CBR", "MOT-777", 2021, 1000, 2);
    std::cout << "Moto 1:" << std::endl;
    moto1.mostrarInformacion();
    std::cout << std::endl;

    // Actualizar algunos valores
    std::cout << "Actualizando placa y año del autobús..." << std::endl;
    bus1.actualizarPlacas("BUS-556");
    bus1.actualizarAnio(2019);
    bus1.mostrarInformacion();
    std::cout << std::endl;

    std::cout << "Cambiando número de puertas del coche..." << std::endl;
    coche1.actualizarNumeroPuertas(2);
    coche1.mostrarInformacion();
    std::cout << std::endl;

    return 0;
}
