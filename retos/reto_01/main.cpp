/*
 * Instrucciones de Compilación:
 *
 * Para compilar este programa, utiliza el siguiente comando:
 *
 *     g++ vehiculo.cpp coche.cpp camion.cpp autobus.cpp moto.cpp main.cpp -o herencia
 *
 * O si prefieres usar la opción de estándar C++17:
 *
 *    g++ -std=c++17 vehiculo.cpp coche.cpp Camion.cpp Autobus.cpp moto.cpp main.cpp -o herencia
 *
 * Para ejecutar el programa:
 *
 *     ./herencia
 */

#include <iostream>
#include <string>
#include "vehiculo.h"
#include "coche.h"
#include "Camion.h"
#include "Autobus.h"
#include "moto.h"

int main() {
    std::cout << "=== Ejemplo de herencia: Vehiculo y derivados ===" << std::endl;
    std::cout << std::endl;

    // Vehiculo base (marca, modelo, anio, tipoLicencia, placas)
    Vehiculo veh1("Ford", "F-150", 2019, "C", "ABC-123");
    std::cout << "Vehiculo base:" << std::endl;
    veh1.mostrarInformacion();
    std::cout << std::endl;

    // Coche
    Coche coche1("Toyota", "Corolla", 2022, "A", "TOY-001", 1800, 4, 2);
    std::cout << "Coche 1:" << std::endl;
    coche1.mostrarInformacion();
    std::cout << std::endl;

    // Camion
    Camion camion1("Volvo", "FH16", 2020, "B", "VOL-999", 4500, 4, 2);
    std::cout << "Camion 1:" << std::endl;
    camion1.mostrarInformacion();
    std::cout << std::endl;

    // Autobus
    Autobus bus1("Mercedes", "Sprinter", 2018, "C", "BUS-555", 2200, 3, 4);
    std::cout << "Autobus 1:" << std::endl;
    bus1.mostrarInformacion();
    std::cout << std::endl;

    // MOTO - CORREGIDO: Conversión explícita a std::string
    Moto moto1("Honda", "CBR", 2021, "A", "MOT-777", 1000, 2);
    
    std::cout << "Moto 1:" << std::endl;
    moto1.mostrarInformacion();
    std::cout << std::endl;

    // Actualizar valores heredados
    std::cout << "Actualizando placa y anio del autobus..." << std::endl;
    bus1.actualizarPlacas("BUS-556");
    bus1.actualizarAnio(2019);
    bus1.mostrarInformacion();
    std::cout << std::endl;

    std::cout << "Cambiando numero de puertas del coche..." << std::endl;
    coche1.actualizarNumeroPuertas(2);
    coche1.mostrarInformacion();
    std::cout << std::endl;

    return 0;
}